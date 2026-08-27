#include <iostream>
#include <string>

const int DATA_NUM = 3;

using namespace std;

class Families{
private:
    string name;
    int birth_y;

public:
    //コンストラクタ
    Families(string get_name,int get_birth_y){
        name = get_name;
        birth_y = get_birth_y;
    }

    string show_name(void){
        return name;
    }
    int show_birth(void){
        return birth_y;
    }
};

int main(void){
    string name[DATA_NUM];
    int birth_y[DATA_NUM];

    for(int i=0;i<DATA_NUM;i++){
        cout<<"Name("<<i<<")? :";
        cin>>name[i];
        cout<<"Birth year("<<i<<")? :";
        cin>>birth_y[i];
    }

    Families A(name[0],birth_y[0]);
    Families B(name[1],birth_y[1]);
    Families C(name[2],birth_y[2]);

    cout<<A.show_name()<<endl;
    cout<<A.show_birth()<<endl;
    puts("");
    cout<<B.show_name()<<endl;
    cout<<B.show_birth()<<endl;
    puts("");
    cout<<C.show_name()<<endl;
    cout<<C.show_birth()<<endl;
 
    return 0;
}
