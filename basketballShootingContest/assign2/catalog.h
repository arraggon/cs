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


/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
                an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team* create_teams(int);


/**************************************************
 * Name: populate_team_data()
 * Description: This function will fill a single team struct 
                with information that is read in from the file
 * Parameters:  Team* - pointer to the Team array
                int - index of the Team in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Team array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Team at provided index is populated
 ***********************************************/
void populate_team_data(Team*, int, ifstream &); 


/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
                an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int);


/**************************************************
 * Name: populate_player_data()
 * Description: This function will fill a single player struct 
                with information that is read in from the file
 * Parameters:  Player* - pointer to the Player array
                int - index of the Player in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Player array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Player at provided index is populated
 ***********************************************/
void populate_player_data(Player*, int, ifstream &); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Team* - the Team array
 * Pre-conditions: the provided Team array hasn't been freed yet
 * Post-conditions: the Team array, with all Players inside, is freed
 ***********************************************/
void delete_info(Team*, int);
void store_data(Team * teams, int teamsNum, ifstream & input);
Team* setup(ifstream & input, int teamsNum);
int choose_option(Team * teams);//print the options
int choose_method();
string input_file(ifstream & input);
string output_file(ofstream & output);
void cout_team(Team * teams, int tT);
void output_team(Team * teams, int tT,ofstream & output);
void print_team(Team * teams, int tT, int dp, ofstream & output);
void search_team_name(Team * teams, int tN, int dp, ofstream & output);
void print_top_scorers(Team * teams, int i, int topP, int dp, ofstream & output);
void top_scorers(Team * teams, int tN, int dp, ofstream & output);
void print_nat_players(Team * teams, int i, int j, int dp, ofstream & output);
void search_nat_players(Team * teams, int tN, int dp, ofstream & output);
void print_sort(Team * teams, int tN, int dp, ofstream & output);
void sort_teams_ppg(Team * teams, int tN, int dp, ofstream & output);
int find_player(string name, Team * teams, int tN);
string get_name(Team * teams, int tN, int p);
void game_run(Team * teams, int tN);
void sim_game(Team * teams, int tN, int dp, ofstream & output);
int run_prog(Team * teams, int tN, int op);//tN is teams' Number
