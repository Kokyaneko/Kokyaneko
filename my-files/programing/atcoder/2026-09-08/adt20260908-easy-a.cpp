#include <iostream>

using namespace std;

int main(){
    int g,s;
    cin>>g>>s;

    if(g>0 and s==0) cout<<"Gold"<<endl;
    if(g>0 and s>0) cout<<"Alloy"<<endl;
    if(g==0 and s>0) cout<<"Silver"<<endl;

    return 0;
}
