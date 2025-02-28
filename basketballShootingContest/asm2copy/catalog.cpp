#include "catalog.h"
#include "game.h"
#include <iostream>
#include <fstream>

using namespace std;

/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
                an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int players_num){
    Player * players = new Player[players_num];
    return players;
}

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
void populate_players_data(Player* players, int num, ifstream & input){
    input >> players[num].name;
    input >> players[num].age;
    input >> players[num].nation;
    input >> players[num].ppg;
    input >> players[num].fg;
}

/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
                an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team* create_teams(int teams_num){
    Team * teams = new Team[teams_num];
    return teams;
}

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
void populate_team_data(Team * teams, int num, ifstream & input){
    input >> teams[num].name;
    input >> teams[num].owner;
    input >> teams[num].market_value;
    input >> teams[num].num_player;
    teams[num].p = create_players(teams[num].num_player);
    teams[num].total_ppg = 0.0;
}

/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Team* - the Team array
 * Pre-conditions: the provided Team array hasn't been freed yet
 * Post-conditions: the Team array, with all Players inside, is freed
 ***********************************************/
void delete_info(Team * teams, int num){
    for (int i = 0; i < num; i++) {
        delete[] teams[i].p;
    }

    delete[] teams;
}

/**************************************************
 * Name: store_data
 * Description: reads data about sports teams and their players from an input file, 
                populates data structures representing the teams and players, and calculates the
                total points per game for each team.
 * Parameters: Team * teams - pointer to an array that stores information aboout sport teams and
               their players
               int teamsNum: integer representing the number of teams for which data will be read
                             and populated
               ifstream & input: A reference to an input file stream that is used to read the data
                                 from a text file
 * Pre-conditions: teams paramter should point ot a valid array, teamsNum should be a non-negative 
                   integer that indicates the number of teams for which data will be read and 
                   populated, populate_team_data and populate_players_data should be defined and 
                   properly handle reading and intializing team and player data
 * Post-conditions: teams data structure  will be populated with data for all teams, including 
                    team-specific information and player information, total_ppg field of each team 
                    in the teams array will be upadted to reflect total ppg for that team, data 
                    read from input file will be processed and stored in the teams data structure
 ***********************************************/
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

/**************************************************
 * Name: setup
 * Description: initializes and populates a data structure for sports teams by reading data from 
 *              an input file and returns a pointer to the populated data structure
 * Parameters: ifstream & input - a reference to an input file stream containing team and player 
               data
               int teamsNum - An integer specifying the number of teams to be set up
 * Pre-conditions: 'input' file must be open and contain valid data in a suitable format, teamsNum
                    should be a non-negative integer, indicating the number of teams to be set up
 * Post-conditions: the function returns pointer to a data structure (Team*) containing information
                    for all teams and their players with the strcuture populated with data from the 
                    input file, input file stream is closed
 ***********************************************/
Team* setup(ifstream & input, int teamsNum){
    Team * teams = create_teams(teamsNum);
    
    store_data(teams, teamsNum, input);

    input.close();
    
    return teams;
}

/**************************************************
 * Name: choose_option
 * Description: Displays a menu of options for a sports team management system and
 *              retrieves the user's choice.
 * Parameters: teams - A pointer to an array of Team objects representing sports teams.
 * Pre-conditions: The 'teams' parameter should point to a valid array of Team objects, the team 
                   structure/class should be properly defined.]
 * Post-conditions: Returns an integer representing the user's selected option.
 ***********************************************/
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
        if (((option >= 0)&&(option <= 5))&& !cin.fail())
        {
            break;
        } else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "The option doesn't exsit! Please enter another one." << endl;
        }
        
    }
    
    
    return option; //return user's input
}

/**************************************************
 * Name: choose_method
 * Description: Presents the user with options for choosing a method to print data
                and retrieves the user's choice.
 * Post-conditions: Returns an integer representing the user's selected printing method (1 for 
                    printing to the screen or 2 for printing to a file)
 ***********************************************/
