#include <iostream>
#include <cstdio>

using namespace std;

int main (){
    int a=3;

    //cast - clasical
    printf("3/2(int):%d\n",a/2);
    printf("3/2(double):%f\n",(double)a/2);

    //static_cast - modern
    cout<<"3/2(int):"<<a/2<<endl;
    cout<<"3/2(double):"<<static_cast<double>(a)/2<<endl;

    return 0;
}
