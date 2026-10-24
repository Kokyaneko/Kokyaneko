#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = n/100;
    int b = (n-100*a)/10;
    int c = (n-100*a-10*b);
    cout << b*100+c*10+a + c*100+a*10+b + n << endl;
    return 0;
}
