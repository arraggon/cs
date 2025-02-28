#include "room.h"

using namespace std;

//Room Implementation
Room::Room(){
    this->event = nullptr;
};

Room::~Room() {
    delete event; // Delete the dynamically allocated Event object
    event = nullptr; // Set the pointer to nullptr (optional but good practice)
}


// string Room::get_name() const{
//     return this->name;
// }

// void Room::set_name(const string& n){
//     this->name = n; 
// }
Event* Room::get_event() const{
    return this->event;
}

void Room::set_event(Event* e){
    this->event = e;
}
