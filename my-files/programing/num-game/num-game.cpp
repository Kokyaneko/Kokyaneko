#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class game{
private:
    vector<int> status;
    int maisu;
public:
    game(int start_num){
        status.resize(start_num+1,0);
        srand(time(NULL));
        for(int i=0;i<start_num;i++) status[i] = rand()%10;
        maisu=start_num;
    }

    void show(void){
        for(int i=0;i<maisu;i++){
            cout << status[i] << " ";
        }
        puts("");
    }

    int thr(void){
        int bangou;
        cout << "select throwing card (pass:0): ";
        cin >> bangou;
        if(bangou < 0) return -1;

        int yama=status[bangou-1];
        for(int i=bangou-1;i<maisu;i++) status[bangou-1] = status[bangou];
        maisu--;
        status.resize(maisu-1);

        return yama;
    }

    bool kachi(void){
        if(int(status.size()) == 1) return true;
    }
};

int main(void){
    int start_num;
    cin >> start_num;

    bool owari = false;

    game player(start_num);
    game com(start_num);

    int yama=0;
    while(owari==false){
        player.show();

        int thr = player.thr();
        if(!(thr > yama) and thr != -1){
            cout << "wrong input." << endl;
            player.thr();
        }

        if(player.kachi()==true or com.kachi()==true) owari=true;
    }

    return 0;
}
