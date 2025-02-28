#include "order.h"

using namespace std;


//function defintions from order.h goes here

/*********************************************************************
** Function: Order (Default Constructor)
** Description: Default constructor for the Order class.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Initializes an Order object with default values.
*********************************************************************/
Order::Order(){
    this->id = 0;
    this->coffee_name = " ";
    this->coffee_size = ' ';
    this->quantity = 0;
};

/*********************************************************************
** Function: Order (Parameterized Constructor)
** Description: Parameterized constructor for the Order class.
** Parameters: int id - Order ID, string n - Coffee name, char s - Coffee size, int q - Quantity.
** Pre-Conditions: None
** Post-Conditions: Initializes an Order object with provided values.
*********************************************************************/
Order::Order(int id, string n, char s, int q)
{
    this->id = id;
    this->coffee_name = n;
    this->coffee_size = s;
    this->quantity = q;
}

/*********************************************************************
** Function: get_id
** Description: Getter function for the Order ID.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the Order ID.
*********************************************************************/
int Order::get_id() const{
    return this->id;
}

/*********************************************************************
** Function: get_coffee_name
** Description: Getter function for the coffee name.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the coffee name.
*********************************************************************/
string Order::get_coffee_name() const{
    return this->coffee_name;
}

/*********************************************************************
** Function: get_coffee_size
** Description: Getter function for the coffee size.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the coffee size.
*********************************************************************/
char Order::get_coffee_size() const{
    return this->coffee_size;
}

/*********************************************************************
** Function: get_quantity
** Description: Getter function for the quantity.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the quantity.
*********************************************************************/
int Order::get_quantity() const{
    return this->quantity;
}

/*********************************************************************
** Function: calculate_order_cost
** Description: Calculates the cost of the order based on the Menu.
** Parameters: Menu& m - Reference to the Menu object.
** Pre-Conditions: None
** Post-Conditions: Returns the calculated cost of the order.
*********************************************************************/
float Order::calculate_order_cost(Menu& m){
    Coffee* result = m.search_coffee_by_name(this->coffee_name);
    float cost;
    if (this->coffee_size == 's')
    {
        cost = result->get_small_cost() * quantity;
    } else if (this->coffee_size == 'm')
    {
        cost = result->get_medium_cost() * quantity;
    } else if (this->coffee_size == 'l')
    {
        cost = result->get_large_cost() * quantity;
    }
    return cost;
}

/*********************************************************************
** Function: print_data
** Description: Prints the details of the order.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Prints the order details.
*********************************************************************/
void Order::print_data(){
    cout << this->id << " ";
    cout << this->coffee_name << " ";
    cout << this->coffee_size << " ";
    cout << this->quantity << endl;
}
