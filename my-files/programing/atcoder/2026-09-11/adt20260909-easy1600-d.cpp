/*
<方針>
    3個の文字配列に入力を格納する.
    入力クエリTを1文字ごとに解釈,表示する.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> s(3);

    for(int i=0;i<3;i++){
        cin >> s[i];
    }

    string t;
    cin >> t;

    for(int i=0;i<t.size();i++){
        if(t[i] == '1') cout<<s[0];
        if(t[i] == '2') cout<<s[1];
        if(t[i] == '3') cout<<s[2];
    }

    puts("");

    return 0;
}
