#ifndef WUMPUS_H
#define WUMPUS_H 
#include "event.h"

//Wumpus Interface
class Wumpus : public Event
{
private:
    int hp;
public:
    Wumpus();
    ~Wumpus();
    string print() override;
    void percert() override;
    string perform(int& hp) override;
};

#endif