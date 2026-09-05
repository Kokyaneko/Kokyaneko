#include <iostream>

using namespace std;

int main(){
  char s[30];
  cin >> s;
  
  for(char c='a';c<'z'+1;c++){ //文字型は数字として扱われるためfor文で使える
    int re=0;
    for(int j=0;j<30;j++){
      if(s[j] == c) re++;
    }
 
    if(re == 0){
      cout<<c<<endl;
      return 0;
    }
  }
 
  return 0;
}