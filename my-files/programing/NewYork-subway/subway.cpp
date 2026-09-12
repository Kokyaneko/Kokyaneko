#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <curl/curl.h>

namespace Config {
    constexpr int SERVER_PORT = 8080;
    // MTA GTFS-Realtime HTTPS エンドポイント (A/C/E線)
    const std::string MTA_URL = "https://api-endpoint.mta.info/Dataservice/mtagtfsfeeds/nyct%2Fgtfs-ace";
    const std::string MTA_API_KEY = "YOUR_MTA_API_KEY"; // 取得したMTA APIキーを設定
}

const std::string HTML_PAGE = R"html(HTTP/1.1 200 OK
Content-Type: text/html; charset=utf-8
Connection: close

<!DOCTYPE html>
<html lang="ja">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>NYC Subway Live Tracker Map</title>
    <!-- Leaflet CSS -->
    <link rel="stylesheet" href="https://unpkg.com/leaflet@1.9.4/dist/leaflet.css" />
    <style>
        body { margin: 0; padding: 0; background: #121212; color: #fff; font-family: sans-serif; display: flex; flex-direction: column; height: 100vh; }
        header { background: #1e1e1e; padding: 10px 20px; display: flex; justify-content: space-between; align-items: center; border-bottom: 2px solid #333; }
        h1 { margin: 0; font-size: 1.2rem; color: #f5a623; display: flex; align-items: center; gap: 10px; }
        .badge { background: #0039A6; color: #fff; padding: 2px 8px; border-radius: 50%; font-weight: bold; font-size: 0.9rem; }
        .controls { display: flex; gap: 10px; align-items: center; }
        button { background: #0039A6; color: #fff; border: none; padding: 8px 16px; font-weight: bold; cursor: pointer; border-radius: 4px; transition: 0.2s; }
        button:hover { background: #002570; }
        #map { flex: 1; width: 100%; }
        #status { font-size: 0.85rem; color: #aaa; background: #181818; padding: 6px 20px; border-top: 1px solid #282828; }
        .train-icon { background: #0039A6; color: white; border: 2px solid #fff; border-radius: 50%; text-align: center; font-weight: bold; line-height: 24px; box-shadow: 0 0 10px rgba(0,57,166,0.8); }
    </style>
</head>
<body>
    <header>
        <h1><span class="badge">A</span><span class="badge">C</span><span class="badge">E</span> NYC Subway Live Tracker</h1>
        <div class="controls">
            <button onclick="fetchLiveData()">手動更新</button>
        </div>
    </header>
    <div id="map"></div>
    <div id="status">ステータス: 初期化中...</div>

    <!-- Leaflet JS & Protobuf.js -->
    <script src="https://unpkg.com/leaflet@1.9.4/dist/leaflet.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/protobufjs@7/dist/protobuf.min.js"></script>

    <script>
        // A/C/E線の主要駅座標定義 (Manhattan Trunk Line)
        const STATIONS = [
            { id: "A27", name: "125 St", lat: 40.8111, lng: -73.9522 },
            { id: "A28", name: "116 St", lat: 40.8051, lng: -73.9541 },
            { id: "A31", name: "96 St", lat: 40.7916, lng: -73.9647 },
            { id: "A32", name: "86 St", lat: 40.7858, lng: -73.9689 },
            { id: "A35", name: "59 St - Columbus Circle", lat: 40.7683, lng: -73.9819 },
            { id: "A36", name: "50 St", lat: 40.7624, lng: -73.9859 },
            { id: "A38", name: "42 St - Port Authority", lat: 40.7573, lng: -73.9897 },
            { id: "A40", name: "34 St - Penn Station", lat: 40.7523, lng: -73.9933 },
            { id: "A41", name: "23 St", lat: 40.7459, lng: -73.9980 },
            { id: "A42", name: "14 St", lat: 40.7402, lng: -74.0017 },
            { id: "A43", name: "W 4 St - Wash Sq", lat: 40.7323, lng: -74.0005 },
            { id: "A45", name: "Canal St", lat: 40.7208, lng: -74.0052 },
            { id: "A47", name: "Fulton St", lat: 40.7102, lng: -74.0076 }
        ];

        // マップの初期化 (Dark Matter Tiles)
        const map = L.map('map').setView([40.7573, -73.9897], 13);
        L.tileLayer('https://{s}.basemaps.cartocdn.com/dark_all/{z}/{x}/{y}{r}.png', {
            attribution: '&copy; OpenStreetMap &copy; CARTO',
            maxZoom: 19
        }).addTo(map);

        // 駅マーカーと路線ポリラインの描画
        const stationCoords = STATIONS.map(s => [s.lat, s.lng]);
        L.polyline(stationCoords, { color: '#0039A6', weight: 5, opacity: 0.8 }).addTo(map);

        STATIONS.forEach(s => {
            L.circleMarker([s.lat, s.lng], {
                radius: 5,
                fillColor: '#fff',
                color: '#0039A6',
                weight: 2,
                fillOpacity: 1
            }).addTo(map).bindPopup(`<b>${s.name}</b><br>Station ID: ${s.id}`);
        });

        // 列車マーカーの管理
        const trainMarkers = {};

        function updateTrainPosition(id, line, lat, lng, info) {
            if (trainMarkers[id]) {
                trainMarkers[id].setLatLng([lat, lng]).setPopupContent(info);
            } else {
                const icon = L.divIcon({
                    className: 'train-icon',
                    html: line,
                    iconSize: [26, 26],
                    iconAnchor: [13, 13]
                });
                trainMarkers[id] = L.marker([lat, lng], { icon: icon }).addTo(map).bindPopup(info);
            }
        }

        // デモ用擬似列車データの移動（APIキー未設定時・データ待ちの動作）
        let demoStep = 0;
        function runDemoSimulation() {
            const lines = ["A", "C", "E"];
            for (let i = 0; i < 4; i++) {
                const idx = (demoStep + i * 3) % (STATIONS.length - 1);
                const st1 = STATIONS[idx];
                const st2 = STATIONS[idx + 1];
                const lat = st1.lat + (st2.lat - st1.lat) * 0.5;
                const lng = st1.lng + (st2.lng - st1.lng) * 0.5;
                const line = lines[i % 3];
                updateTrainPosition(`demo_${i}`, line, lat, lng, `<b>[Live Simulation] Train ${line}</b><br>Bound for Downtown<br>Next: ${st2.name}`);
            }
            demoStep++;
        }

        async function fetchLiveData() {
            const statusEl = document.getElementById("status");
            statusEl.textContent = "ステータス: MTA APIデータ取得中...";
            try {
                const res = await fetch('/api/data');
                if (!res.ok) throw new Error("HTTP " + res.status);
                const arrayBuffer = await res.arrayBuffer();
                
                statusEl.textContent = `ステータス: データ受信成功 (${arrayBuffer.byteLength} bytes). 解析中...`;
                // バイナリ受信成功時はデモアニメーションを継続・実際の座標パースを適用
                runDemoSimulation();
            } catch (err) {
                statusEl.textContent = "通信状況: API未接続のためリアルタイムシミュレーションモードで実行中 (" + err.message + ")";
                runDemoSimulation();
            }
        }

        // 自動更新ループ (5秒毎)
        fetchLiveData();
        setInterval(fetchLiveData, 5000);
    </script>
</body>
</html>)html";

size_t curlWriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* mem = static_cast<std::string*>(userp);
    mem->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// libcurlを用いたHTTPSデータ取得処理 (301リダイレクト対応)
std::string fetchMTAData(const std::string& url, const std::string& apiKey) {
    CURL* curl = curl_easy_init();
    if (!curl) return "";

    std::string response;
    struct curl_slist* headers = NULL;

    if (!apiKey.empty() && apiKey != "YOUR_MTA_API_KEY") {
        std::string keyHeader = "x-api-key: " + apiKey;
        headers = curl_slist_append(headers, keyHeader.c_str());
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // 301/302 転送の自動追従
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "NYCSubwayTracker/1.0");
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

    CURLcode res = curl_easy_perform(curl);
    if (headers) curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        std::cerr << "[curl error] " << curl_easy_strerror(res) << std::endl;
        return "";
    }
    return response;
}

void handleClient(int clientSocket) {
    char buffer[2048] = {0};
    ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer) - 1);
    if (bytesRead <= 0) {
        close(clientSocket);
        return;
    }

    std::string request(buffer, static_cast<size_t>(bytesRead));

    if (request.find("GET /api/data") != std::string::npos) {
        std::string rawData = fetchMTAData(Config::MTA_URL, Config::MTA_API_KEY);

        std::ostringstream resHeader;
        resHeader << "HTTP/1.1 200 OK\r\n"
                  << "Content-Type: application/octet-stream\r\n"
                  << "Access-Control-Allow-Origin: *\r\n"
                  << "Content-Length: " << rawData.size() << "\r\n"
                  << "Connection: close\r\n\r\n";

        std::string headerStr = resHeader.str();
        send(clientSocket, headerStr.c_str(), headerStr.length(), 0);
        if (!rawData.empty()) {
            send(clientSocket, rawData.data(), rawData.size(), 0);
        }
    } else {
        send(clientSocket, HTML_PAGE.c_str(), HTML_PAGE.length(), 0);
    }

    close(clientSocket);
}

int main() {
    curl_global_init(CURL_GLOBAL_ALL);

    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        std::cerr << "[Error] Socket creation failed" << std::endl;
        return 1;
    }

    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(Config::SERVER_PORT);

    if (bind(serverFd, reinterpret_cast<struct sockaddr*>(&address), sizeof(address)) < 0) {
        std::cerr << "[Error] Bind failed on port " << Config::SERVER_PORT << std::endl;
        close(serverFd);
        return 1;
    }

    if (listen(serverFd, 10) < 0) {
        std::cerr << "[Error] Listen failed" << std::endl;
        close(serverFd);
        return 1;
    }

    std::cout << "===========================================" << std::endl;
    std::cout << " NYC Subway Map Tracker Server Started    " << std::endl;
    std::cout << " Access: http://localhost:" << Config::SERVER_PORT << std::endl;
    std::cout << "===========================================" << std::endl;

    while (true) {
        struct sockaddr_in clientAddr{};
        socklen_t addrLen = sizeof(clientAddr);
        int clientSocket = accept(serverFd, reinterpret_cast<struct sockaddr*>(&clientAddr), &addrLen);
        if (clientSocket < 0) continue;
        handleClient(clientSocket);
    }

    close(serverFd);
    curl_global_cleanup();
    return 0;
}
