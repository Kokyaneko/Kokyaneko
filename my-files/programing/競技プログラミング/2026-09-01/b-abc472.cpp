/*
<方針>
    0. 棒を折った場所までの前後の長さの差を出す (その値が負ならば、-1をかける,絶対値変換)
    1. その和を折った場所ごとに算出し、配列に格納する
    2. 配列の中で、最小の絶対値を表示する
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int b[n-1];
    for(int i=1;i<n;i++){
        int pl=0,fl=0;

        for(int j=0;j<i;j++){
            pl += a[j];
        }

        for(int j=i;j<n;j++){
            fl += a[j];
        }

        int res = pl - fl;
        if(res<0) res = res*(-1);
        b[i-1] = res;
    }

    int minimum=100001;
    for(int i=0;i<n-1;i++){
        if(minimum>b[i]) minimum = b[i];
    }

    printf("%d\n",minimum);

    return 0;
}
