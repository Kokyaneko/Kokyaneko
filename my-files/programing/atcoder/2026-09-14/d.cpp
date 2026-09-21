/*
<方針>
  できる限りi国からi+1国に換金する(最終的にn国に最大値が換金されるようにする)
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<long long> a(n,0);
  for(int i=0;i<n;i++){
     cin >> a[i];
  }
  
  for(int i=0;i+1<n;i++){
    long long ifn,ton;
    cin >> ifn >> ton;
    a[i+1] += ton*(a[i]/ifn);
  }
  
  cout << a[n-1] << endl;
}
