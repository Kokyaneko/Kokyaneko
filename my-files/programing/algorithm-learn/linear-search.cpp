#include <iostream>
using namespace std;

int main(){
    int x,s;
    cin >> x >> s;
    int count=0;
    for(int i=0;i<x;i++){
        int a;
        cin >> a;
        if(a == s) cout << "a[" << i << "] = " << a << endl; 
        count++;
    }
    cout << "O(" << count << ')' << endl;
    return 0;
}
