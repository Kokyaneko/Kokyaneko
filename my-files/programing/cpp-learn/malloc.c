#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *p = malloc(sizeof(int));
    printf("*p: %p\n",p);

    return 0;
}
