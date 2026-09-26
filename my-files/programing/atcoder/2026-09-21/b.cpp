#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  int n,m,x,t,d;
  cin >> n >> m >> x >> t >> d;
  for(int i=n;i>m;i--){
    if(i<=x) t -= d;
  }
  cout << t << endl;
  return 0;
}
