#include "coffee.h"

using namespace std;

/*********************************************************************
** Function: Coffee::Coffee()
** Description: Default constructor for the Coffee class.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Creates a Coffee object with empty name and zero costs.
*********************************************************************/
Coffee::Coffee(){
    this->name = "";
    this->small_cost = 0.0;
    this->medium_cost = 0.0;
    this->large_cost = 0.0;
}; //Coffee constructor 

/*********************************************************************
** Function: Coffee::Coffee(string n, float s, float m, float l)
** Description: Parameterized constructor for the Coffee class.
** Parameters: 
**              - n: name of the coffee
**              - s: cost of the small size
**              - m: cost of the medium size
**              - l: cost of the large size
** Pre-Conditions: None
** Post-Conditions: Creates a Coffee object with the specified attributes.
*********************************************************************/
Coffee::Coffee(string n, float s, float m, float l){
    this->name = n;
    this->small_cost = s;
    this->medium_cost = m;
    this->large_cost = l;
};

/*********************************************************************
** Function: string Coffee::get_name() const
** Description: Accessor function to get the name of the coffee.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the name of the coffee.
*********************************************************************/
string Coffee::get_name() const{
    return this->name;
}

/*********************************************************************
** Function: float Coffee::get_small_cost () const
** Description: Accessor function to get the cost of the small size.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the cost of the small size.
*********************************************************************/
float Coffee::get_small_cost () const{
    return this->small_cost;
}

/*********************************************************************
** Function: float Coffee::get_medium_cost () const
** Description: Accessor function to get the cost of the medium size.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the cost of the medium size.
*********************************************************************/
float Coffee::get_medium_cost () const{
    return this->medium_cost;
}

/*********************************************************************
** Function: float Coffee::get_large_cost () const
** Description: Accessor function to get the cost of the large size.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the cost of the large size.
*********************************************************************/
float Coffee::get_large_cost () const{
    return this->large_cost;
}

/*********************************************************************
** Function: void Coffee::set_name (string n)
** Description: Mutator function to set the name of the coffee.
** Parameters: 
**              - n: new name for the coffee
** Pre-Conditions: None
** Post-Conditions: Sets the name of the coffee.
*********************************************************************/
void Coffee::set_name (string n){
    this->name = n;
}

/*********************************************************************
** Function: void Coffee::set_small_cost(float s)
** Description: Mutator function to set the cost of the small size.
** Parameters: 
**              - s: new cost for the small size
** Pre-Conditions: None
** Post-Conditions: Sets the cost of the small size.
*********************************************************************/
void Coffee::set_small_cost(float s){
    this->small_cost = s;
}

/*********************************************************************
** Function: void Coffee::set_medium_cost(float m)
** Description: Mutator function to set the cost of the medium size.
** Parameters: 
**              - m: new cost for the medium size
** Pre-Conditions: None
** Post-Conditions: Sets the cost of the medium size.
*********************************************************************/
void Coffee::set_medium_cost(float m){
    this->medium_cost = m;
}

/*********************************************************************
** Function: void Coffee::set_large_cost(float l)
** Description: Mutator function to set the cost of the large size.
** Parameters: 
**              - l: new cost for the large size
** Pre-Conditions: None
** Post-Conditions: Sets the cost of the large size.
*********************************************************************/
void Coffee::set_large_cost(float l){
    this->large_cost = l;
}

/*********************************************************************
** Function: void Coffee::print_coffee() const
** Description: Prints the attributes of the Coffee object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Outputs the name and costs of the coffee.
*********************************************************************/
void Coffee::print_coffee() const{
    cout << "----------" << endl;
    cout << "name: " << this->name << endl;
    cout << "small cost: " << this->small_cost << endl;
    cout << "medium cost: " << this->medium_cost << endl;
    cout << "large cost: " << this->large_cost << endl;
} //print the coffee object

/*********************************************************************
** Function: void Coffee::load_data(ifstream& input)
** Description: Loads data from an input file stream into the Coffee object.
** Parameters: 
**              - input: input file stream
** Pre-Conditions: The file is open and formatted correctly.
** Post-Conditions: Reads data from the file and sets the attributes of the Coffee object.
*********************************************************************/
void Coffee::load_data(ifstream& input){
    input >> this->name >> this->small_cost >> this->medium_cost >> this->large_cost;
}
