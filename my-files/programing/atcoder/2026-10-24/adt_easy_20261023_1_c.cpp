#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<long long> s(n);
    vector<long long> t(n);
    for(int i=0;i<n-1;i++){
        cin >> s[i] >> t[i];
    }
    for(int i=0;i<n-1;i++){
        long long koukan = a[i]/s[i];
        a[i+1] += koukan*t[i];
    }
    cout << a[n-1] << endl;
    return 0;
}
