#ifndef TP_H
#define TP_H 
#include "event.h"

//Bats Interface
class Tp : public Event
{
private:
public:
    Tp(string n);
    ~Tp();
    void set_name(const string n);
    string print() override;
    void percert() override;
    string perform(int& hp) override;
};

#endif