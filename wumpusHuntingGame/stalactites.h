#ifndef STALACTITES_H
#define STALACTITES_H 
#include "event.h"

//Stalactites Interface
class Stalactites : public Event
{
private:
    /* data */
public:
    Stalactites(/* args */);
    ~Stalactites();
    string print() override;
    void percert() override;
    string perform(int& hp) override;
};
#endif
