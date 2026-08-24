//code for atcorder daily task 2026/08/17 Easy 16:00: B-Vacation Validation

#include <stdio.h>

int main(void){
    int n,l,r,fail=0;
    scanf("%d %d %d",&n,&l,&r);

    char s[n];
    scanf("%s",s);

    for(int i=l-1;i<r;i++){
        if(s[i] == 'x'){
            fail++;
        }
    }

    if(fail == 0){
        puts("Yes");
    }else{
        puts("No");
    }

    return 0;
}
