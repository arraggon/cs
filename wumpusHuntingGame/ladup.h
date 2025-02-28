#ifndef LADUP_H
#define LADUP_H 
#include "event.h"

//Bats Interface
class Ladup : public Event
{
private:
    /* data */
public:
    Ladup(/* args */);
    ~Ladup();
    string print() override;
    string perform(int& hp) override;
};

#endif