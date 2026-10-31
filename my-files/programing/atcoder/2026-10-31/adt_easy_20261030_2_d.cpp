//1,2,3について,文字と捉えて,キーがchar型のmapを実装する.
//1文字だとstring型ではなくchar型にキャストされるため注意する.

#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map<char,string> a;
    cin >> a['1'] >> a['2'] >> a['3'];
    string q;
    cin >> q;
    for(int i=0;i<int(q.size());i++){
        cout<<a[q[i]];
    }
    return 0;
}
