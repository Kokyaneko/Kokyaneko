/*
<方針>
i点から他の点までの距離がD以下であればokとする.
i点から正の方向に距離がD未満の点を弾く.

解説より: abs関数なら絶対値で確かめることができる.(1点から正の方向/負の方向どちらにも計算対応できる.)
*/

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,d;
    cin >> n >> d;

    vector<int> a(n,0);
    vector<int> ok(n,0);
    int count=0;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j) if(a[j] >=a[i] and a[j] < a[i]+d) {ok[i]+=1; ok[j]+=1;}
        }
    }

    for(int i=0;i<n;i++) if(ok[i] == 0) count++;
    cout<< count << endl;

    for(int i=0;i<n;i++) if(ok[i] == 0) cout << i+1 << " ";
    puts("");

    return 0;
}
