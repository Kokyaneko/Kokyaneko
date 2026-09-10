/*
<方針>
  各クエリに対して、配列の値を加工・表示する

  タイムアウト対策
  * クエリ2: 値をずらすのではなく、参照する区間を変更する
  * クエリ3: クエリ1が行われるごとにその配列までの論理和を計算する その論理和と先頭データの差を表示する
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int q;
  cin>>q;
 
  int hebi[300000]; 
  long long last=0;
  long long first=0;
  vector<long long> total(q,0);

  for(int i=0;i<q;i++){
    int q1;
    cin>>q1;
    if(q1 == 1){
      int q2;
      cin>>q2;
 
      hebi[last] = q2;
      total[last + 1] += total[last] + q2;
      last++;
    }
 
    if(q1 == 2){
      first++;
    }
    if(q1 == 3){
      int q2;
      cin >> q2;
 
      long long resp = total[first+q2-1] - total[first];
      cout<<resp<<endl;
    }
  }
 
  return 0;
}
