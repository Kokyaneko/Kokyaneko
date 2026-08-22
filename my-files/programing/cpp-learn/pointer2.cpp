#include <iostream>

using namespace std;

int main(void){
    int array[5] = { 0 , 1 , 100 , 101 , 200};//editable

    puts("array(direct): ");
    for(int i=0;i<5;i++){
        cout<<array[i]<<' ';
    }
    puts("");

    int *p = array;

    puts("array(via *p): ");
    for(int i=0;i<5;i++){
        cout<< p[i] <<' ';
    }
    puts("");

    for(int i=0;i<5;i++){
        cout<< *(p+i) <<' ';
    }
    puts("");

    return 0;
}
