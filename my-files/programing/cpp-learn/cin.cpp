#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int main(void){
    int a;

    cout<<"Enter number>";
    cin>>a;

    cout<<"Your input:"<< a <<endl;

    getchar();

    char n[12];

    cout<<"Enter string(max 10 char): ";
    cin.getline(n,9,'\n');
    //cin.getline(文字列名,最大文字数(\n,\oを含む),この文字を見つけたら読み込み終了)

    cout<<"Your input: "<< n <<endl;

    puts("Your input(tolower):");
    for(int i=0;n[i];i++){
        cout<<static_cast<char>(tolower(n[i]));
        //tolower:大文字->小文字
    }

    puts("");
    puts("Your input(toupper): ");
    for(int i=0;n[i];i++){
        cout<<static_cast<char>(toupper(n[i]));
        //toupper:小文字->大文字
    }
    puts("");

    return 0;
}
