/*********************************************************************
**Program Filename: GoHooping
** Author: Dongwen yang
** Date: 10/15/2023
** Description: Simulating a basketball shooting game for a local high school
** Input: Number of players(int), money ball rack position(1-5) and play again or not(0-1)
** Output: result, score and winner of the game
*********************************************************************/
#include <iostream>
using namespace std;

int get_num(){// how many players
    int num = 0;
    cout << "How many players? ";
    cin >> num;
    return num;
}

/********************************************************************* 
** Function: get_num
** Description: get the number of how many players will play the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return the integer what the player entered
*********************************************************************/

int get_mbr(){//money ball rack
    int mbr;
    cout << "Where do you want to put your money-ball rack? Enter 1-5: ";
    cin >> mbr;
    while (mbr < 1||mbr > 5)
    {
        cin.clear();
        cout << endl << "That’s not a valid input." << endl;
        cout << "Where do you want to put your money-ball rack? Enter 1-5: " << endl;
        cin >> mbr;
    }
    return mbr;
}

/********************************************************************* 
** Function: get_mbr
** Description: get input from player where the money ball position is
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return the number repersents where the player want to set his money ball rack
*********************************************************************/

int get_pa(){//play again?
    int play_a;
    cout << endl << "Do you want to play again? (1-yes, 0-no): " << endl;
    cin >> play_a;
    while ((play_a != 1) && (play_a != 0))
    {
        cin.clear();
        cout << endl << "Sorry, that’s not a valid input." << endl;
        cout << "Do you want to play again? (1-yes, 0-no): " << endl;
        cin >> play_a;
    }
    return play_a;
}

/********************************************************************* 
** Function: get_pa
** Description: ask if user wanna play again or not, if yes, enter 1; if not, enter 0;
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return 
*********************************************************************/

void o_r(int i1, int i2, int i3, int i4, int i5, char c1, char c2, char c3, char c4, char c5){
    int it = i1 + i2 + i3 + i4 + i5;
    cout << c1 << " " << c2 << " " << c3 << " " << c4 << " " << c5 << " | " << it << " " << "pts" << endl;
}

/********************************************************************* 
** Function: o_r
** Description: print out result of a rack, 5 shots results and the rack score
** Parameters: i1, i2, i3, i4, i5: Integers representing the scores of the 5 shots. c1, c2, c3, c4, c5: Characters representing the result(made or miss) of the 5 shots.
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/


int *score(int mbr_p){
    int made_s[27] = { 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 3, 3};
    int mbr = 5 * mbr_p;
    for (int d = mbr - 5; d < mbr; d++)
    {
        made_s[d] = 2;
    }
    int miss_s[27] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int result[27];
    for (int b = 0; b < 27; b++)
    {
        int shot = rand() % 2;
        if (shot == 1)
        {
            result[b] = made_s[b];
        } else {
            result[b] = miss_s[b];
        }
    }
    return result;
}

/********************************************************************* 
** Function: score
** Description: setup the money ball position and simulating the shots with 50% chance made it
** Parameters: int mbr_p, the money ball position.
** Pre-Conditions: int mbr_p should be a integer(1-5)
** Post-Conditions: Returns an integer array of length 27 representing the results of 27 shots.
*********************************************************************/

char sw_to(int num){
    switch (num)
    {
    case 0:
        return 'X';
        break;
    case 1:
        return 'O';
        break;
    case 2:
        return 'M';
        break;
    case 3:
        return 'W';
        break;
    
    default:
        return 0;
        break;
    }
}

/********************************************************************* 
** Function: sw_to
** Description: switch score number to be result letters
** Parameters: int num
** Pre-Conditions: none
** Post-Conditions: return result letters 
*********************************************************************/

int print_out(){
    int *rs = score(get_mbr());
        char op[27];
        int pts = 0;

        for (int c = 0; c < 27; c++)
        {
            op[c] = sw_to(rs[c]);
        }

        for (int f = 0; f < 5; f++)
        {
            if ((f == 2)||(f == 3))
            {
                cout << "Starry: " << op[23+f] << "         |" << rs[23+f] << endl;
            }
            cout << "Rack " << f+1 << " :";
            for (int g = 0; g < 5; g++)
            {
                cout << op[(f*5)+g] << " ";
                pts = pts + rs[f*5+g];
            }
            cout << "|" << rs[f*5]+rs[f*5+1]+rs[f*5+2]+rs[f*5+3]+rs[f*5+4] << " pts" << endl;
        }
        return pts + rs[25]+rs[26];
}

/********************************************************************* 
** Function: print_out
** Description: print out the game result and score
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return total score for next function
*********************************************************************/

int *game(int num){
    int *gr = new int[num];
    for (int a = 0; a < num; a++)
    {
        cout << endl << "player " << a+1  << ": " << endl;
        int pn = print_out();
        cout << endl << "Total: " << pn << " pts" << endl;
        gr[a] = pn;
    }
    return gr;
}

/********************************************************************* 
** Function: game
** Description: put all game precesses functions inside, repeat the game as much and player number
** Parameters: int num, the number of players
** Pre-Conditions: none
** Post-Conditions: return the player's game result
*********************************************************************/

int best_s (int x[], int n) {
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > best)
        {
            best = x[i];
        }
        
    }
    return best;
}

/********************************************************************* 
** Function: best_s
** Description: find out the highest score
** Parameters: int x[], this array storeed all players' total scores; int n, it is the number of players
** Pre-Conditions: none
** Post-Conditions: return the highest score in the around
*********************************************************************/

int winner_n(int x[], int best) {//winner numbers
    int *re_s = x;
    int s_re_s = sizeof(re_s);
    int order[s_re_s];
    int num = 0;
    //cout << best << endl;
    for (int i = 0; i < s_re_s; i++)
    {
        if (re_s[i]==best)
        {
            num++;
        }
    }
    //cout << "THE NUM IS " << num << endl;
    return num;
}

/********************************************************************* 
** Function: winner_n
** Description: find out how many player or players got the highest score
** Parameters: int x[], the array stored the total scores of all players, int best, it is the highest score.
** Pre-Conditions: none
** Post-Conditions: return the number of players got highest score
*********************************************************************/

void winners(int scores[], int winner_n, int best, int player_n) {
    if ((winner_n == player_n) && (winner_n != 1))
    {
        cout << "Tie Game!!" << endl;
    } else if (winner_n == 1)
    {
        for (int i = 0; i < player_n; i++)
        {
            if (scores[i]==best)
            {
                cout << " " << endl << "Player " << i+1 << " is the winner!!" << endl;
            }
        }
    } else {
        for (int i = 0; i < player_n; i++)
        {
            if (scores[i] == best)
            {
                cout << "Player " << i+1 <<" ";
            }
        }
        cout << "are the winners!!" << endl;
    }
}

/********************************************************************* 
** Function: winner
** Description: finded and print out who is or are the winner
** Parameters: int scores[], all players' total scores; int winner_n, the number of players who had highest score; int best, high score; int player_n, how many players in the game
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

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

/********************************************************************* 
** Function: main
** Description: this is the main function of the basketball shooting contest program
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/