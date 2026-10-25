#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n,l,r;
    cin >> n >> l >> r;
    int count=0;
    for(int i=0;i<n;i++){
        int h;
        string s;
        cin >> h >> s;
        if(l<=h and h<=r and s=="Yes") count++;
    }
    cout << count << endl;
    return 0;
}
