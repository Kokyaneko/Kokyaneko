//O(N)

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n;
    cout << "Input number: ";
    cin >> n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cout << "Input person[" << i+1 <<"]: ";
        cin >> a[i];
    }
    string q;
    cout << "Input query: ";
    cin >> q;
    for(int i=0;i<n;i++){
        if(a[i].find(q) != string::npos) cout << i+1 << ' ' << a[i] << endl;
    }
    return 0;
}
