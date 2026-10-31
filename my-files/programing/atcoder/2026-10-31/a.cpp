#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    int cou=0;
    for(int i=0;i<int(s.size());i++){
        if(s[i] == 'o') cou++;
    }
    if(cou%2 == 0) cout<<"even"<<endl;
    else cout<<"odd"<<endl;
    return 0;
}
