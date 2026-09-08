/*
<方針>
	入力された文字列をtoupperで大文字化する
	(toupperは位置文字ごとしか対応していないので注意)
*/
#include <iostream>
#include <cctype>

using namespace std;

int main(){
  char s[101];
  cin>>s;
 
  char S[101];
  for(int i=0;i<101;i++){
    S[i] = toupper(s[i]);
  }
 
  cout<<S<<endl;
 
  return 0;
}