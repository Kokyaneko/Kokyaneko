#include <iostream>

using namespace std;

template <class type>//関数の型をtypeに格納
type warun(type a,type n){
    a = a/n;
    return a;
}

int main(){
    double n;
    cout<<"N: ";
    cin>>n;

    int x;
    cout<<"int: ";
    cin>>x;
    cout<< warun<double>(x,n) <<endl;//引数の型を明示的にdoubleに揃える func<type>(a,b,...)

    double y;
    cout<<"double: ";
    cin>>y;
    cout<< warun(y,n) <<endl;

    return 0;
}
