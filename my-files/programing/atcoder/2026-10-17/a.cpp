#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string u;
    string d;

    cin >> u;
    cin >> d;
    
    u += '.';
    d += '.';

    bool ok = false;
    if(u[0] == 'D' and u[1] == 'A') ok = true;
    if(d[0] == 'D' and d[1] == 'A') ok = true;
    if(d[1] == 'D' and d[0] == 'A') ok = true;
    if(u[1] == 'D' and u[0] == 'A') ok = true;
    for(int i=0;i<2;i++){
        if(u[i] == 'A' and d[i] == 'D') ok = true;
        if(u[i] == 'D' and d[i] == 'A') ok = true;
    }
    if(ok == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
