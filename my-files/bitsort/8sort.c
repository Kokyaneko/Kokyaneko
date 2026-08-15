#include <stdio.h>
#include <stdlib.h>
#define INT_MAX_IN_8 37777777778

int main (void){
    int n;
    scanf("%d",&n);

    puts("");

    int a[n-1];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    char data[n-1][16];

    for(int i=0;i<n;i++){
        sprintf(data[i],"%o",a[i]);
    }

    puts("\n8 bit numbers");

    long int hachi[n-1];
    for(int i=0;i<n;i++){
        hachi[i] = atoi(data[i]);
        printf("%ld\n",hachi[i]);
    }

    int sorted_count=0;
    int sorted[n];
    for(int i;i<INT_MAX_IN_8;i++){
        for(int j=0;j<n;j++){
                if(i==hachi[j]){
                    sorted[sorted_count]=i;
                    sorted_count++;
                }
        }

        if(sorted_count=n-1)break;

    }

    puts("\n8 bit sorted numbers");
    for(int i=0;i<n;i++) printf("%d\n",sorted[i]);

    return 0;
}
