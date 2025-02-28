
#ifndef EVENT_H
#define EVENT_H 

#include <iostream>
#include <string>

using namespace std;

class Event {
protected:
    string name;  // Name of the event

public:
    /*********************************************************************
    ** Function: Event
    ** Description: Default constructor for Event class.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Event object is created with default values.
    *********************************************************************/
    Event();

    /*********************************************************************
    ** Function: Event (Overloaded Constructor)
    ** Description: Overloaded constructor for Event class.
    ** Parameters: string name - Name for the event.
    ** Pre-Conditions: None
    ** Post-Conditions: Event object is created with the given name.
    *********************************************************************/
    Event(string name);

    /*********************************************************************
    ** Function: get_name
    ** Description: Gets the name of the event.
    ** Parameters: None
    ** Pre-Conditions: Event object exists.
    ** Post-Conditions: Returns the name of the event.
    *********************************************************************/
    string get_name() const;

    /*********************************************************************
    ** Function: set_name
    ** Description: Sets the name of the event.
    ** Parameters: const string name - New name for the event.
    ** Pre-Conditions: Event object exists.
    ** Post-Conditions: The name of the event is updated.
    *********************************************************************/
    void set_name(const string name);

    // Virtual functions to be overridden by derived classes
    virtual string print();
    virtual void percert();
    virtual string perform(int& hp);
};

#endif
