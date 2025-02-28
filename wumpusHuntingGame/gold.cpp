#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation
Gold::Gold(/* args */)
{
}

Gold::~Gold()
{
    delete this;
}

string Gold::print()
{
    return "G";
}

void Gold::percert()
{
    cout << "You see a glimmer nearby." << endl;
}

string Gold::perform(int& hp)
{
    return "gold";
    
}