#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<long long> a(n,0);
    int usiro = 0;
    for(int i=0;i<n;i++){
        int q;
        cin >> q;
        if(q == 1){
            int x; cin >> x;
            a[usiro] = x;
            usiro++;
        }
        if(q == 2){
            int k; cin >> k;
            cout << a[usiro-k] << endl;
        }
    }
    return 0;
}
