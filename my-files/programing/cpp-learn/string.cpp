#include <iostream>
#include <cstdio>

using namespace std;

const char* hw(){
    return "Hello world!";
}

string input_return(string text){
    text = "Your input: " + text;

    return text;
}

int main(){
    //C style
    printf("%s\n",hw());

    //C++ style
    string hw = "Hello";
    hw = hw + " " + "World!";
    cout<<hw<<endl;

    puts("");

    string input;
    cout<<"Input text: ";
    cin>>input;
    cout<<input_return(input)<<endl;

    return 0;
}
