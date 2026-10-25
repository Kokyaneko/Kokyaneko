#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;
    string t;
    cin >> t;
    long long k;
    cin >> k;
    for(long long i=1;i<k;i++){
        s+=s;
        if(int(s.size()) > 500) break;
    }
    if(s.find(t) != string::npos) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
