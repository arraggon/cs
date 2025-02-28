#include "catalog.h"

using namespace std;

int main(){

    string inputFile;// read file
    ifstream input(inputFile);

    

    inputFile = input_file(input);//get users file
    int teamsNum;
    input >> teamsNum;//get the first line as teams number

    Team * teams = setup(input, teamsNum);//store teams and players data
    while (true)
    {
        int op = choose_option(teams); //options
        if (op == 0) //if user wanna quit
        {
            break;
        }
        run_prog(teams, teamsNum, op);//do users choice

    }


    for (int i = 0; i < 4; i++)
    {
        cout << "Team Name: " << teams[i].name << " ";
        cout << "Owner: " << teams[i].owner << " ";
        cout << "Market Value: " << teams[i].market_value << " ";
        cout << "Number of Players: " << teams[i].num_player << " ";
        cout << "Total PPG: " << teams[i].total_ppg << " " << endl;
        for (int j = 0; j < teams[i].num_player; j++)
        {
            cout << "Player Name: " << teams[i].p[j].name << " ";
            cout << "Age: " << teams[i].p[j].age << " ";
            cout << "Nationality: " << teams[i].p[j].nation << " ";
            cout << "PPG: " << teams[i].p[j].ppg << " ";
            cout << "FG: " << teams[i].p[j].fg << endl;
        }
    }

    delete_info(teams, teamsNum);
}