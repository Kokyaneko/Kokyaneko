#include <iostream>
#include <string>
using namespace std;
const string a = "aeiou";
int main(){
    string s; cin >> s;
    for(int i=0;i<s.size();i++){
        int ok = 0;
        for(int j=0;j<5;j++){
            if(s[i] == a[j]) ok--;
        }
        if(ok==0) cout << s[i];
    }
    return 0;
}
