#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(100,0);
    vector<long long> input(n,0);
    int res = -1;

    for(int i=0;i<n;i++){
        cin >> input[i];

        if(input[i] > (long long)(a.size()) - 1) a.resize(input[i]+1);

        a[input[i]]++;
        if(a[input[i]] == 2){
            for(int j=0;j<i;j++){
                if(input[j] == input[i]){
                    res = i-j+1;
                    break;
                }
            }
        if(res != -1) break;
        }
    if(res != -1) break;
    }

    cout << res << endl;
    
    return 0;
}
