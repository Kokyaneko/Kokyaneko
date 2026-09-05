//update version

/*
<方針>
  インプットを100,10,1のくらいに分離する
  - 100,10の位の数の積が1の位の数に等しいならその数を出力
  - そうでなければインプットの数+1,2,3...で確かめる
*/

#include <iostream>

using namespace std;

int main(){
  int N;
  std::cin>>N;
  
  for(int i=N;i<=919;i++){ //i=Nで真偽を問わずfor文の中で判定
    int id=i;
    int h = id/100;
    id-=h*100;
    int t = id/10;
    id-=t*10;
    int o = id;
    
    if(h*t==o){
      cout<<i<<endl;
      break;
    }
  }
  return 0;
}
