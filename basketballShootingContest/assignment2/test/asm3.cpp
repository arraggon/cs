#include <iostream>
#include <fstream>

using namespace std;

//a struct to hold info of a team
struct Team {
  string name;        //name of the team
  string owner;       //owner of the team
  int market_value;   //market value of the team
  int num_player;     //number of players in the team
  struct Player *p;   //an array that holds all players
  float total_ppg;    //total points per game
};

//a struct to hold info of a player
struct Player {
  string name;      //name of the player
  int age;          //age of the player
  string nation;    //nationality of the player
  float ppg;        //points per game of the player
  float fg;         //field goal percentage
};

Player* create_players(int players_num){
    Player * players = new Player[players_num];
    return players;
}

void populate_players_data(Player* players, int num, ifstream & input){
    input >> players[num].name;
    input >> players[num].age;
    input >> players[num].nation;
    input >> players[num].ppg;
    input >> players[num].fg;
}

Team* create_teams(int teams_num){
    Team * teams = new Team[teams_num];
    return teams;
}

void populate_team_data(Team * teams, int num, ifstream & input){
    input >> teams[num].name;
    input >> teams[num].owner;
    input >> teams[num].market_value;
    input >> teams[num].num_player;
    teams[num].p = create_players(teams[num].num_player);
    teams[num].total_ppg = 0;
}

void store_data(Team * teams, int teamsNum, ifstream & input){
    for (int i = 0; i < teamsNum; i++)
    {
        populate_team_data(teams, i, input);

        for (int j = 0; j < teams[i].num_player; j++)
        {
            populate_players_data(teams[i].p, j, input);
            teams[i].total_ppg += teams[i].p[j].ppg;
        }
    }
}

int main(){
    ifstream input;
    input.open("teams.txt");
    int teamsNum;
    input >> teamsNum;

    cout << teamsNum;

    Team * teams = create_teams(teamsNum);
    
    store_data(teams, teamsNum, input);
    
    

    // for (int i = 0; i < teamsNum; i++)
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
    //         cout << "FG%: " << teams[i].p[j].fg << endl;
    //     }
        
    // }
}