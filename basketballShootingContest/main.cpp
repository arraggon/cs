#include <iostream>
#include "game.h"
using namespace std;

int main() {
    srand((unsigned) time(NULL));
    cout << "Welcome to the basketball shooting contest!" << endl << endl;
    int play_a = 1;
    while (play_a == 1)
    {
        int player_num = get_num();
        int *all_scores = game(player_num);
        int best = best_s(all_scores, player_num);
        int win_num = winner_n(all_scores, best);
        winners(all_scores, win_num, best, player_num);

        //cout << "Players " << player_num << " best " << best << " winner number " << win_num << endl;

        play_a = get_pa();
        delete [] all_scores;
    }
}