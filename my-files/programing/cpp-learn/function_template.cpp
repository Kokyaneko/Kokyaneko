#include <iostream>

using namespace std;

template <class type>//関数の型をtypeに格納
type waru2(type a){
    a = a/2;
    return a;
}

int main(){
    int n;
    cout<<"int: ";
    cin>>n;
    cout<<waru2(n)<<endl;

    double nn;
    cout<<"double: ";
    cin>>nn;
    cout<<waru2(nn)<<endl;

    return 0;
}
