#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());

    int kiriage = n/2 + 1;
    int total = 0;
    for(int i=0;i<kiriage;i++) total += a[a.size()-i-1];
    cout << total << endl;
    return 0;
}
