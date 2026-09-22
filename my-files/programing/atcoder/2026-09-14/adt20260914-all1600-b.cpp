#include <iostream>
#include <vector>
using namespace std;
int main(){
    int x;
    cin >> x;
    vector<int> a(x,0);
    for(int i=0;i<x;i++){
        cin >> a[i];
        if(i>0){
            if(!(a[i]>a[i-1])){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
