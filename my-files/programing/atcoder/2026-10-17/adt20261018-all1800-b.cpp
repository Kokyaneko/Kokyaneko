#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int shu=0;
        for(int i=0;i<7;i++){
            int a;
            cin >> a;
            shu += a;
        }
        cout << shu << ' ';
    }
    return 0;
}
