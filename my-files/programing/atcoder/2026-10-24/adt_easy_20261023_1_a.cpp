#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a=0;
    int b=0;
    int c=0;
    for(int i=0;i<6;i++){
        if(s[i] == '1') a++;
        if(s[i] == '2') b++;
        if(s[i] == '3') c++;
    }
    if(a == 1 and b==2 and c==3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
