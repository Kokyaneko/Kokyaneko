//code for atcorder daily task 2026/08/17 Easy 16:00: A-Healthy Breakfast

#include <stdio.h>

int main (void){
  char input[3];
  scanf("%s",input);

  int r=0;
  
  for(int i=0;i<3;i++){
    if(input[i] == 'R'){
      for(int j=i;j<3;j++){
        if(input[j] == 'M'){
          r++;
        }
      }
    }
  }

  if(r>=1){
    puts("Yes");
  }else{
    puts("No");
  }

  return 0;
}
