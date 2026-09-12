#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a(32,0);
    for(int i=0;i<32;i++){
        cin>>a[i];
    }

    vector<int> b(16,0);
    for(int i=0;i<32-1;i+=2){
        if(a[i] < a[i+1]) a[i+1] = b[i/2];
        if(a[i] > a[i+1]) a[i] = b[i/2];
    }
    vector<int> c(8,0);
    for(int i=0;i<16-1;i+=2){
        cout<<a[i]<<a[i+1];
        if(b[i] < b[i+1]) b[i+1] = c[i/2];
        if(b[i] > b[i+1]) b[i] = c[i/2];
    }
    vector<int> d(4,0);
    for(int i=0;i<8-1;i+=2){
        if(c[i] < c[i+1]) c[i+1] = d[i/2];
        if(c[i] > c[i+1]) c[i] = d[i/2];
    }
    vector<int> e(2,0);
    for(int i=0;i<4-1;i+=2){
        if(d[i] < d[i+1]) d[i+1] = e[i/2];
        if(d[i] > d[i+1]) d[i] = e[i/2];
    }

    if(e[0]>e[1]) cout<<e[1];
    if(e[0]<e[1]) cout<<e[0];

    return 0;
}
