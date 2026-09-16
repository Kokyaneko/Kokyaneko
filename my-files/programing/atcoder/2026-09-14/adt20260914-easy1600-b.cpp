//A[i] < A[i+1]が真ならYesを出力

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i > 0){
            if(!(a[i-1] < a[i])){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
