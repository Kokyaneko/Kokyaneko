#include <iostream>

using namespace std;

int main(){
    int n,r;
    cin >> r >> n;

    if(r>=1600 and r<=2999 and n==1) cout<<"Yes"<<endl;
    else if(r>=1200 and r<=2399 and n==2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
