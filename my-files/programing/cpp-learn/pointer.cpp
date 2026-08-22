#include <iostream>

using namespace std;

int main(void){
    int a;

    cout<<"enter number: ";
    cin >> a;
    int &p = a;//Cとは異なり、ポインタは&nのように宣言できる。また、アドレスではなく、変数名を直接代入できる。

    cout<<"a: "<< a <<endl;
    cout<<"&p(=a): "<< p <<endl;

    p = 3;
    cout<<"a(changed from p): "<< p <<endl;

    int *pp = &p;
    cout<<"*pp(=p=a): "<< *pp <<endl;

    return 0;
}
