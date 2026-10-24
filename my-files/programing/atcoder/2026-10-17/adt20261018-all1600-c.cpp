#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=0;i<int(s.size());i++){
        if(s[i] == '#') cout << '#';
        else if(i == 0 or s[i-1] == '#') cout << 'o';
        else cout << '.';
    }
    puts("");
    return 0;
}
