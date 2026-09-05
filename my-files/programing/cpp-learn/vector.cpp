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
    std::sort(a.begin(),a.end());//昇順でソート

    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]: "<<a[i]<<endl;
    }

    return 0;
}
