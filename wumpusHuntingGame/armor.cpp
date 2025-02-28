#include "armor.h"

#include <iostream>

using namespace std;

//Armor Implementation

Armor::Armor(/* args */)
{
}

Armor::~Armor()
{
}

string Armor::print()
{
    return "A";
}

void Armor::percert()
{
    cout << "You see a glimmer nearby." << endl;
}

string Armor::perform(int& hp)
{
    hp+=2;
    return "armor";
}