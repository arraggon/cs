#include "catalog.h"

using namespace std;

int main(){

    string inputFile;
    ifstream input(inputFile);

    

    inputFile = input_file(input);
    int teamsNum;
    input >> teamsNum;

    Team * teams = setup(input, teamsNum);
    while (true)
    {
        int op = choose_option(teams); //option
        if (op == 0)
        {
            break;
        }
        run_prog(teams, teamsNum, op);

    }


    // for (int i = 0; i < 4; i++)
    // {
    //     cout << "Team Name: " << teams[i].name << " ";
    //     cout << "Owner: " << teams[i].owner << " ";
    //     cout << "Market Value: " << teams[i].market_value << " ";
    //     cout << "Number of Players: " << teams[i].num_player << " ";
    //     cout << "Total PPG: " << teams[i].total_ppg << " " << endl;
    //     for (int j = 0; j < teams[i].num_player; j++)
    //     {
    //         cout << "Player Name: " << teams[i].p[j].name << " ";
    //         cout << "Age: " << teams[i].p[j].age << " ";
    //         cout << "Nationality: " << teams[i].p[j].nation << " ";
    //         cout << "PPG: " << teams[i].p[j].ppg << " ";
    //         cout << "FG: " << teams[i].p[j].fg << endl;
    //     }
    // }

    delete_info(teams, teamsNum);
}