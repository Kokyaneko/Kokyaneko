#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;

    int count=0;
    for(int i=0;i<int(s.size());i++){
        if(s[i] == 'v') count++;
        if(s[i] == 'w') count+=2;
    }
    cout << count << endl;
    return 0;
}
