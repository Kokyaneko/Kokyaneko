#include <iostream>
#include <vector>
using namespace std;

int main(){
    cout << "input num: ";
    int n;
    cin >> n;
    vector<int> a(n,0);
    int count=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>0;j--){
            if(a[j] < a[j-1]){
                int swap = a[j];
                a[j] = a[j-1];
                a[j-1] = swap;
            }
            count++;
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    puts("");
    cout << "O(" << count << ")" << endl;
    return 0;
}
