#include <iostream>

using namespace std;

int main (void){
    enum alpha {exit, x, y, z, invalid};

    int a;
    do{
        cout<<"0:exit 1:a 2:b 3:c >";
        cin >> a;
    } while(a<exit or a>invalid);

    alpha b = static_cast<alpha>(a);//int型変数aをalpha型に変換する

    switch(b){
        case 0 : return 0;
        case 1 : cout << 'A' << endl; break;//breakしないとcase2,3も実行される
        case 2 : cout << 'B' << endl; break;//breakしないとcase3も実行される
        case 3 : cout << 'C' << endl; break;
    }

    return 0;
}
