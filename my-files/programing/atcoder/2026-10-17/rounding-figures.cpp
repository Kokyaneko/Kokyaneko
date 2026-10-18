#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"input a,b: "; cin>>a>>b;
    
    cout << "ROUNDING: "<< int(a/b) << endl;
    cout << "ROUND OFF: "<< int((double)a/(double)(b) + 0.5) << endl;
    cout << "ROUND UP: "<< int((a + b-1) /b) << endl;

    return 0;
}
