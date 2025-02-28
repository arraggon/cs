#include "game.h"

#include <iostream>

using namespace std;

//Game Implementation

Game::Game()
{
	//Game constructor
	//Your code here:
}

Game::~Game()
{
	//Game destructor
	//Your code here:
}

void Game::insert_level(){//event for each floor
	//2 bat, 2 sta, up, down
// Looping through elements
	for (int k = 0; k < this->level; k++)
	{
// Looping through elements
		for (int e = 0; e < 8; e++)
		{
			int x, y;
			do
			{
				x = rand() % this->length;
				y = rand() % this->width;
// While loop for repeated checks
			} while (this->rooms[x][y][k].get_event() != nullptr);

// Switch statement for multiple cases
			switch (e)
			{
			case 0:
				this->rooms[x][y][k].set_event(new Bats());
				break;
			case 1:
				this->rooms[x][y][k].set_event(new Bats());
				break;
			case 2:
				this->rooms[x][y][k].set_event(new Stalactites());
				break;
			case 3:
				this->rooms[x][y][k].set_event(new Stalactites());
				break;
			case 4:
// Conditional check
				if (k!=level-1)
				{
					this->rooms[x][y][k].set_event(new Ladup());
				}
				break;
			case 5:
// Conditional check
				if (k != 0)
				{
					this->rooms[x][y][k].set_event(new Laddown());
				}
				break;
			case 6:
				this->rooms[x][y][k].set_event(new Tp("t1"));
				break;
			case 7:
				this->rooms[x][y][k].set_event(new Tp("t2"));
				break;
			}
		}
	}
}

void Game::insert_events(vector < vector < vector < Room > > >& r)
{
	int x, y, z;
// Looping through elements
	for (int i = 0; i < 4; i++)
	{
		do
		{
			x = rand() % this->length;
			y = rand() % this->width;
			z = rand() % this->level;
// While loop for repeated checks
		} while (this->rooms[x][y][z].get_event() != nullptr);
		// only!! ---- start, armor, gold, wumpus, 4
// Switch statement for multiple cases
		switch (i)
		{
		case 0:
			this->rooms[x][y][z].set_event(new Start());
			this->pX = x, this->pY = y; this->pZ = z;
			break;
		case 1:
			this->rooms[x][y][z].set_event(new Gold());
			break;
		case 2:
			this->rooms[x][y][z].set_event(new Armor());
			break;
		case 3:
			this->rooms[x][y][z].set_event(new Wumpus());
			break;
		}
	}
	insert_level();
}

void Game::set_up(int w, int l, int h)
{
	//set up the game
	this->length = l;
	this->width = w;
	this->level = h;

	this->num_arrows = 3; 	//start with 3 arrows

	// Finish the remaining...
	//Your code here:
	
	// Create the game board: 2D vector of Room objects
	this->rooms = this->rooms = vector<vector<vector<Room>>>(length, vector<vector<Room>>(width, vector<Room>(level)));
	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
	// rooms[0][4].set_name("T");
	Game::insert_events(this->rooms);
}

//Note: you need to modify this function
void Game::display_game() const
{
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
// Looping through elements
	for (int i = 0; i < this->width; ++i)
		line += "-----";

// Looping through elements
	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
// Looping through elements
		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "

			//else, print "*"
			
			//Fix the following
			
			((pX == i)&&(pY == j)) ? cout << "*" : cout << " "; // display player
			
			
			
// Conditional check
			if ((debug_view) && (this->rooms[i][j][pZ].get_event() != nullptr)) {  // Check if the event is not null
				cout << this->rooms[i][j][pZ].get_event()->print();

			} else {
				if ((this->rooms[i][j][pZ].get_event() != nullptr)&&((this->rooms[i][j][pZ].get_event()->print()=="^")||(this->rooms[i][j][pZ].get_event()->print()=="V")))
				{
					cout << this->rooms[i][j][pZ].get_event()->print();
				}
				
				cout << " ";  // Or handle the no-event case appropriately
			}
			
			//test
			// cout << this->rooms[i][j].get_event()->get_name();

			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			
			//else, 
				//if debug_view is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			//Fix the following...
			cout << " ||";
		}
		cout << endl;
	}
	cout << line << endl;
	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}

