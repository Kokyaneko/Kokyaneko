#include <stdio.h>
#include <stdlib.h>

int main (int argc,char *argv[]){
    int a;
    if(argc!=2){
        scanf("%d",&a);
    }else{
        a = atoi(argv[1]);
    }

    char data[16];
    sprintf(data,"%o",a);

    long int hati = atoi(data);

    printf("%s\n",data);

    return 0;
}
