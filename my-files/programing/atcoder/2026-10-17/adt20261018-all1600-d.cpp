#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool ok = false;
    int count=0;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s == "login") ok = true;
        if(s == "logout") ok = false;
        if(s == "private" and ok == false) count++;
        else continue;
    }
    cout << count << endl;
    return 0;
}
