#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  
  int student_class[n];
  int class_count[k];
  
  for(int i=0;i<n;i++){
    scanf("%d",&student_class[i]);
    class_count[student_class[i]-1]++;
  }
  
  auto maxnum = max_element(class_count,class_count + sizeof(class_count)/sizeof(int) - 1);

  int pleasure_count=0;
  for(int i=0;i<k;i++){
    if(*maxnum-1<=class_count[i]) pleasure_count++;
  }
 
  cout<<pleasure_count<<endl;
  
  return 0;
}