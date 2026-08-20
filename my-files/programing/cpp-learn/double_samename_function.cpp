/*
C言語と異なり、C++では、同じ名前で関数を定義する、「多重定義」が可能。
ただし、引数の個数などで区別できるようにしなければならない。
*/

#include <iostream>
#include <cstdio>

using namespace std;

int max(int a,int b){
    if(a >= b) return a;
    if(a < b) return b;

    return 0;
}

int max(int a,int b,int c){
    int r = a;
    if(b>=r) r = b;
    if(c>=r) r = c;

    return r;
}

int main(void){
    int n;
    cout<<"Input numbers of data(2 or 3)\n";
    cin>>n;

    if(!(n == 2 or n == 3)){
        return 1;
    }

    int d[n];
    cout<<"Input "<< n <<" datas\n";
    for(int i=0;i<n;i++){
        cin>>d[i];
    }

    int r=0;
    if(n == 2) r = max(d[0],d[1]);
    if(n == 3) r = max(d[0],d[1],d[2]);

    cout<<"Max number is "<< r <<'.'<<endl;

    return 0;
}
