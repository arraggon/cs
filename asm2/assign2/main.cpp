#include <iostream>
#include "game.h"
using namespace std;

int main(){
    welcome();//welcome part
    int play_ag =1;
    while (play_ag==1)
    {
        cout << endl << "Player 1: " << endl;
        int P1_score = game(0.0);//game 1
        cout << endl << "Player 2: " << endl;
        int P2_score = game(0.0);//game 2
        winner(P1_score,P2_score);
        play_ag = play_again();
    }
}