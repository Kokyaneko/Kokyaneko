#include <stdio.h>

int main(){
    printf("input num: ");
    int n;
    scanf("%d",&n);
    int a[n];
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>0;j--){
            if(a[j] < a[j-1]){
                int swap = a[j];
                a[j] = a[j-1];
                a[j-1] = swap;
            }
            count++;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    puts("");
    printf("%d\n",count);
    return 0;
}