// Function: Game::hidden_passage - [Describe the functionality of Game::hidden_passage]
void Game::hidden_passage(){
	string p = rooms[pX][pY][pZ].get_event()->get_name();
// Looping through elements
	for (int i = 0; i < length; i++)
	{
// Looping through elements
		for (int j = 0; j < width; j++)
		{
// Conditional check
			if ((rooms[i][j][pZ].get_event()!=nullptr)&&(rooms[i][j][pZ].get_event()->print()=="H")&&(rooms[i][j][pZ].get_event()->get_name()!= p))
			{	
				pX = i;
				pY = j;
// Return statement
				return;
			}
		}
	}
}

// Function: Game::extra_check_event - [Describe the functionality of Game::extra_check_event]
void Game::extra_check_event(string r){
// Conditional check
	if (r == "armor")
	{
		cout << "hp :" << hp << endl;
		// Delete the existing event object to prevent memory leak
        delete this->rooms[pX][pY][pZ].get_event();

        // Now set the event to nullptr
        this->rooms[pX][pY][pZ].set_event(nullptr); 

        // Player has collected the gold
	}
// Conditional check
	if (r == "ladup")
	{
		cout << "Ladder up!" << endl;
		// lad_up();
		pZ++;
	}
// Conditional check
	if (r == "laddown")
	{
		cout << "Ladder down!" << endl;
		// lad_down();
		pZ--;
	}
// Conditional check
	if (r == "tp")
	{
		cout << "Hidden passage event!" << endl;
		hidden_passage();
	}
	
}

void Game::check_event(string r)
{
// Conditional check
    if (r == "gold") // if entered the gold room
    {
        // Delete the existing event object to prevent memory leak
        delete this->rooms[pX][pY][pZ].get_event();

        // Now set the event to nullptr
        this->rooms[pX][pY][pZ].set_event(nullptr); 

        // Player has collected the gold
        this->gold = true;
    } 
// Conditional check
	if ((r=="start")&&(this->gold))
	{
		this->start = true;
	}
// Conditional check
	if (r == "bat")
	{
		cout << "Superbat make u lost!" << endl;
		this->batDebuff = 5;
	}
// Conditional check
	if (r == "wumpus")
	{
		cout << "WUMPUS attack!" << endl;
		this->hp--;
	}
// Conditional check
	if (r == "stalactites")
	{
		cout << "Stalactites fall!" << endl;
		this->hp--;
	}
	extra_check_event(r);
}

bool Game::check_win(int hp) const
{
	//check if game over/win
	//Your code here:

	// cout << "Game::check_win() is not implemented..." << endl;

	// return false;
// Conditional check
	if (this->hp > 0)
	{
// Conditional check
		if (start)
		{
			Game::display_game();
			cout << "WIN by got gold!" << endl;
// Return statement
			return true;
		}
// Conditional check
		if (boss)
		{

			Game::display_game();
			cout << "WIN by killed the boss!" << endl;
// Return statement
			return true;
		}
		
		
// Return statement
		return false;
	} else {
		cout << "You Dead, Game over T_T ~" << endl;
		Game::display_game();
// Return statement
		return true;
	}
	
}

void Game::move_up()
{
	//move player up
	//Your code here:

	// cout << "Game::move_up() is not implemented..." << endl;
	// return;
	
// Conditional check
	if (this->batDebuff == 0)
	{
// Conditional check
		if (this->pX > 0)
		{
			this->pX--;
		}
	} 
	else
	{
// Conditional check
		if (this->pX < this->length-1)
		{
			this->pX++;
			this->batDebuff--;
		}
	}
	
	
}

