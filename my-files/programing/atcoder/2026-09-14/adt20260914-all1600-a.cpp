//abc+bca+cab
#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    int a = x/100;
    int b = (x-100*a)/10;
    int c = x-100*a-10*b;
    int total = 0;
    total += a*100+b*10+c;
    total += b*100+c*10+a;
    total += c*100+a*10+b;
    cout << total << endl;
    return 0;
}
