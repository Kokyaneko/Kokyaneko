#include <iostream>
#include <string>
using namespace std;
string B = "B";
string Y = "Y";
string R = "R";
int main(){
    string s;
    cin >> s;
    if(s == B) cout << "Y" << endl; 
    if(s == Y) cout << "R" << endl; 
    if(s == R) cout << "B" << endl; 

    return 0;
}
