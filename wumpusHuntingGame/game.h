#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream>

#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "bats.h"
#include "gold.h"
#include "stalactites.h"
#include "start.h"
#include "armor.h"
#include "ladup.h"
#include "laddown.h"
#include "tp.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:

	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board

	int level;

	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not

	//feel free to add more variables...
	
	//inital players  info
	int hp = 1;
	bool gold = false;
	bool start = false;
	bool boss = false;

	int batDebuff = 0;

	vector < vector < vector < Room > > > rooms; // rooms

	int pX, pY, pZ; // player's positon
	
public:

	//suggested functions:

	/*********************************************************************
** Function: Game
** Description: Constructor to initialize a Game object with default settings.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: A Game object is created with default initial values.
*********************************************************************/

Game();

/*********************************************************************
** Function: ~Game
** Description: Destructor to deallocate memory and clean up resources.
** Parameters: none
** Pre-Conditions: Game object exists
** Post-Conditions: Game object is properly destroyed and resources are freed.
*********************************************************************/

~Game();

/*********************************************************************
** Function: insert_level
** Description: Inserts a new level into the game.
** Parameters: none
** Pre-Conditions: Game object is initialized
** Post-Conditions: A new level is added to the game.
*********************************************************************/

void insert_level();

/*********************************************************************
** Function: insert_events
** Description: Inserts events into the specified rooms of the game.
** Parameters: vector<vector<vector<Room>>>& rooms - Reference to a 3D vector of Room objects where events will be inserted.
** Pre-Conditions: Rooms are initialized
** Post-Conditions: Events are inserted into the specified rooms.
*********************************************************************/

void insert_events(vector<vector<vector<Room>>>& rooms);

/*********************************************************************
** Function: set_up
** Description: Sets up the game with specified dimensions and level.
** Parameters: int l - Length of the game board, int w - Width of the game board, int lvl - Level of the game.
** Pre-Conditions: none
** Post-Conditions: Game is set up with given dimensions and level.
*********************************************************************/

void set_up(int l, int w, int lvl);

/*********************************************************************
** Function: display_game
** Description: Displays the current state of the game board.
** Parameters: none
** Pre-Conditions: Game is initialized and in progress
** Post-Conditions: Current state of the game is displayed to the user.
*********************************************************************/

void display_game() const;

/*********************************************************************
** Function: check_win
** Description: Checks if the winning conditions of the game are met.
** Parameters: int hp - The current hit points of the player.
** Pre-Conditions: Game is in progress
** Post-Conditions: Returns true if winning conditions are met, false otherwise.
*********************************************************************/

bool check_win(int hp) const;

/*********************************************************************
** Function: get_dir
** Description: Gets the direction of movement from the player.
** Parameters: none
** Pre-Conditions: Game is in progress
** Post-Conditions: Returns the character indicating the direction of movement.
*********************************************************************/

char get_dir();

/*********************************************************************
** Function: wumpus_move
** Description: Moves the Wumpus in the game.
** Parameters: none
** Pre-Conditions: Game is in progress and Wumpus is in the game
** Post-Conditions: Wumpus is moved to a new location.
*********************************************************************/

void wumpus_move();

/*********************************************************************
** Function: kill_w
** Description: Kills the Wumpus at the specified location.
** Parameters: int x, int y, int z - Coordinates of the Wumpus's location.
** Pre-Conditions: Game is in progress and Wumpus is at the specified location
** Post-Conditions: Wumpus at the given location is killed.
*********************************************************************/

void kill_w(int x, int y, int z);

/*********************************************************************
** Function: fire_arrow
** Description: Fires an arrow in the game.
** Parameters: none
** Pre-Conditions: Game is in progress and player has arrows
** Post-Conditions: An arrow is fired, potentially affecting the game state.
*********************************************************************/

void fire_arrow();

/*********************************************************************
** Function: move_up
** Description: Moves the player up in the game world.
** Parameters: none
** Pre-Conditions: Game is in progress
** Post-Conditions: Player's position is updated to one unit up.
*********************************************************************/

void move_up();

/*********************************************************************
** Function: move_down
** Description: Moves the player down in the game world.
** Parameters: none
** Pre-Conditions: Game is in progress
** Post-Conditions: Player's position is updated to one unit down.
*********************************************************************/

void move_down();

/*********************************************************************
** Function: move_left
** Description: Moves the player left in the game world.
** Parameters: none
** Pre-Conditions: Game is in progress
** Post-Conditions: Player's position is updated to one unit left.
*********************************************************************/

void move_left();

/*********************************************************************
** Function: move_right
** Description: Moves the player right in the game world.
** Parameters: none
** Pre-Conditions: Game is in progress
** Post-Conditions: Player's position is updated to one unit right.
*********************************************************************/

void move_right();

/*********************************************************************
** Function: move
** Description: Moves the player in the specified direction.
** Parameters: char dir - Direction in which the player is to move.
** Pre-Conditions: Game is in progress
** Post-Conditions: Player's position is updated in the specified direction.
*********************************************************************/

void move(char dir);

/*********************************************************************
** Function: get_input
** Description: Gets input from the player.
** Parameters: none
** Pre-Conditions: Game is in progress
** Post-Conditions: Returns the input received from the player.
*********************************************************************/

char get_input();

/*********************************************************************
** Function: percerts
** Description: Handles the perception events in the game.
** Parameters: none
** Pre-Conditions: Game is in progress
** Post-Conditions: Perception events are processed.
*********************************************************************/

void percerts();

/*********************************************************************
** Function: hidden_passage
** Description: Reveals or interacts with hidden passages in the game.
** Parameters: none
** Pre-Conditions: Game is in progress
** Post-Conditions: Hidden passages are processed in the game.
*********************************************************************/

void hidden_passage();

/*********************************************************************
** Function: extra_check_event
** Description: Checks for additional events based on a specific condition.
** Parameters: string r - The condition to check for events.
** Pre-Conditions: Game is in progress
** Post-Conditions: Additional events are processed based on the condition.
*********************************************************************/

void extra_check_event(string r);

/*********************************************************************
** Function: check_event
** Description: Checks for events based on the game state.
** Parameters: string res - The result or state to check for events.
** Pre-Conditions: Game is in progress
** Post-Conditions: Events are processed based on the game state.
*********************************************************************/

void check_event(string res);

/*********************************************************************
** Function: play_game
** Description: Starts and runs the main game loop.
** Parameters: int l - Length of the game board, int w - Width of the game board, int lvl - Level of the game, bool debug - Indicates whether debug mode is on.
** Pre-Conditions: Game is initialized
** Post-Conditions: Game is played based on specified parameters.
*********************************************************************/

void play_game(int l, int w, int lvl, bool debug);


	//feel free (and you will need) to add more functions...
};
#endif