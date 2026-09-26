#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int q;
    cin >> q;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<int> a(s.size(),0);
    for(int i=0;i<s.size();i++){
        string kensaku;
        for(int j=0;j<t.size();j++) kensaku[j] = s[i+j];
        if(t == kensaku) {a[i]++; i += t.size()-1;}
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        int ok=0;
        for(int i=0;i<s.sise();i++){
            if(a[i]>=l and a[i]+a.size()<=r) {ok++; break;}
        }
        if(ok != 0) cout << "Yes" <<endl;
        else if cout << "No" <<endl;
    }

    return 0;
}
