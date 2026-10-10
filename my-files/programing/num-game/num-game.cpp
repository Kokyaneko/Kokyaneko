#include <iostream>
#include <vector>
#include <algorithm>
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

    int thr(int o_yama){
        int bangou;
        cout << "select throwing card (pass:0): ";
        cin >> bangou;

        if(!(bangou > o_yama) and bangou != -1){
            cout << "wrong input." << endl;
            return -2;
        }
 
        if(bangou < 0) return -1;

        int yama=status[bangou-1];
        status.erase(status.begin()+bangou-1);
        maisu--;

        return yama;
    }

    int autothr(int yama){
        auto it = min_element(status.begin(),status.end());
        status.erase(it);
        maisu--;
        return *it;
    }

    bool kachi(void){
        if(int(status.size()) == 1) return true;
        else return false;
    }
};

int main(void){
    int start_num;
    cin >> start_num;

    bool owari = false;

    game player(start_num);
    game com(start_num);

    int yama=-1;
    while(owari==false){
        player.show();

        int thr = player.thr(yama);
        if(thr > -1) yama = thr;
        else if(thr == -1) cout << "You passed." << endl;
        else if(thr == -2) continue;

        thr = com.autothr(yama);
        if(thr == -1) cout << "computer passed.";
        else yama = thr;

        cout << "computer: " << yama << endl;

        if(player.kachi()==true or com.kachi()==true) owari=true;
    }

    return 0;
}
