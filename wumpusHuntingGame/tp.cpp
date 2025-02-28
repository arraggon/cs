#include "tp.h"

#include <iostream>

using namespace std;

//Bats Implementation

Tp::Tp(string n)
{
    this->name = n;
}

Tp::~Tp()
{

}

void Tp::percert(){
    cout << "You feel a breeze!" << endl;
}

void Tp::set_name(string n)
{
    this->name = n;
}

string Tp::print()
{
    return "H";
}

string Tp::perform(int& hp)
{
    // cout << "perform test at beginning!" << endl;
    return "tp";
}