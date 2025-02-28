#include <iostream>
#include <fstream>
#include "catalog.h"

using namespace std;

//function definitions go here

void set_up(){
    cout << "set up" << endl;
}

Team* create_teams(int teams_num)
{
    Team * teams = new Team[teams_num];
    return teams;
}

void populate_team_data(Team*, int, ifstream & )
{

}

Player* create_players(int players_num)
{
    Player * players = new Player[players_num];
    return players;
}

void populate_players_data(Player* players, int num, ifstream & )
{

}



void delete_info(Team*, int)
{

}

