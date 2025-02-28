#ifndef ARMOR_H
#define ARMOR_H
#include "event.h"

//Bats Interface
class Armor : public Event
{
private:
public:
    Armor(/* args */);
    ~Armor();
    string print() override;
    void percert() override;
    string perform(int& hp) override;
};

#endif
