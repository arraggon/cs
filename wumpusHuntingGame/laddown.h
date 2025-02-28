#ifndef LADDOWN_H
#define LADDOWN_H 
#include "event.h"

//Bats Interface
class Laddown : public Event
{
private:
    /* data */
public:
    Laddown(/* args */);
    ~Laddown();
    string print() override;
    string perform(int& hp) override;
};

#endif