void Game::move_down()
{
	//move player down
	//Your code here:

	// cout << "Game::move_down() is not implemented..." << endl;
	// return;
// Conditional check
	if (this->batDebuff == 0)
	{
// Conditional check
		if (this->pX < this->length-1)
		{
			this->pX++;
		}
	} 
	else
	{
// Conditional check
		if (this->pX > 0)
		{
			this->pX--;
			this->batDebuff--;
		}
	}
}

void Game::move_left()
{
	//move player left
	//Your code here:

	// cout << "Game::move_left() is not implemented..." << endl;
	// return;
// Conditional check
	if (this->batDebuff == 0)
	{
// Conditional check
		if (this->pY > 0)
		{
			this->pY--;
		}
	} 
	else
	{
// Conditional check
		if (this->pY < width-1)
		{
			this->pY++;
			this->batDebuff--;
		}
	}
}

void Game::move_right()
{
	//move player right
	//Your code here:

	// cout << "Game::move_right() is not implemented..." << endl;
	// return;
// Conditional check
	if (this->batDebuff == 0)
	{
// Conditional check
		if (this->pY < width-1)
		{
			this->pY++;
		}
	} 
	else
	{
// Conditional check
		if (this->pY > 0)
		{
			this->pY--;
			this->batDebuff--;
		}
	}
}

char Game::get_dir()
{
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');
// Conditional check
	if ((dir=='w')||(dir=='s')||(dir == 'a')||(dir == 'd'))
	{
		this->num_arrows--;
	}
// Return statement
	return dir;
}

void Game::wumpus_move()
{
	//after a missed arrow, 75% chance that the wumpus is moved to a different room
// Conditional check
	if ((rand() % 100) < 75)
	{
		int x, y, z;
		do
		{
			x = rand() % this->length;
			y = rand() % this->width;
			z = rand() % this->level;
// While loop for repeated checks
		} while (this->rooms[x][y][z].get_event() != nullptr);

		this->rooms[x][y][z].set_event(new Wumpus());

// Looping through elements
		for (int k = 0; k < this->level; k++)
		{
// Looping through elements
			for (int i = 0; i < this->length; i++)
			{
// Looping through elements
				for (int j = 0; j < this->width; j++)
				{
					
// Conditional check
					if ((this->rooms[i][j][k].get_event()!=nullptr)&&(this->rooms[i][j][k].get_event()->print() == "W")&&((i!=x)||(j!=y)||(k!=z)))
					{
						delete this->rooms[i][j][k].get_event();
						this->rooms[i][j][k].set_event(nullptr);
					}
				}
			}
		}
	}
}

// Function: Game::kill_w - [Describe the functionality of Game::kill_w]
void Game::kill_w(int x, int y, int z){
	this->boss = true;
	// Delete the existing event object to prevent memory leak
    delete this->rooms[x][y][z].get_event();
    // Now set the event to nullptr
    this->rooms[x][y][z].set_event(nullptr);
}

