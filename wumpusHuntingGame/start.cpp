#include "start.h"

#include <iostream>

using namespace std;

//Bats Implementation

Start::Start(/* args */)
{
    this->name = "start";
}

Start::~Start()
{
}

string Start::print()
{
    return "O";
}

string Start::perform(int& hp)
{
    // cout << "perform test at beginning!" << endl;
    return "start";
}