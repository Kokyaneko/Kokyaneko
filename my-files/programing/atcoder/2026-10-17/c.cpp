#include <iostream>
using namespace std;

int main(){
    long long n,k,t;
    cin >> n >> k >> t;

    long long now = 0;
    long long count = 0;
    for(int i=0;i<n;i++){
        long long next;
        cin >> next;
        if(!(next < t)) break;
        if(next < now) now = next;

        count += (long long)((next-now + k-1) / k);

        now = next+k;
        if(now > t) break;
    }

    if(!(now > t)) count += (long long)((t-now + k-1) / k);

    cout << count << endl;

    return 0;
}
