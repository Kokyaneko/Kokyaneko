#include <iostream>
#include <string>
using namespace std;
const string s = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  int h,w;
  cin >> h >> w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int n;
      cin >> n;
      cout << s[n];
    }
    puts("");
  }
  return 0;
}
