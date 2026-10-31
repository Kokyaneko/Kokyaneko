#include <iostream>
#include <string>
#include <map>
using namespace std;
const string abc = "abcdefghijklmnopqrstuvwxyz";
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  s += '.';
  map<char,int> cou;
  int back=-1;
  for(int i=0;i<n;i++){
    int sa=0;
    if(s[i] != s[i+1]){
      sa = i-back;
      back = i;
    }
    if(sa > cou[s[i]]) cou[s[i]] = sa;
  }
  int total=0;
  for(int i=0;i<26;i++){
    total += cou[abc[i]];
  }
  cout << total << endl;
  return 0;
}
