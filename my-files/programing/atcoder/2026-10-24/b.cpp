#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    if(a[0] == k) cnt++;
    for(int i=0;i<n-1;i++){
        if((a[i] < k and k < a[i+1]) or (a[i] > k and k > a[i+1])) cnt++;
        else if(a[i+1] == k) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
