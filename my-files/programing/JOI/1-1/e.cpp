#include <iostream>
#include <string>

using namespace std;

int main(){
    string ss;
    getline(cin,ss);
    if(int(ss.size()) == 1 or int(ss.size()) == 2 or int(ss.size()) == 5) {cout<<"No"<<endl; return 0;}

    string joig = "JOIG";
    string ioi = "IOI";


    for(int i=0;i<int(ss.size());){
        if(ss[i] == joig[0]){
            if(ss[i+1] == joig[1]){
                if(ss[i+2] == joig[2]){
                    if(ss[i+3] == joig[3]){
                        i+4;
                        continue;
                    }
                    else{
                        i+3;
                        continue;
                    }
                }
            }
        }

        else if(ss[i] == ioi[0]){
            if(ss[i+1] == ioi[1]){
                if(ss[i+2] == ioi[2]){
                    i+3;
                    continue;
                }
            }
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }

    return 0;
}
