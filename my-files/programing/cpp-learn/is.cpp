//==より良い?

#include <iostream>
#define is ==
using namespace std;

int main(){
    int a,b;
    cout << "Input 2 numbers: ";
    cin >> a >> b;
    if(a is b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
