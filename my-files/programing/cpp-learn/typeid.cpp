#include <iostream>
#include <typeinfo>
#include <cstdio>

using namespace std;

struct A{
    int b;
    double c;
    char d[72];
    int e[4];
};

int main (){
    A x;
    
    cout<<"x: "<<typeid(x).name()<<endl;
    cout<<"x.b: "<<typeid(x.b).name()<<endl;
    cout<<"x.c: "<<typeid(x.c).name()<<endl;
    cout<<"x.d: "<<typeid(x.d).name()<<endl;
    cout<<"x.d: "<<typeid(x.e).name()<<endl;
    cout<<"'A': "<<typeid('A').name()<<endl;

    return 0;
}
