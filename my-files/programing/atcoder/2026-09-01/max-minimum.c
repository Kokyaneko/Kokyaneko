#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int max=0;
    for(int i=0;i<n;i++){
        if(max<a[i]) max = a[i];
    }

    int minimum=max;
    for(int i=0;i<n;i++){
        if(minimum>a[i]) minimum = a[i];
    }

    printf("%d %d\n",max,minimum);

    printf("%d\n",max-minimum);

    return 0;
}
