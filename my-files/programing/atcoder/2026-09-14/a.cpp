#include <iostream>

using namespace std;

int main (){
  int x;
  cin >> x;
  for(int i=1;i<=3;i++){
    if(i != x){
      cout << i << endl;
      break;
    }
  }
 
  return 0;
}
