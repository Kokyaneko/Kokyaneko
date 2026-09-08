/*
<方針>
    std::reverse関数を用いて、l-r間の数を反転させる
*/

#include <iostream>
#include <vector>
#include <algorithm>//for std::reverce

using namespace std;

int main(){
    int n,l,r;
    cin>>n>>l>>r;

    n++;

    vector<int> a(n,0);
    for(int i=1;i<n;i++){
        a[i] = i;
    }

    reverse(a.begin()+l , a.begin()+r+1);

    for(int i=1;i<n;i++){
        cout<<a[i]<<' ';
    }

    return 0;
}
