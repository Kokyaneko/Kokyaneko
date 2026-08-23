#include <stdio.h>

int main (void){
  int C;
  scanf("%d",&C);

  char s[C+1];
  scanf("%s",s);

  if(C<2){
    if(s[0]=='o'){
        puts("0")
        return 0;
    }
    puts("1");
    return 0;
  }

  int match_count = 0;

  if(s[0]=='x'){
    if(s[1]=='x')match_count++;
  }

  for(int i=1;i<C-1;i++){
    if(s[i]=='x'){
      if(s[i-1]=='x'){
        if(s[i+1]=='x')match_count++;
      }
    }
  }

  if(s[C-1]=='x'){
    if(s[C-2]=='x')match_count++;
  }

  printf("%d\n",match_count);

  return 0;
}
