#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> a;
    int newid = 1;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(a[s] == 0){
            cout << newid << endl;
            a[s] = newid;
            newid++;
        }
        else cout << a[s] << endl;
    }
    return 0;
}
