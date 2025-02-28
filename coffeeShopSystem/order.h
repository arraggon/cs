#ifndef ORDER_H
#define ORDER_H 

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	//need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

	Order();
	Order(int id, string n, char s, int q);

	int get_id() const;
	string get_coffee_name() const;
	char get_coffee_size() const;
	int get_quantity() const;

	
	void print_orders();

	// void load_data(ifstream& input);
	float calculate_order_cost(Menu& m);
	void print_data();
};
#endif