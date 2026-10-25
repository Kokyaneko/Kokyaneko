//縦 R 行，横 C 列

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    long long r,c;
    cin >> r >> c;
    vector<string> a(r+2);
    for(int i=0;i<c+2;i++) a[0][i] = 'U';
    for(int i=1;i<r+1;i++){
        cin >> a[i];
        a[i] = 'L' + a[i] + 'R';
    }
    for(int i=0;i<c+2;i++) a[r+1][i] = 'D';

    long long cunt=0;
    for(int i=1;i<r+2;i++){
        for(int j=1;j<c+2;j++){
            if(a[i][j] == 'U' and a[i-1][j] == 'D') cunt++;
            if(a[i][j] == 'L' and a[i][j-1] == 'R') cunt++;
        }
    }
    cout << cunt << endl;
    
    return 0;
}
