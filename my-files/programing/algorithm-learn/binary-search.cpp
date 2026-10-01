#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int x,s;
    cin >> x >> s;
    vector<int> a(x,0);
    for(int i=0;i<x;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    int l = -1;
    int r = x;
    int count = 0;
    bool found = false;

    while(r-l > 1){
        count++;
        int mid = l + (r-l)/2;
        if(a[mid] > s) r = mid;
        if(a[mid] < s) l = mid;
        if(a[mid] == s){found = true; break;}
    }

    if(found == true) cout << s << " found." << endl;
    else cout << "Not found." << endl;
    cout << "O(" << count << ')' << endl;
    return 0;
}
