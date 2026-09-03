#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  
  int a[n];
  int total=0;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    total+=a[i];
  }
 
  for(int i=1;i<101;i++){
    int count = 0;
    for(int j=0;j<n;j++){
      if(a[j] == i){
        count++;
      }
    }
    total -= (int)(count/2)*2*i;
  }
 
  printf("%d\n",total);
 
  return 0;
}