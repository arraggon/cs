#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
Wumpus::Wumpus()
{
    this->hp = 1;
}

Wumpus::~Wumpus()
{

}

string Wumpus::print()
{
    return "W";
}

void Wumpus::percert()
{
    cout << "You smell a terrible stench." << endl;
}

string Wumpus::perform(int& hp)
{
    return "wumpus";
}