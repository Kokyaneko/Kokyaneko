#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    for(int i=0;i<101;i++){
        if(i != a and i != b){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
