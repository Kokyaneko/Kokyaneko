#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b==c or a+c==b or b+c==a or(a==b and b==c)) cout<<"Yes"<<endl;
    else cout << "No" << endl;
    return 0;
}
