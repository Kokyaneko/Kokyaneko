/*
<方針>
  n*n + 2*n + 3を計算する関数を実行する
*/

#include <iostream>

using namespace std;

long long func(long long n){
  long long res = n*n + 2*n + 3;
  return res;
}

int main(){
  long long n;
  cin>>n;
  
  long long res1 = func(func(n) + n);
  long long res2 = func(func(n));
  long long res3 = func(res1+res2);
  
  cout<<res3<<endl;
  return 0;
}