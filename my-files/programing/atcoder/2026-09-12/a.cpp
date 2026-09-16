#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    int i=0;
    for(;i<int(s.size()) - 1;i++){
        cout<<s[i]<<"o";
    }

    cout<<s[i]<<endl;

    return 0;
}
