/*
<方針>
  ギザギザとした2次元配列(malloc)

  0. 列数を受け取る
  1. 各列の要素数を受け取る
  2. 受け取った要素数について、malloc関数を用いて容量確保
  3. 各配列にデータを格納
  4. 呼び出された番地のデータを表示
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d",&n);
  
  int l[n];
  int *p[n];
  for(int i=0;i<n;i++){
    scanf("%d",&l[i]);
    p[i] = malloc(l[i] * sizeof(int));
    
    for(int j=0;j<l[i];j++){
      scanf("%d",&p[i][j]);
    }
  }
  
  int y,x;
  scanf("%d %d",&y,&x);
  
  printf("%d",p[y-1][x-1]);
 
  return 0;
}