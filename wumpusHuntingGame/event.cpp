#include "event.h"


using namespace std;

//Event Implementation
Event::Event()
{
    this->name = "";
    // this->hp = 0;
}

Event::Event(string name)
{
    this->name = name;
    // this->hp = hp;
}

string Event::get_name() const
{
    return this->name;
}

// int Event::get_hp() const{
//     return this->hp;
// }

void Event::set_name(string n)
{
    this->name = n;
}

// void Event::set_hp(int hp){
//     this->hp = hp;
// }

string Event::print()
{
    return "";
}

void Event::percert()
{
    
}

string Event::perform(int& hp)
{
    return "";
}