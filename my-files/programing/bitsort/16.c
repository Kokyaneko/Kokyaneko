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
    sprintf(data,"%x",a);

    printf("%s\n",data);

    return 0;
}
