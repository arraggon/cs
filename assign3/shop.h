#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate
    Shop() {
      // this->m = NULL;
      this->phone = "";
      this->address = "";
      this->revenue = 0.0;
      this->order_arr = NULL;
      this->num_orders = 0;
    }

    //big three
    ~Shop();
    Shop(const Shop&);
    Shop& operator = (const Shop&);

    //Suggested functions
    void load_data(); //reads from files to correctly populate coffee, menu, etc.
    void view_shop_detail();

    bool check_new_item(string n, float s, float m, float l);
    
    // Menu add_new_item(Menu& old, int num_coffee, string n, float s, float m, float l);
    void write_new_menu(Menu& m);
    void write_new_orders(Order* o);
    void add_to_menu();
    void remove_from_menu();
    void search_by_name();
    
    void search_by_price();
    
    float calculate_cost(int choice, char size, int quantity);
    void add_new_order(int choice, char size, int quantity, float cost);
    void comfirm(string cf, int choice, char size, int quantity, float cost);
    void con_place(int choice, char size, int q);
    void place_order();
    Shop clone_shop();
    //-----------------------------
    int compare(int& q, int s, int m, int l, string& size);
    void best_seller();

    void sortFloatArrayDescending(float sell[], Coffee c[],int size);
    void top_3_popular();
    

};

#endif
