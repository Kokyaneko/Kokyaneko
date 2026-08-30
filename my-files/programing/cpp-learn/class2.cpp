#include <iostream>

using namespace std;

class Days{
private:
    int m;
    int d;
    string day_name;

public:
    Days(int mm,int dd,string day_name_){
        m = mm;
        d = dd;
        day_name = day_name_;
    }

    int mr(){
        return m;
    }

    int dr(){
        return d;
    }

    string namer(){
        return day_name;
    }
};

int main (){
    Days Xmas(12,25,"Chrismas/Xmas");
    Days Valentine(02,14,"Valentine's day");

    cout<<"Chrismas: "<<Xmas.mr()<<'/'<<Xmas.dr()<<' '<<Xmas.namer()<<endl;
    cout<<"Valentine's day: "<<Valentine.mr()<<'/'<<Valentine.dr()<<' '<<Valentine.namer()<<endl;

    string get;

    cout<<endl;

    cout<<"Other Input? (Yes or No): ";
    cin >> get;

    if(get == "No") return 0;
    if((get == "Yes") or (get == "yes") or (get == "y")){
        int m,d;
        string name;

        cout<<"MM/DD: ";
        cin >> m >> d;
        cout<<"Name: ";
        cin >> name;

        Days a(m,d,name);

        cout<<a.namer()<<": "<<a.mr()<<'/'<<a.dr()<<' '<<a.namer()<<endl;
    }

    return 0;
}
