/*
<方針>
    j行に#があるか,i列に#があるかを考える
    あるのであれば,記録用配列tate[j],yoko[i]に記録する
*/

#include <iostream>
#include <vector>
using namespace std;
int main(){
    char s[10][10];
    vector<int> tate(8,0);
    vector<int> yoko(8,0);
    for(int i=0;i<8;i++){
        cin >> s[i];
        for(int j=0;j<8;j++){
            if(s[i][j] == '#'){tate[j]++; yoko[i]++;}
        }
    }
    int count = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(tate[j] == 0 and yoko[i] == 0) count++;
        }
    }
    cout << count << endl;
    return 0;
}
