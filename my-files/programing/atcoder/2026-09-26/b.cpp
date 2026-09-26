#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,d;
    cin >> n >> d;

    vector<int> a(n,0);
    vector<int> ok(n,0);
    int count=0;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j) if(a[j] >=a[i] and a[j] < a[i]+d) {ok[i]+=1; ok[j]+=1;}
        }
    }

    for(int i=0;i<n;i++) if(ok[i] == 0) count++;
    cout<< count << endl;

    for(int i=0;i<n;i++) if(ok[i] == 0) cout << i+1 << " ";
    puts("");

    return 0;
}
