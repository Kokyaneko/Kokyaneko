#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;
int main(){
    vector<string> s(5);
    for(int i=0;i<5;i++){
        cin >> s[i];
    }
    int mini=5;
    //tate
    for(int i=0;i<5;i++){
        int cou=0;
        for(int j=0;j<5;j++){
            if(s[j][i]!='o') cou++;
        }
        if(mini>cou) mini=cou;
    }
    //yoko
    for(int i=0;i<5;i++){
        int cou=0;
        for(int j=0;j<5;j++){
            if(s[i][j]!='o') cou++;
        }
        if(mini>cou) mini=cou;
    }
    //naname
    int cou=0;
    for(int i=0;i<5;i++){
        if(s[i][i] != 'o') cou++;
    }
    if(mini>cou) mini=cou;
    cout << mini << endl;
    return 0;
}
