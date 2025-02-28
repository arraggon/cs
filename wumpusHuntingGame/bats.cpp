#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation

Bats::Bats(/* args */)
{
}

Bats::~Bats()
{
}

string Bats::print()
{
    return "B";
}

void Bats::percert()
{
    cout << "You hear wings flapping." << endl;
}

string Bats::perform(int& hp)
{
    return "bat";
}