void Game::fire_arrow()
{
	// The player may fire arrow...
	char dir = get_dir();
	//Your code here:
// Switch statement for multiple cases
	switch (dir)
	{
	case 'w':
// Looping through elements
		for (int i = 0; (pX-i>0)&&(i < 3); i++)
		{
// Conditional check
			if ((this->rooms[pX-1-i][pY][pZ].get_event() != nullptr)&&(this->rooms[pX-1-i][pY][pZ].get_event()->print() == "W"))
			{
				Game::kill_w(pX-1-i, pY, pZ);
			}
		}
		break;
// Conditional check
		// if (this->pX < this->length-1)
		// {
		// 	this->pX++;
		// }
	case 's':
// Looping through elements
		for (int i = 0; (pX+i<length-1)&&(i < 3); i++)
		{
// Conditional check
			if ((this->rooms[pX+1+i][pY][pZ].get_event() != nullptr)&&(this->rooms[pX+1+i][pY][pZ].get_event()->print() == "W"))
			{
				Game::kill_w(pX+1+i, pY, pZ);
			}
		}
		break;
	case 'a':
// Looping through elements
		for (int i = 0; (pY-i>0)&&(i < 3); i++)
		{
// Conditional check
			if ((this->rooms[pX][pY-1-i][pZ].get_event() != nullptr)&&(this->rooms[pX][pY-1-i][pZ].get_event()->print() == "W"))
			{
				Game::kill_w(pX, pY-1-i, pZ);
			}
		}
		break;
	case 'd':
// Looping through elements
		for (int i = 0; (pY+i<width-1)&&(i < 3); i++)
		{
// Conditional check
			if ((this->rooms[pX][pY+1+i][pZ].get_event() != nullptr)&&(this->rooms[pX][pY+1+i][pZ].get_event()->print() == "W"))
			{
				Game::kill_w(pX, pY+1+i, pZ);
			}
		}
		break;
	}
}

void Game::move(char c)
{
	// Handle player's action: move or fire an arrow
// Function: if - [Describe the functionality of if]
// Conditional check
	if ((c == 'f')&&(this->num_arrows>0)){
		Game::fire_arrow();
// Conditional check
		if (!boss)
		{
			wumpus_move();
		}
		
// Return statement
		return;
	}
	
// Function: switch - [Describe the functionality of switch]
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}

// Function: Game::get_input - [Describe the functionality of Game::get_input]
char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;
	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;
    // printw("\n\nPlayer move...\n");
    // printw("W - up\n");
    // printw("A - left\n");
    // printw("S - down\n");
    // printw("D - right\n");
    // printw("F - fire an arrow\n");

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');


    // Get a single character input
    // char c = getch();
// Return statement
	return c;
}

void Game::percerts()
{
	// this->rooms[0][0].get_event()->percert();
	//up
// Conditional check
	if ((pX > 0)&&(this->rooms[this->pX-1][this->pY][pZ].get_event() != nullptr)) // if the room is not empty
	{
		this->rooms[this->pX-1][this->pY][pZ].get_event()->percert(); // then display the warning
	}
	//down
// Conditional check
	if ((pX < this->length-1)&&(this->rooms[this->pX+1][this->pY][pZ].get_event() != nullptr)) // if the room is not empty
	{
		this->rooms[this->pX+1][this->pY][pZ].get_event()->percert(); // then display the warning
	}
	//left
// Conditional check
	if ((pY > 0) && (this->rooms[this->pX][this->pY-1][pZ].get_event() != nullptr)) // if the room is not empty
	{
		this->rooms[this->pX][this->pY-1][pZ].get_event()->percert(); // then display the warning
	}
	//right
// Conditional check
	if ((pY < this->width-1) && (this->rooms[this->pX][this->pY+1][pZ].get_event() != nullptr)) // if the room is not empty
	{
		this->rooms[this->pX][this->pY+1][pZ].get_event()->percert(); // then display the warning
	}
	
}




//Note: you need to modify this function
void Game::play_game(int w, int l, int h, bool d)
{
	Game::set_up(w, l, h);
	this->debug_view = d;

	char input, arrow_input;
	
// Function: while - [Describe the functionality of while]
// While loop for repeated checks
	while (Game::check_win(this->hp) == false){

		//print game board
		Game::display_game();


		//display percerts around player's location
		//Your code here:
		Game::percerts();
		//Player move...
		//1. get input
		input = Game::get_input();
		//2. move player
		
		cout << endl << endl << "----------" << endl;

		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
// Conditional check
		if (this->rooms[pX][pY][pZ].get_event()!=nullptr) // if there is a event
		{
			check_event(this->rooms[pX][pY][pZ].get_event()->perform(this->hp)); // 
		}
	}
// Return statement
	return;

}