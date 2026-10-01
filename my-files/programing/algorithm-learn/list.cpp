#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> a;

    //push
    int n;
    cout << "push num: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "enter push num: ";
        int inp;
        cin >> inp;
        a.push_back(inp);
    }
    for(auto it = a.begin();it != a.end();++it){
        cout << *it << " ";
    }
    puts("");

    //pop
    int nn;
    cout << "pop num:";
    cin >> nn;
    for(int i=0;i<nn;i++) a.pop_back();
    for(auto it = a.begin();it != a.end();++it){
        cout << *it << " ";
    }
    puts("");

    return 0;
}
