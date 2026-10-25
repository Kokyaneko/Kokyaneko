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
    int count=0;
    for(int i=0;i<n;i++){
        int a,b;
        string s;
        cin >> a >> b >> s;
        if(s == "keep") count+=b-a;
    }
    cout << count << endl;
    return 0;
}
