#include <iostream>

using namespace std;
int main (void){
    int a;
    cin >> a;

    switch(a){
        case 0 : return 0;
        case 1 : cout << 'a' << endl; break;//breakしないとcase2,3も実行される
        case 2 : cout << 'b' << endl; break;//breakしないとcase3も実行される
        case 3 : cout << 'c' << endl; break;
    }

    return 0;
}
