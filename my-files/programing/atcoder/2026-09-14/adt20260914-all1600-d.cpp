#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    vector<long long> s(n-1,0);
    vector<long long> t(n-1,0);
    for(int i=0;i<n-1;i++){
        cin >> s[i] >> t[i];
        long long kankin = a[i]/s[i];
        a[i+1] += kankin * t[i];
    }

    cout << a[n-1] << endl;
    return 0;
}
