/*
<方針>
  n^n 1<n<20について計算する
  その値が入力値と等しいならばnを、等しくないならば-1を返す

  std::powはオーバーフローしやすいため、自分で累乗を求める
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n;
    cin>>n;

    int re = -1;
    for(int i=1;i<20;i++){
        long long nijo=1;
        for(int j=1;j<=i;j++){
            nijo *=i;
        }
        if(nijo == n) re = i;
    }

    cout<<re<<endl;

    return 0;
}
