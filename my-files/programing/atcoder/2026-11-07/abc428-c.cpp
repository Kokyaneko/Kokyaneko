#include <iostream>
#include <vector>
using namespace std;
int main(){
    int q;
    cin >> q;
    int left = 0;
    int right = 0;
    vector<int> a;
    vector<bool> ok;
    a.push_back(0);
    ok.push_back(true);
    while(q--){
        int qq;
        cin >> qq;
        if(qq == 1){
            char inp;
            cin >> inp;
            if(inp == '(') a.push_back(a.back()+1);
            else a.push_back(a.back()-1);
            if(a.back() >= 0 and ok.back() == true) ok.push_back(true);
            else ok.push_back(false);
        }else{
            a.pop_back();
            ok.pop_back();
        }
        if(a.back() == 0 and ok.back() == true) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
