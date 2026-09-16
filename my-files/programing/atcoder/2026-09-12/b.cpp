#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n,0);
    vector<int> kane(3,0);//1:0 10:1 100:2

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int b = int(a[i]/kane[j]);
            kane[j] -= b;
            a[i] -= b * kane[j];

            if
         }
    }

    return 0;
}
