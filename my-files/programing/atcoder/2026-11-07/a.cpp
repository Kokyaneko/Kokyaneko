#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a;
    cin >> a;
    if(fmod(a/2,1)==0) cout << int(a/2) << endl;
    else cout << int(a/2+1) << endl;
    return 0;
}
