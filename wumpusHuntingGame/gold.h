#ifndef GOLD_H
#define GOLD_H 
#include "event.h"

//Gold Interface
class Gold : public Event
{
private:
    /* data */
public:
    Gold(/* args */);
    ~Gold();
    string print() override;
    void percert() override;
    string perform(int& hp) override;
};
#endif