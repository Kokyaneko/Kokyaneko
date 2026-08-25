//code for atcorder daily task 2026/08/17 Easy 16:00: C-Grid Walk

#include <stdio.h>

int main(void){
  int h,w;
  scanf("%d %d",&h,&w);

  int x,y;
  scanf("%d %d",&y,&x);
  
  char s[h][w];
  for(int i=0;i<h;i++){
    scanf("%s",s[i]);
  }
 
  char X[50];
  scanf("%s",X);
 
  for(int a=0;X[a];a++){
    if(X[a]=='U'){
      if(y-1!=0){
        if(s[y-2][x-1]!='#') y--;
      }
    }
 
    if(X[a]=='D'){
      if(y+1!=h+1){
        if(s[y][x-1]!='#') y++;
      }
    }

    if(X[a]=='L'){
      if(x-1!=0){
        if(s[y-1][x-2]!='#') x--;
      }
    }
 
    if(X[a]=='R'){
      if(x+1!=w+1){
        if(s[y-1][x]!='#') x++;
      }
    }
  }

  printf("%d %d\n",y,x);

  return 0;
}
