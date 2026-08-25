#include <iostream>

using namespace std;

namespace USA{
    int count_number = 1;
    void HW(){
        cout<<"USA:Hello world!"<<endl;
    }
}

namespace Japanese{
    int count_number = 81;
    void HW(){
        cout<<"Japanese:こんにちは"<<endl;
    }
}
namespace JP = Japanese;//別名をつけることができる

int main(void){
    cout<<"USA coutry number: "<<USA::count_number<<endl;
    USA::HW();

    cout<<"Japanese coutry number: "<<JP::count_number<<endl;
    JP::HW();

    return 0;
}
