#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void){
    cout<<"output random number 0-99"<<endl;

    int n;
    cout<<"Number of output: ";
    cin>>n;

    srand(time(NULL));

    int x[n];
    for(int i=0;i<n;i++){
        x[i] = rand()%100;
    }

    for(int i=0;i<n;i++) cout<<x[i]<<' ';

    puts("");

    return 0;
}
