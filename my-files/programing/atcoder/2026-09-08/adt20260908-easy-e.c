#include <stdio.h>

int main(){
  int q;
  scanf("%d",&q);
 
  int hebi[300000]; 
  long long last=0;
  long long first=0;
  for(int i=0;i<q;i++){
    int q1;
    scanf("%d",&q1);
    if(q1 == 1){
      int q2;
      scanf("%d",&q2);
       
      hebi[last] = q2;
      last++;
    }
    
    if(q1 == 2){
      first++;
    }
    if(q1 == 3){
      int q2;
      scanf("%d",&q2);
      
      long long total=0;
      for(int j=0;j<q2-1;j++){
        total+=hebi[first+j];
      }
      printf("%lld\n",total);
    }
  }
 
  return 0;
}
