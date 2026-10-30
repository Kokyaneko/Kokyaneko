#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int main(){
    cout << "How many input?: ";
    int n;
    cin >> n;
    map<string,int> a;
    set<string> nam; //set 同じ要素が重複しないような配列が組める.
    for(int i=0;i<n;i++){
        string inp;
        int money;
        cin >> inp >> money;
        a[inp] = money;
        nam.insert(inp);
    }
    for(auto it=nam.begin();it!=nam.end();++it){
        cout << *it << ' ' << a[*it] << endl;
    }
    return 0;
}
