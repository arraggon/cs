#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

#include <iostream>

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
    //test 
	// string name;
    Event* event;
public:
    Room();
    ~Room();
    // string get_name() const;
    Event* get_event() const;
    // void set_name(const string& n);
    void set_event(Event* e);
};

#endif