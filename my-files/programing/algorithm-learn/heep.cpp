#include <iostream>
#include <vector>
using namespace std;
int main(){
    int x;
    cin >> x;
    vector<int> a(x+1,0);//1 indexed

    //add number
    for(int i=1;i<=x;i++){
        cin >> a[i];
        for(int j=i;j>0;){
            if(a[int(j/2)] > a[j]){
                int swap = a[j];
                a[j] = a[int(j/2)];
                a[int(j/2)] = swap;
            }else{ break; }
            j = int(j/2);
        }
    }
    cout << "minimum = " << a[1] << endl;
    return 0;
}
