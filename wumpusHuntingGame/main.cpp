/*********************************************************************
** Program Filename: hunt wumpus
** Author: Dongwen Yang
** Date: Nov. 28th
** Description: get the gold and leave safe or kill the wumpus
** Input: width, length, height
** Output: game
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"


using namespace std;

int get_wid(){ // get wid
	int wid;
	cout << "Width: ";
	cin >> wid;
	while (wid<4)
	{
    	cout << "Width can not smaller than 4 \nEnter width again: ";//make sure is positive
		cin >> wid;
	}
	return wid;
}

int get_len(){
	int len;
	cout << "length: ";// get length
	cin >> len;
	while (len<4)
	{
    	cout << "Length can not smaller than 4 \nEnter length again: ";//make sure is positive
		cin >> len;
	}
	return len;
}

int get_lv(){
	int lv;
	cout << "level: ";// get length
	cin >> lv;
	while (lv<=0)
	{
    	cout << "Enter level again: ";//make sure is positive
		cin >> lv;
	}
	return lv;
}

bool get_debug(){// cheating mode
	bool d;
	string dc;
	do
	{
		cout << "Enter 0 for normal mode, 1 for cheating mode: ";
    	cin >> dc;
	} while ((dc != "1")&&(dc != "0"));
	
	if (dc == "1")
	{
		d = true;
	} else {
		dc = false;
	}
	
	return d;
}

bool replay(){
	string c;
	do
	{	
		cout << "enter 1 for play again \nenter 0 for quit" << endl;
		cin >> c;
	} while ((c != "1")&&(c != "0"));
	if (c == "0")
	{
		return false;
	} else {
		return true;
	}
	
}

int main()
{
	// Event e;
	// Wumpus w;
    // Bats b;
    // Stalactites s;
    // Gold g1;
	// Start s1;

    // cout << "-----" << e.print() << "-----" << endl;
    // cout << "-----" << w.print() << "-----" << endl;
    // cout << "-----" << b.print() << "-----" << endl;
    // cout << "-----" << s.print() << "-----" << endl;
    // cout << "-----" << g1.print() << "-----" << endl;
    // cout << "-----" << s1.print() << "-----" << endl;
	
	srand(time(NULL));
	
	int wid = 8, len = 5, lv = 4;
	bool debug = true;
	while (true)
	{
			
			//get two inputs: size of the cave(wid and len)
			wid = get_wid();
			len = get_len();
			lv = get_lv();
		
			//get the 3rd input --> debug mode or not
			debug = get_debug();
		
		Game g;
		//Play game

		g.play_game(wid, len, lv, debug);
		if (!replay())
		{
			break;
		}
	}
	return 0;
}