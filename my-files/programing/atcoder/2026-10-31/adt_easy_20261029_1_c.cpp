#include <iostream>
#include <string>
using namespace std;
int main(){
  string s,l;
  cin >> l >> s;
  bool ok = true;
  for(int i=0;i<int(l.size());i++){
    if(s[i] != l[i]) ok = false;
  }
  if(ok==false) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
