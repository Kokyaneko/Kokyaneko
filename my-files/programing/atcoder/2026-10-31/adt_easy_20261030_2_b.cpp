#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long nn = n*n;
    for(long long i=0;i<n;i++){
        nn/=2;
    }
    if(nn != 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
