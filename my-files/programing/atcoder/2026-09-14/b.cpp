/*
<方針>
入力された数字の10の位がグループで許された番号と異なるならNoを出力する
*/

#include <iostream>
#include <vector>

using namespace std;

int main (){
  int n;
  cin >> n;
  
  vector<int> a(n,0);
  
  for(int i=0;i<n;i++){
    cin >> a[i];
    
    if(!(a[i] > i/10*10 and a[i] < (i/10+1)*10 + 1)){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
 
  return 0;
}
