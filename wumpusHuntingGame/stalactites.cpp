#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation
Stalactites::Stalactites(/* args */)
{
}

Stalactites::~Stalactites()
{
}

string Stalactites::print()
{
    return "S";
}

void Stalactites::percert()
{
    cout << "You hear water dripping." << endl;
}

string Stalactites::perform(int& hp)
{
    if (rand() % 2 == 0) //if 0, then die
    {
        return "stalactites";
    }
    return "";
}