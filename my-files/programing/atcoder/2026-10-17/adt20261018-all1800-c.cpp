#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    string s;
    cin >> n >> k >> s;
    for(int i=0;i<n;i++){
        if(s[i] == 'o' and k>0){
            cout << 'o';
            k--;
        }
        else cout << 'x';
    }
    return 0;
}
