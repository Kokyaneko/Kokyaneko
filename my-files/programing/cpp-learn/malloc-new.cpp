#include <iostream>
#include <cstdio>
#include <cstdlib>

int main (void){
    int a = 100;
    std::cout<<"a(int): "<< a <<std::endl;

    //malloc - C
    int *p = (int*)malloc(sizeof(int));//C++では型判定が厳格なため、int*型に変更する。
    *p = a;
    printf("*p=100(malloc): %d %p\n",*p,p);
    free(p);

    //new - C++
    int *pp = new int;
    *pp = 200;
    std::cout<<"*pp=200(new): "<< *pp <<' '<< pp <<std::endl;
    delete p;

    return 0;
}
