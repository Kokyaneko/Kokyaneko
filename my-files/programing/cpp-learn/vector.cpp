//std::vectorを用いたソートの実装

#include <iostream>
#include <vector>//for std::vector
#include <algorithm>//for std::sort

using namespace std;

int main(){
    int n;
    cout << "Number of input?: ";
    cin>>n;

    vector<int> a(n,0);//vector<型> 配列名(要素数,初期値)
    for(int i=0;i<n;i++){
        cout<<"Input a["<<i<<"]: ";
        cin>>a[i];
    }

    vector<int> b = a;//copy vector

    std::sort(a.begin(),a.end(),less<>());//昇順でソート
    std::sort(b.begin(),b.end(),greater<>());//降順でソート

    puts("");
    puts("Greater");
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]: "<<a[i]<<endl;
    }

    puts("Less");
    for(int i=0;i<n;i++){
        cout<<"b["<<i<<"]: "<<b[i]<<endl;
    }

    auto maxnum = max_element(a.begin(),a.end());
    puts("");
    cout<<"Max number: "<<*maxnum<<endl;

    return 0;
}
