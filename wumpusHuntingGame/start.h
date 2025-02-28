#ifndef START_H
#define START_H 
#include "event.h"

//Bats Interface
class Start : public Event
{
private:
    /* data */
public:
    Start(/* args */);
    ~Start();
    string print() override;
    string perform(int& hp) override;
};

#endif