#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //need to use 'const' when appropriate
    Menu() {
      this->num_coffee = 0;
      this->coffee_arr = NULL;
    }

    Menu(int size) {
      this->num_coffee = size;
      this->coffee_arr = new Coffee [size];
    }


    //big three
    ~Menu();
    Menu(const Menu&);
    Menu& operator = (const Menu&);

    int get_num_coffee() const;
    Coffee* get_coffee_arr() const;

    // Suggested functions:
    Coffee* search_coffee_by_name(string name); 
    void search_coffee_by_price(float budget); 
    void add_to_menu(Coffee& coffee_to_add); //add a coffee object into the Menu
    void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu

    // feel free to add more member functions

    void load_data();
    void print_data();
};

#endif