int choose_method(){
    int dm;
    while (true)
    {
        cout << "1. Print to screen (Press 1)" << endl;
        cout << "2. Print to file (Press 2)" << endl;

        cout << "Your choice: ";
        cin >> dm; //get user's input
        if (((dm == 1)||(dm == 2))&& !cin.fail())
        {
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "The option doesn't exsit! Please enter another one." << endl;
    }
    return dm;
}

/**************************************************
 * Name: input_file
 * Description: Prompts the user to enter an input file name and attempts to open the specified 
                file for reading using an ifstream object
 * Parameters: input - An ifstream object by reference, used to open and read from the input file
 * Pre-conditions: The input parameter is an ifstream object that should be passed by reference,
 *                 the function assumes that the input file specified by the user exists in the 
                   file system
 * Post-conditions: The function returns the name of the successfully opened input file, if the file 
                    doesn't exist, the function continuously prompts the user for a valid file name，
                    the ifstream object input is associated with the opened file for further reading,
                    the function does not modify the file or its contents, the function does not 
                    create or delete any files in the file system.
 ***********************************************/
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

/**************************************************
 * Name: output_file
 * Description: This function prompts the user to enter an output file name and returns the specified
                file name. It does not open or create the file itself; it only retrieves the user's 
                choice for the output file name
 * Parameters: output - An ofstream object passed by reference. This parameter is intended to be used 
               for opening and writing to the output file but is not opened within this function
 * Pre-conditions: The output parameter is an ofstream object passed by reference
 * Post-conditions: The function returns the name of the specified output file entered by the user, 
                    the function does not open or create the output file; it only retrieves the user's 
                    choice for the output file name, the output parameter is not opened or associated 
                    with any file within this function; it remains unaffected.
 ***********************************************/
string output_file(ofstream & output){
    string outputFile;
        cout << "enter the output file name:" << endl;
        cin >> outputFile;
    return outputFile;
}

/**************************************************
 * Name: print_team
 * Description: This function is used to print information about a team, which is stored in an array of 
                Team structures. The information can be printed to either the console (using cout) or
                to an output file (using an ofstream object). The choice of printing destination is 
                determined by the dp parameter.
 * Parameters: teams - An array of Team structures.
               tT - An integer representing the index of the team to be printed from the teams array.
               dp - An integer representing the destination for printing (1 for console, 2 for an output file).
               output - An ofstream object used to write to an output file if dp is set to 2.
 * Pre-conditions: The teams array is assumed to be properly initialized with data, the tT parameter is expected 
                    to be a valid index within the bounds of the teams array, the dp parameter is expected to be 
                    either 1 or 2 (indicating the printing destination).
 * Post-conditions: If dp is 1, the function prints team information to the console using cout.
If dp is 2, the function prints team information to an output file using the provided output ofstream object.
The output file is closed (using output.close()) if dp is 2. The function does not modify the data in the teams array.
 ***********************************************/
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

/**************************************************
 * Name: search_team_name
 * Description: This function is used to search for a team by its name in an array of Team structures. If the team with
                the specified name is found, its information is printed to either the console (using cout) or to an 
                output file (using an ofstream object), based on the dp parameter.
 * Parameters: teams - An array of Team structures.
               tN - An integer representing the total number of teams in the teams array.
               dp - An integer representing the destination for printing (1 for console, 2 for an output file).
               output - An ofstream object used to write to an output file if dp is set to 2
 * Pre-conditions: The teams array is assumed to be properly initialized with data, the tN parameter represents the total 
                   number of teams in the teams array, the dp parameter is expected to be either 1 or 2 (indicating the 
                   printing destination)
 * Post-conditions: the function prompts the user to enter a team name, it searches for a team with the specified name in 
                    the teams array, if the team is found (the name exists in the array), it calls the print_team function
                    to print the team's information to either the console or an output file based on the dp parameter, if 
                    the team is not found, the function prints a message indicating that the team doesn't exist, the output 
                    file is closed (using output.close()) if dp is 2, the function does not modify the data in the teams array
 ***********************************************/
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

/**************************************************
 * Name: print_top_scorers
 * Description: This function is used to print information about the top scorers from a specific team. It can print the top 
                scorer's name and points per game (PPG) to either the console (using cout) or to an output file (using an 
                ofstream object), based on the dp parameter
 * Parameters: teams - An array of Team structures.
               i - An integer representing the index of the team from which you want to print top scorers
               topP - An integer representing the index of the top scorer within the team's players
               dp - An integer representing the destination for printing (1 for console, 2 for an output file)                 
               output - An ofstream object used to write to an output file if dp is set to 2
 * Pre-conditions: The teams array is assumed to be properly initialized with data, the i parameter is expected to be a valid 
               index within the bounds of the teams array， the topP parameter is expected to be a valid index within the 
               bounds of the player array for the specified team, the dp parameter is expected to be either 1 or 2 
               (indicating the printing destination).
 * Post-conditions: f dp is 1, the function prints information about the top scorer's name and points per game (PPG) for a 
                    specific team to the console using cout, if dp is 2, the function prints the same information to an 
                    output file using the provided output ofstream object, the output file is closed (using output.close()) 
                    if dp is 2, the function does not modify the data in the teams array.
 ***********************************************/
void print_top_scorers(Team * teams, int i, int topP, int dp, ofstream & output){
    if (dp == 1)
    {
        cout << teams[i].name << ": " << teams[i].p[topP].name << " " << teams[i].p[topP].ppg << endl;
    } else if (dp == 2)
    {
        output  << teams[i].name << ": " << teams[i].p[topP].name << " " << teams[i].p[topP].ppg << endl;
    }
}

/**************************************************
 * Name: top_scorers
 * Description: This function is used to find and print information about the top scorers from each team in an array of Team 
                structures. It iterates through each team, identifies the player with the highest points per game (PPG), and
                prints the top scorer's information for each team. The information can be printed to either the console 
                (using cout) or to an output file (using an ofstream object), based on the dp parameter.
 * Parameters: teams- An array of Team structures.
               tN - An integer representing the total number of teams in the teams array.
               dp - An integer representing the destination for printing (1 for console, 2 for an output file).
               output - An ofstream object used to write to an output file if dp is set to 2.
 * Pre-conditions: The teams array is assumed to be properly initialized with data, the tN parameter represents the total 
                   number of teams in the teams array, the dp parameter is expected to be either 1 or 2 (indicating the printing 
                   destination)
 * Post-conditions: The function iterates through each team in the teams array and identifies the player with the highest points 
per game (PPG) for each team, it then calls the print_top_scorers function to print information about the top scorer for each team 
to either the console or an output file based on the dp parameter, the output file is closed (using output.close()) if dp is 2, the 
function does not modify the data in the teams array.
 ***********************************************/
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

/**************************************************
 * Name: print_nat_players
 * Description: This function is used to print information about a player from a specific team who is a naturalized (foreign) player,
                it can print the player's name and age to either the console (using cout) or to an output file (using an ofstream 
                object), based on the dp parameter.
 * Parameters: teams - An array of Team structures.
               i - An integer representing the index of the team to which the player belongs.
               j - An integer representing the index of the player within the team's players.
               dp - An integer representing the destination for printing (1 for console, 2 for an output file).
               output - An ofstream object used to write to an output file if dp is set to 2
 * Pre-conditions: The teams array is assumed to be properly initialized with data, the i parameter is expected to be a valid 
index within the bounds of the teams array, the j parameter is expected to be a valid index within the player array for the specified 
team, the dp parameter is expected to be either 1 or 2 (indicating the printing destination).
 * Post-conditions: If dp is 1, the function prints information about the naturalized player's name and age for a specific team to the 
console using cout, if dp is 2, the function prints the same information to an output file using the provided output ofstream object,
the output file is closed (using output.close()) if dp is 2, the function does not modify the data in the teams array.
 ***********************************************/
void print_nat_players(Team * teams, int i, int j, int dp, ofstream & output){
    if (dp == 1)
    {
        cout << teams[i].p[j].name << " " << teams[i].p[j].age << endl;
    } else if (dp == 2)
    {
        output  << teams[i].p[j].name << " " << teams[i].p[j].age << endl;
    }
}
/**************************************************
 * Name: search_nat_players
 * Description: Searches for players by nationality and prints their names and ages.
 * Parameters:
 * - teams: An array of Team structures.
 * - tN: Total number of teams in the teams array.
 * - dp: Destination for printing (1 for console, 2 for an output file).
 * - output: An ofstream object used for writing to an output file if dp is set to 2.
 * Pre-conditions: The teams array is expected to be properly initialized with data.
 * Post-conditions: The function prints the names and ages of players with the specified nationality to the console or an output file, based on the dp parameter.
 ***********************************************/
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

/**************************************************
 * Name: print_sort
 * Description: Prints team names and their total points per game (PPG).
 * Parameters:
 * - teams: An array of Team structures.
 * - tN: Total number of teams in the teams array.
 * - dp: Destination for printing (1 for console, 2 for an output file).
 * - output: An ofstream object used for writing to an output file if dp is set to 2.
 * Pre-conditions: The teams array is expected to be properly initialized with data.
 * Post-conditions: The function prints team names and their total points per game (PPG) to the console or an output file, based on the dp parameter.
 ***********************************************/
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

/**************************************************
 * Name: sort_teams_ppg
 * Description: Sorts teams based on total points per game (PPG) and prints the sorted list.
 * Parameters:
 * - teams: An array of Team structures.
 * - tN: Total number of teams in the teams array.
 * - dp: Destination for printing (1 for console, 2 for an output file).
 * - output: An ofstream object used for writing to an output file if dp is set to 2.
 * Pre-conditions: The teams array is expected to be properly initialized with data.
 * Post-conditions: The function sorts the teams array based on total PPG and then calls print_sort to print the sorted list to the console or an output file, based on the dp parameter.
 ***********************************************/
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

int find_player(string name, Team * teams, int tN){//not h yet
    int fg;
    for (int i = 0; i < tN; i++)
    {
        for (int j = 0; j < teams[i].num_player; j++)
        {
            if (teams[i].p[j].name == name)
            {
                fg = (int)(teams[i].p[j].fg*100);
            }
        }
    }
    
    cout << fg << endl;
    return fg;
}

string get_name(Team * teams, int tN, int p){
    string name;
    while (true)
        {
            cout << endl << "Player" << p << " : "  << endl;
            cin >> name;
            bool exsit = false;
            // double ppg1 = find_player(pN, teams, tN);
            // if (ppg1!=-1)
            // {
            // score = game(ppg1);//game 1
            //     break;
            // }
            for (int i = 0; i < tN; i++)
            {
                for (int j = 0; j < teams[i].num_player; j++)
                {
                    if (teams[i].p[j].name == name)
                    {
                        exsit = true;
                    }
                }
            }
            if (exsit)
            {
                break;
            }
            cout << "enter again";
        }
    return name;
}

void game_run(Team * teams, int tN) { //not h yet
    welcome();//welcome part
        
        
        string p1N = get_name(teams, tN, 1);
        float p1P = find_player(p1N, teams, tN);
        int P1_score = game(p1P);

        string p2N = get_name(teams, tN, 2);
        float p2P = find_player(p2N, teams, tN);
        int P2_score = game(p2P);

        if (P1_score>P2_score)
        {
            cout << "The winner is " << p1N << ": " << P1_score << endl;
        } else if (P1_score<P2_score)
        {
            cout << "The winner is " << p2N << ": " << P2_score << endl;
        } else {
            cout << "Tie game!" << endl;
        }
}

void sim_game(Team * teams, int tN, int dp, ofstream & output){
    game_run(teams, tN);
}

/**************************************************
 * Name: run_prog
 * Description: A control function for the program that performs various operations.
 * Parameters:
 * - teams: An array of Team structures.
 * - tN: Total number of teams in the teams array.
 * - op: The selected operation (1 for search by team name, 2 for top scorers, 3 for search by nationality, 4 for sort by PPG, 5 for an unspecified operation).
 * Pre-conditions: The teams array is expected to be properly initialized with data.
 * Post-conditions: The function performs the selected operation by calling the appropriate functions and printing the results to the console or an output file based on user preferences. It returns the selected operation op.
 ***********************************************/
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
        sim_game(teams, tN, dp, output);
        break;
    default:
        // Handle other cases if needed.
        break;
    }

    return op;
}
