/*
入力例解釈
  3 <- 人数
  1 2 <-送る人数 送り先
  1 2 <-送る人数 送り先
  3 1 2 3 <-送る人数 送り先

<方針>
   0. a[プレゼント宛先][プレゼント送り主] の配列を用意.
   1. 入力に基づいて,配列に挿入. (プレゼントがないなら初期値0.)
   2. もしプレゼントがある(=a[i][j]が0でない)ならば,
   	- その人のトータル値にプラスする.
     - 送り主を表示する

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  
  vector<vector<int>> a(n,vector(n,0));
  for(int i=0;i<n;i++){
    int to_num;
    cin>>to_num;
    
    for(int j=0;j<to_num;j++){
      int to;
      cin>>to;
      a[to-1][i]++;
    }
  }
  
  for(int i=0;i<n;i++){
    int total=0;
    for(int j=0;j<n;j++){
      total += a[i][j];
    }
    cout<<total<<' ';
    
    for(int j=0;j<n;j++){
      if(a[i][j] == 1) cout<<j+1<<' ';
    }
    puts("");
  }
 
  return 0;
}