#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> cand(n);
    vector<int> tokuhyo(n,0);
    vector<string> tohyo(m);
    for(int i=0;i<n;i++){
        cin >> cand[i];
    }
    for(int i=0;i<m;i++){
        cin >> tohyo[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(tohyo[i].size() == cand[j].size()){
                int count=0;
                for(int k=0;k<int(tohyo[i].size());k++){
                    if(tohyo[i][k] == cand[j][k]) count++;
                }
                if(count == int(tohyo.size()) or count == int(tohyo.size())-1) tokuhyo[j]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << tokuhyo[i] << endl;
    }

    return 0;
}
