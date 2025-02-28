#include <iostream>
#include <fstream>
#include <string>

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
    teams[num].total_ppg = 0.0;
}

void delete_info(Team * teams, int num){
    for (int i = 0; i < num; i++) {
        delete[] teams[i].p;
    }

    delete[] teams;
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


Team* setup(ifstream & input, int teamsNum){
    Team * teams = create_teams(teamsNum);
    
    store_data(teams, teamsNum, input);

    input.close();
    
    return teams;
}


int choose_option() {//print the options
    int option;
    while (true)
    {
        cout << "1. Search team by its name " << endl;
        cout << "2. Display the top scorer of each team " << endl;
        cout << "3. Search players by nationality " << endl;
        cout << "4. Sort teams by total points per game " << endl;
        cout << "5. Simulate a game " << endl;
        cout << "0. Quit " << endl;
        cin >> option; //get user's input
        cout << "Your choice: " <<  option << endl;
        if ((option >= 0)&&(option <= 5))
        {
            break;
        }
        cout << "The option doesn't exsit! Please enter another one." << endl;
    }
    
    
    return option; //return user's input
}

int choose_method(){
    int dm;
    while (true)
    {
        cout << "1. Print to screen (Press 1)" << endl;
        cout << "2. Print to file (Press 2)" << endl;
        cout << "The option doesn't exsit!" << endl;

        cin >> dm; //get user's input
        cout << "Your choice: " << dm << endl;
        if ((dm == 1)||(dm == 2))
        {
            break;
        }
        cout << "The option doesn't exsit! Please enter another one." << endl;
    }
    return dm;
}

string input_file(ifstream & input){
    string inputFile;
    while (true)
    {
        cout << "enter the input file name:" << endl;
        cin >> inputFile;
        input.open(inputFile);
        if (input.is_open())
        {
            break;
        }
        cout << "The file doesn't exsit!" << endl;
    }
    cout << inputFile<<endl;
    return inputFile;
}

string output_file(ofstream & output){
    string outputFile;
    while (true)
    {
        cout << "enter the output file name:" << endl;
        cin >> outputFile;
        output.open(outputFile);
        if (output.is_open())
        {
            break;
        }
        cout << "The file doesn't exsit!" << endl;
    }
    return outputFile;
    
}

void print_team(Team * teams, int i, int dp, ofstream & output){
    if (dp == 1)
    {
        cout << "Team Name: " << teams[i].name << " ";
        cout << "Owner: " << teams[i].owner << " ";
        cout << "Market Value: " << teams[i].market_value << " ";
        cout << "Number of Players: " << teams[i].num_player << " ";
        cout << "Total PPG: " << teams[i].total_ppg << " " << endl;
    } else if (dp == 2)
    {
        output << "Team Name: " << teams[i].name << " ";
        output << "Owner: " << teams[i].owner << " ";
        output << "Market Value: " << teams[i].market_value << " ";
        output << "Number of Players: " << teams[i].num_player << " ";
        output << "Total PPG: " << teams[i].total_ppg << " " << endl;
    }
    
}

void search_team_name(Team * teams, int tN, int dp, ofstream & output){
    string teamName;
    int theT = -1; //the team
    cout << "What is the team name?" << endl;
    cin >> teamName;
    for (int i = 0; i < tN; i++)
    {
        if (teams[i].name == teamName)
        {
            theT = i;
            break;
        }
    }
    if (theT != -1)
    {
        print_team(teams, theT, dp, output);
    }   
}

void run_prog(Team * teams, int tN, int op, int dp){//tN is teams' Number

    string outputFile;
    ofstream output(outputFile);

    switch (op)
    {
    case 1:
        search_team_name(teams, tN, dp, output);
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    
    default:
        break;
    }
}



int main(){

    string inputFile;
    ifstream input(inputFile);
    inputFile = input_file(input);

    int teamsNum;
    input >> teamsNum;
    cout << teamsNum;
    Team * teams = setup(input, teamsNum);


    string outputFile;
    ofstream output(outputFile);
    outputFile = output_file(output);

    int op = -1;
    int dp = 0;
    while (op != 0)
    {   
        op = choose_option(); //option
        dp = choose_method();
        run_prog(teams, teamsNum, op, dp);
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