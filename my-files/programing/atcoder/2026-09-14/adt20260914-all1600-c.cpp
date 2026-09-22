#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int x,k;
    cin >> x >> k;

    vector<string> a(x);
    for(int i=0;i<x;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.begin()+k);
    for(int i=0;i<k;i++){
        cout << a[i] << endl;
    }
    return 0;
}
