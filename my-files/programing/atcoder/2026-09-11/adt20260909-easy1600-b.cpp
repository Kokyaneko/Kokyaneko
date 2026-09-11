/*
<方針>
  文字列を走査して例外の文字以外ならば変換する
*/

#include <iostream>

using namespace std;

int main(){
  int n;
  string o,c;
  cin>>n>>o>>c;
  
  string a;
  cin>>a;
  for(int i=0;i<n;i++){
    if(char(a[i]) != char(o[0])) a[i] = c[0];
    else continue;
  }
  
  for(int i=0;i<n;i++){
    cout<<a[i];
  }
 
  return 0;
}