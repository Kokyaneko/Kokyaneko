#include <iostream>

using namespace std;

class Days{
private:
    int m;
    int d;
    string day_name;

public:
    //constructer
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

    int eve(){
        if(d>1) return d-1;
        else return -1;
    }

    string namer(){
        return day_name;
    }
};

int main (){
    Days Xmas(12,25,"Chrismas/Xmas");
    Days X_eve = Xmas;//copy constructer
    Days Valentine(02,14,"Valentine's day");

    cout<<"Valentine's day: "<<Valentine.mr()<<'/'<<Valentine.dr()<<' '<<Valentine.namer()<<endl;
    cout<<"Chrismas: "<<Xmas.mr()<<'/'<<Xmas.dr()<<' '<<Xmas.namer()<<endl;
    cout<<"Chrismas eve: "<<X_eve.mr()<<'/'<<X_eve.eve()<<' '<< X_eve.namer() + " eve"<<endl;

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
