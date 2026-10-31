#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<long long,long long> a;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        a[x]++;
    }
    long long total=0;
    for(auto it=a.end();it!=a.begin();--it){
        total += it->second;
        if(!(total < it->first)){
            cout << it->first;
            return 0;
        }
    }
    return 0;
}
