#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>

int main (void){
    int n;
    scanf("%d",&n);

    puts("");

    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    char data[n][16];

    for(int i=0;i<n;i++){
        sprintf(data[i],"%o",a[i]);
    }

    std::cout<<"\n8 bit numbers"<<std::endl;

    long int hachi[n-1];
    for(int i=0;i<n;i++){
        hachi[i] = atoi(data[i]);
        printf("%ld\n",hachi[i]);
    }

    std::sort(hachi,hachi+n);

    puts("\n8 bit sorted numbers");
    for(int i=0;i<n;i++){
        std::cout<<hachi[i]<<std::endl;
    }

    std::cout<<std::endl<<"10 bit sorted numbers"<<std::endl;
    
    int result[n];
    char hachi_num[n][16];
    for(int i=0;i<n;i++){
        sprintf(hachi_num[i],"%d",hachi[i]);
        result[i] = std::stoi(hachi_num[i],nullptr,8);

        printf("%d\n",result[i]);
    }

    return 0;
}
