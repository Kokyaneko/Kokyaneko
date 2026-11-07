#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        s[i] = to_string(i+1);
    }
    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        reverse(s.begin(),s.begin()+a);
        for(int i=0;i<a;i++){
            if(s[i][0] == '-') s[i].erase(0,1);
            else s[i] = '-' + s[i];
        }
    }
    for(int i=0;i<n;i++){
        cout << s[i] << endl;
    }
    return 0;
}
