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


int choose_option(Team * teams) {//print the options
    int option;
    while (true)
    {
        cout << "1. Search team by its name " << endl;
        cout << "2. Display the top scorer of each team " << endl;
        cout << "3. Search players by nationality " << endl;
        cout << "4. Sort teams by total points per game " << endl;
        cout << "5. Simulate a game " << endl;
        cout << "0. Quit " << endl;
        cout << "Your choice: ";
        cin >> option; //get user's input
        if ((option >= 0)&&(option <= 5))
        {
            break;
        }
        cin.clear();
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

        cout << "Your choice: ";
        cin >> dm; //get user's input
        if ((dm == 1)||(dm == 2))
        {
            break;
        }

        cin.clear();
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
        cin.clear();
        cout << "The file doesn't exsit!" << endl;
    }
    return inputFile;
}

string output_file(ofstream & output){
    string outputFile;
        cout << "enter the output file name:" << endl;
        cin >> outputFile;
    return outputFile;
}

void print_team(Team * teams, int tT, int dp, ofstream & output){
    if (dp == 1)//cout
    {
        cout << "Team Name: " << teams[tT].name << endl;
        cout << "Owner: " << teams[tT].owner << endl;
        cout << "Market Value: " << teams[tT].market_value << endl;
        cout << "Number of Players: " << teams[tT].num_player << endl;
        cout << "Total PPG: " << teams[tT].total_ppg << " " << endl;
    } else if (dp == 2)//ofstream
    {
        output << "Team Name: " << teams[tT].name << endl;
        output << "Owner: " << teams[tT].owner << endl;
        output << "Market Value: " << teams[tT].market_value << endl;
        output << "Number of Players: " << teams[tT].num_player << endl;
        output << "Total PPG: " << teams[tT].total_ppg << " " << endl;
    }
    output.close();
}
void search_team_name(Team * teams, int tN, int dp, ofstream & output){
    cout << "What is the team name?" << endl;
    string teamName;
    cin >> teamName;
    int theT = -1;
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
    } else {
        cout << "the team doesn't exsit!" << endl;
    }
}

void print_top_scorers(Team * teams, int i, int topP, int dp, ofstream & output){
    if (dp == 1)
    {
        cout << teams[i].name << ": " << teams[i].p[topP].name << " " << teams[i].p[topP].ppg << endl;
    } else if (dp == 2)
    {
        output  << teams[i].name << ": " << teams[i].p[topP].name << " " << teams[i].p[topP].ppg << endl;
    }
}

void top_scorers(Team * teams, int tN, int dp, ofstream & output){
    for (int i = 0; i < tN; i++)
    {
        int topP = 0;
        for (int j = 1; j < teams[i].num_player; j++)
        {
            if (teams[i].p[j].ppg > teams[i].p[j-1].ppg)
            {
                topP = j;
            }   
        }
        print_top_scorers(teams, i, topP, dp, output);
    }
    
}
void print_nat_players(Team * teams, int i, int j, int dp, ofstream & output){
    if (dp == 1)
    {
        cout << teams[i].p[j].name << " " << teams[i].p[j].age << endl;
    } else if (dp == 2)
    {
        output  << teams[i].p[j].name << " " << teams[i].p[j].age << endl;
    }
}
void search_nat_players(Team * teams, int tN, int dp, ofstream & output){
    cout << "Enter the player’s nationality: ";
    string nation;
    cin >> nation;
    for (int i = 0; i < tN; i++)
    {
        int topP = 0;
        for (int j = 0; j < teams[i].num_player; j++)
        {
            if (teams[i].p[j].nation == nation)
            {
                print_nat_players(teams, i, j, dp, output);
            }   
        }
    }
    
}

void print_sort(Team * teams, int tN, int dp, ofstream & output){
    for (int i = 0; i < tN; i++)
    {
        if (dp == 1)
        {
            cout << teams[i].name << " ,total points per game:" << teams[i].total_ppg << endl;
        } if (dp == 2)
        {
            output << teams[i].name << " ,total points per game:" << teams[i].total_ppg << endl;
        }
        
    }
    
}

void sort_teams_ppg(Team * teams, int tN, int dp, ofstream & output){
    Team temp;
    for (int i = 0; i < tN; i++)
    {
        for (int j = 1; j < tN; j++)
        {
            if (teams[j].total_ppg > teams[j-1].total_ppg)
            {
                temp = teams[j-1];
                teams[j-1] = teams[j];
                teams[j] = temp;
            }
            
        }
    }
    print_sort(teams, tN, dp, output);
}

int run_prog(Team * teams, int tN, int op){//tN is teams' Number

    int dp = choose_method(); //display

    string outputFile;
    ofstream output;
    if (dp == 2)
    {
        outputFile = output_file(output);
        output.open(outputFile);
    }


    switch (op)
    {
    case 1:
        search_team_name(teams, tN, dp, output);
        break;
    case 2:
        top_scorers(teams, tN, dp, output);
        break;
    case 3:
        search_nat_players(teams, tN, dp, output);
        break;
    case 4:
        sort_teams_ppg(teams, tN, dp, output);
        break;
    case 5:
    
        break;
    
    default:
        break;
    }

    return op;
}



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


    // if (dp == 1)
    // {
        
    // } else if (dp == 2)
    // {
        
    // }