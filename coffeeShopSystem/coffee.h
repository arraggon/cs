#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Coffee {
  private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate
    
  
    Coffee(); //Coffee constructor 
    Coffee(string n, float s, float m, float l);


    string get_name() const;
    float get_small_cost () const;
    float get_medium_cost () const; 
    float get_large_cost () const;

    void set_name (const string);
    void set_small_cost(const float);
    void set_medium_cost(const float);
    void set_large_cost(const float);

    void print_coffee() const; //print the coffee object

    void load_data(ifstream& input);
};

#endif