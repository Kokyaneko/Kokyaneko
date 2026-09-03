#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main (){
  int n; 
  cin>>n;
  
  string s[n][10];
  char is[n][10];
  for(int i=0;i<n;i++){
    cin>>is[i];
    for(int j=0;j<10;j++){
      s[i][j] = static_cast<string>(toupper(is[i][j]));
    }
  }

  map<string,int> data;
  int data_num = 0,data_num_c=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(s[i] == s[j]) data_num_c++;
    }
    if(data_num_c == n-1)data_num++;
    data[s[i]]++;
  }
 
  int r = 0;
  for(auto& [k,v]:data) r = max(r,v);

  cout<<r<<endl;
 
  return 0;
}
