#include <stdio.h>
#define f(a,b) (b*a+1)
int main(){
    int x;
    scanf("%d",&x);
    int re = f(f(f(f(1,x),x),x),x);
    printf("%d\n",re);
    return 0;
}