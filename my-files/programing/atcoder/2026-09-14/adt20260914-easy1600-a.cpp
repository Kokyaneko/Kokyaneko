//abc+bca+cab

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a = n/100;
    int b = (n - a*100) / 10;
    int c = (n - a*100 - b*10);

    int total = n;
    total += b*100 + c*10 + a;
    total += c*100 + a*10 + b;

    cout << total << endl;

    return 0;
}
