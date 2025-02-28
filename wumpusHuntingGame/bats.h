#ifndef BATS_H
#define BATS_H 
#include "event.h"

//Bats Interface
class Bats : public Event
{
private:
    /* data */
public:
    Bats(/* args */);
    ~Bats();
    string print() override;
    void percert() override;
    string perform(int& hp) override;
};

#endif
