#include <stdio.h>

int main(void){
    int i;
    scanf("%d",&i);
    for(int j=1;j<i+1;j++){
        if(j%3==0){
            printf("Fizz\n");
        }else{
            printf("%d\n",j);
       }
    }
    return 0;
}
