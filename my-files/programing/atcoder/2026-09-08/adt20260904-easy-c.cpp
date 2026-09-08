/*
<方針>
  0. h行w列の数列を取得
  1. 取得した数字と英文字は一対一対応しているから対応するAtoZの文字列を出力する
*/
#include <iostream>

using namespace std;

string ABC = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int h,w;//H 個(行)の長さ W の文字列
  cin>>h>>w;
  
  int num[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>num[i][j];
    }
  }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout<<ABC[num[i][j]];
    }
    puts("");
  }
 
  return 0;
}