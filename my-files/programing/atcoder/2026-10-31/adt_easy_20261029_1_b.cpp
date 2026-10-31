#include <iostream>
#include <string>
using namespace std;
const string s = "HelloWorld";
int main(){
  int x;
  cin >> x;
  for(int i=0;i<10;i++){
    if(i == x-1) continue;
    else cout << s[i];
  }
  return 0;
}
