#include "laddown.h"

#include <iostream>

using namespace std;

//Bats Implementation

Laddown::Laddown(/* args */)
{
    this->name = "Laddown";
}

Laddown::~Laddown()
{
}

string Laddown::print()
{
    return "V";
}

string Laddown::perform(int& hp)
{
    // cout << "perform test at beginning!" << endl;
    return "laddown";
}