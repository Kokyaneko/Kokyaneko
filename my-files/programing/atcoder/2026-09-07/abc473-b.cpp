/*
<方針>
    入力された値の総和から2数1組の値を引く
    (intに商を入れると切り捨てできる。)
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n,0);
    vector<int> cou(100,0);
    int total = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cou[a[i]]++;
        total += a[i];
    }

    for(int i=0;i<=100;i++){
        int shou = cou[i] / 2;
        total -= shou * 2 * i;
    }
    
    cout<<total<<endl;

    return 0;
}
