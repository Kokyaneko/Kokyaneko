/*
std::listを用いて並べ替えを実装
std::remove実行が原因でTLEが起きる
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main (){
  int n,q;
  cin >> n >> q;
  
  list<int> a;
  for(int i=0;i<n;i++){
    int inp;
    cin >> inp;
    
    a.push_back(inp);
  }
  
  list<int> inp(q,0);
  for(int i=0;i<q;i++){
    int inpn;
    cin >> inpn;
    
    if(inp.begin() != inp.end()) inp.remove(inpn);
    inp.push_back(inpn);
  }
 
  for(auto it = inp.begin();it != inp.end() ;++it){
    if(a.begin() != a.end()) a.remove(*it);
    a.push_back(*it);
  }
  
  a.remove(0);
  
  for(auto it = a.begin();it != a.end();++it){
    cout << *it << ' ';
  }

  puts("");
 
  return 0;
}
