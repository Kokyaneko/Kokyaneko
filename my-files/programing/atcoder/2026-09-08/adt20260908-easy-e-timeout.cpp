/*
  各クエリに対して、配列の値を加工・表示する
  クエリ2のとき、1回の動作で30万回計算が行われるためタイムアウト
*/

#include <iostream>

using namespace std;

int main(){
  int q;
  cin>>q;
 
  int hebi[300000]; 
  long long last=0;
  for(int i=0;i<q;i++){
    int q1;
    cin>>q1;
    if(q1 == 1){
      int q2;
      cin>>q2;
       
      hebi[last] = q2;
      last++;
    }
    
    if(q1 == 2){
      for(int j=0;j<last;j++){
        hebi[j] = hebi[j+1];
      }
      last--;
    }
    if(q1 == 3){
      int q2;
      cin >> q2;
      
      long long total=0;
      for(int j=0;j<q2-1;j++){
        total+=hebi[j];
      }
        cout<<total<<endl;
    }
  }
 
  return 0;
}