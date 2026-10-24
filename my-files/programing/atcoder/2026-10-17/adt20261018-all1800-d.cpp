#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t,x;
    cin >> t >> x;
    vector<int> a(t+1,0);
    for(int i=0;i<t+1;i++) cin >> a[i];
    int mae = 1000;
    for(int i=0;i<t+1;i++){
        if(!(abs(a[i]-mae)<x)) {cout << i << ' ' << a[i] << endl; mae=a[i];}
    }
    return 0;
}
