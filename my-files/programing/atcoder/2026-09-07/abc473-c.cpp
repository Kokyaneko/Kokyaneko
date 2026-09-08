/*
<方針>
    0. クラスごとの人数算出
    1. 人数が最も多いクラスと高橋くんの入るクラスとの比較を行う。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n,0);
    vector<int> cou(k,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cou[a[i]]++;
    }

    int total = 0;
    auto maxn = max_element(cou.begin(),cou.end());
    for(int i=0;i<k;+i++){
        if(cou[i+1] + 1 >= *maxn) total++;
    }

    cout<<total<<endl;

    return 0;
}
