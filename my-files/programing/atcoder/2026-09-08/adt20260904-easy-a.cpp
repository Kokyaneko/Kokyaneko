#include <iostream>

using namespace std;

int main(){
  int r,g,b;
  cin>>r>>g>>b;
  
  string c;
  cin>>c;
  
  if(c=="Red") r = 1000;
  if(c=="Green") g = 1000;
  if(c=="Blue") b = 1000;
  
  int minn = min({r,g,b});
  
  cout<<minn<<endl;
 
  return 0;
}
