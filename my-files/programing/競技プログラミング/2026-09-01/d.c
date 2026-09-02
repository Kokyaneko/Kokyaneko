/*
<方針>
  入力された値nはYesを出力するとき、2^a*3^b(a,bは任意の実数)の積の形で表せる。
  よって、2,3で割り続け、その結果が1になるのならばYesを出力する。
*/

#include <iostream>

using namespace std;

int main (){
  long long n;
  cin>>n;
 
  long long a = n;
  while(810!=114514){
    if(a%2 == 0) a/=2;
    else break;
  }
 
  while(810!=114514){   
    if(a%3 == 0) a/=3;
    else break;
  }
 
  if(a==1){
    cout<<"Yes"<<endl;
    return 0;
  }
  
  cout<<"No"<<endl;

  return 0;
}