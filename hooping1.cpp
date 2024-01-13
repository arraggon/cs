#include <iostream>
using namespace std;

void welcome() {
    cout << "welcome" << endl;
}

int money_ball_rack(){//where is the
    int mbr;
    cout << "Where do you want to put your money-ball rack? Enter 1-5: ";
    cin >> mbr;
    while ((mbr < 1) || (mbr > 5))
    {
        cout << endl << "That’s not a valid input." << endl;
        cin >> mbr;
    }
    return mbr;
}

void switch_mbr(char sets[7][5], int mbrp) {
    int mbr;

    switch (mbrp)
    {
    case 1:
        mbr = 1;
        break;
    case 2:
        mbr = 2;
        break;
    case 3:
        mbr = 4;
        break;
    case 4:
        mbr = 6;
        break;
    case 5:
        mbr = 7;
        break;
    
    default: 
        mbr = mbrp;
        break;
    }
    for (int i = 0; i < 5; i++)
    {
        sets[mbr-1][i] = 'M';
    }
}

void sim_shots(char ball_sets[7][5]) {
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((rand() % 2) == 0)
            {
                ball_sets[i][j] = 'X';
            }
            if ((i == 2) || (i == 4))
            {
                break;
            }
        }
    }
}

int calculator_rack_score(char shots[7][5],int row){
    int rack_score = 0;
    for (int i = 0; i < 5; i++)
    {
        switch (shots[row][i])
        {
        case 'O':
            rack_score += 1;
            break;
        case 'M':
            rack_score += 2;
            break;
        case 'W':
            rack_score += 3;
            break;
        
        default:
            rack_score += 0;
            break;
        }
    }
    return rack_score;
}

int calculator_total_score(char shots[7][5]){
    int total = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
          switch (shots[i][j])
            {
            case 'O':
                total += 1;
                break;
            case 'M':
                total += 2;
                break;
            case 'W':
                total += 3;
                break;
                
            default:
                total += 0;
                break;
            }
            if ((i==2)||(i==4))
            {
                break;
            }
        }
    }
    return total;
}

void print_order(int i){
    switch (i)
    {
    case 0:
        cout << "Rack 1: ";
        break;
    case 1:
        cout << "Rack 2: ";
        break;
    case 2:
        cout << "Starry: ";
        break;
    case 3:
        cout << "Rack 3: ";
        break;
    case 4:
        cout << "Srarry: ";
        break;
    case 5:
        cout << "Rack 4: ";
        break;
    case 6:
        cout << "Rack 5: ";
        break;
    
    default:
        break;
    }
}

int print_out(char ball_sets[7][5]){
        for (int i = 0; i < 7; i++)
        {
            print_order(i);
            for (int j = 0; j < 5; j++)
            {
                cout << ball_sets[i][j] << " ";
                if ((i == 2) || (i == 4))
                {
                    cout << "        ";
                    break;
                }
            }
        cout <<"| " << calculator_rack_score(ball_sets, i) << " pts" << endl;
    }
    int tatol = calculator_total_score(ball_sets);
    cout << endl << "Tatol: " << tatol << " pts" << endl;
    return tatol;
}

int game() {
    int mbrp = money_ball_rack();
    char ball_sets[7][5] = {
        {'O', 'O', 'O', 'O', 'M'},
        {'O', 'O', 'O', 'O', 'M'},
        {'W'},
        {'O', 'O', 'O', 'O', 'M'},
        {'W'},
        {'O', 'O', 'O', 'O', 'M'},
        {'O', 'O', 'O', 'O', 'M'}
    };

    switch_mbr(ball_sets, mbrp);
    sim_shots(ball_sets);
    int score = print_out(ball_sets);
    return score;
}

void winner(int p1, int p2){
    if (p1 > p2)
    {
        cout << "Player 1 is the winner!!" <<endl;
    } else if (p1 < p2){
        cout << "Player 2 is the winner!!" <<endl;
    } else {
        cout << "Tie game!!" <<endl;
    }
}

int play_again(){
    int play_ga;
    cout << endl << "Do you want to play again? (1-yes, 0-no):" <<endl;
    cin >> play_ga;
    while ((play_ga != 0)&&(play_ga != 1))
    {
        cin.clear();
        cout << endl << "Sorry, that’s not a valid input." << endl << "Do you want to play again? (1-yes, 0-no):";
        cin >> play_ga;
    }
    return play_ga;
}

int main(){
    welcome();//welcome part
    int play_ag =1;
    while (play_ag==1)
    {
        cout << endl << "Player 1: " << endl;
        int P1_score = game();//game 1
        cout << endl << "Player 2: " << endl;
        int P2_score = game();//game 2
        winner(P1_score,P2_score);
        play_ag = play_again();
    }
}