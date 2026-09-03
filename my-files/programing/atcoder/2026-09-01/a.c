#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  int start_ptr = n/2;
  int total=0;
  for(int i = start_ptr;i<n;i++){
    total += a[i];
  }
  
  printf("%d\n",total);
 
  return 0;
}