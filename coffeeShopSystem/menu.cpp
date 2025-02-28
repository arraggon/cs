#include "menu.h"

using namespace std;

//function defintions from menu.h goes here


//big three
/*********************************************************************
** Function: ~Menu
** Description: Destructor for the Menu class.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Deallocates memory for the coffee_arr array.
*********************************************************************/
Menu::~Menu(){
    cout << "D" << endl;
    if (this->coffee_arr != NULL) {
        delete [] this->coffee_arr;
        this->coffee_arr = NULL;
    }
}

/*********************************************************************
** Function: Menu (Copy Constructor)
** Description: Copy constructor for the Menu class.
** Parameters: const Menu& m - Reference to the Menu object to be copied.
** Pre-Conditions: None
** Post-Conditions: Creates a deep copy of the Menu object.
*********************************************************************/
Menu::Menu(const Menu& m){
    
    cout << "CC" << endl;
    this->num_coffee = m.num_coffee;
    this->coffee_arr = new Coffee [this->num_coffee];
    for (int i = 0; i < this->num_coffee; i++)
    {
        this->coffee_arr[i] = m.coffee_arr[i];
    }
}

/*********************************************************************
** Function: operator= (Assignment Operator Overload)
** Description: Assignment operator overload for the Menu class.
** Parameters: const Menu& m - Reference to the Menu object to be assigned.
** Pre-Conditions: None
** Post-Conditions: Creates a deep copy of the Menu object.
*********************************************************************/
Menu& Menu::operator = (const Menu& m){
    cout << "AOO" << endl;
    if (this == &m)
    {
        return *this;
    }
    if (this->coffee_arr !=NULL)
    {
        delete [] this->coffee_arr;
    }
    this->num_coffee = m.num_coffee;
    this->coffee_arr = new Coffee [this->num_coffee];
    for (int i = 0; i < this->num_coffee; i++)
    {
        this->coffee_arr[i] = m.coffee_arr[i];
    }
    return *this;
}

/*********************************************************************
** Function: get_num_coffee
** Description: Getter function for the number of coffee items in the menu.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the number of coffee items.
*********************************************************************/
int Menu::get_num_coffee() const{
    return this->num_coffee;
}

/*********************************************************************
** Function: get_coffee_arr
** Description: Getter function for the coffee_arr array.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns a pointer to the coffee_arr array.
*********************************************************************/
Coffee* Menu::get_coffee_arr() const{
    return this->coffee_arr;
}

/*********************************************************************
** Function: search_coffee_by_name
** Description: Searches for a coffee item by name.
** Parameters: string name - Name of the coffee to be searched.
** Pre-Conditions: None
** Post-Conditions: Returns a pointer to the found coffee item or NULL if not found.
*********************************************************************/
Coffee* Menu::search_coffee_by_name(string name) {
    Coffee* found = NULL;
    for (int i = 0; i < num_coffee; i++)
    {
        if (coffee_arr[i].get_name() == name)
        {
            found = &coffee_arr[i];
        }
    }
    return found;
}

/*********************************************************************
** Function: search_coffee_by_price
** Description: Searches for coffee items under a specific budget.
** Parameters: float budget - Budget for the search.
** Pre-Conditions: None
** Post-Conditions: Prints the details of coffee items under the budget.
*********************************************************************/
void Menu::search_coffee_by_price(float budget){
    for (int i = 0; i < this->num_coffee; i++)
    {
        if (this->coffee_arr[i].get_small_cost() <= budget)
        {
            cout << i+1 << ". " << this->coffee_arr[i].get_name() << endl;
            cout << "   Small – " << this->coffee_arr[i].get_small_cost() << endl;

            if (this->coffee_arr[i].get_medium_cost() <= budget)
            {
                cout << "   Medium – " << this->coffee_arr[i].get_medium_cost() << endl;

                if (this->coffee_arr[i].get_large_cost() <= budget)
                {
                    cout << "   Large – " << this->coffee_arr[i].get_large_cost() << endl;
                }
            }
            cout << endl;
        }
    }
}

/*********************************************************************
** Function: add_to_menu
** Description: Adds a coffee item to the menu.
** Parameters: Coffee& coffee_to_add - Reference to the Coffee object to be added.
** Pre-Conditions: None
** Post-Conditions: Adds the coffee item to the menu.
*********************************************************************/
void Menu::add_to_menu(Coffee& coffee_to_add){
    Coffee* new_coffee_arr = new Coffee[(this->num_coffee)+1];
    for (int i = 0; i < this->num_coffee; i++)
    {
        new_coffee_arr[i] = this->coffee_arr[i];
    }
    new_coffee_arr[this->num_coffee] = coffee_to_add;
    delete[] this->coffee_arr;
    this->coffee_arr = new_coffee_arr;
    this->num_coffee++;
}

/*********************************************************************
** Function: remove_from_menu
** Description: Removes a coffee item from the menu.
** Parameters: int index - Index of the coffee item to be removed.
** Pre-Conditions: None
** Post-Conditions: Removes the coffee item from the menu.
*********************************************************************/
void Menu::remove_from_menu(int index){
    Coffee* new_coffee_arr = new Coffee[(this->num_coffee)-1];
    for (size_t i = 0; i < index; i++)
    {
        new_coffee_arr[i] = this->coffee_arr[i];
    }
    for (int i = index; i < this->num_coffee-1; i++)
    {
        new_coffee_arr[i] = this->coffee_arr[i+1];
    }
    delete[] this->coffee_arr;
    this->coffee_arr = new_coffee_arr;
    this->num_coffee--;
}

/*********************************************************************
** Function: load_data
** Description: Loads data from a file into the menu.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Populates the menu with data from the file.
*********************************************************************/
void Menu::load_data(){
    ifstream menu_txt("menu.txt");
    menu_txt >> this->num_coffee;

    this->coffee_arr = new Coffee[this->num_coffee];
    for (int i = 0; i < this->num_coffee; i++)
    {
        this->coffee_arr[i].load_data(menu_txt);
    }
}

/*********************************************************************
** Function: print_data
** Description: Prints details of all coffee items in the menu.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Prints the details of all coffee items in the menu.
*********************************************************************/
void Menu::print_data(){
    for (int i = 0; i < this->num_coffee; i++)
    {
        cout << "------------------------------" << endl;    
        cout << i+1 << ". " << this->coffee_arr[i].get_name() << endl;
        cout << "   Small - " << this->coffee_arr[i].get_small_cost() << endl;
        cout << "   Medium - " << this->coffee_arr[i].get_medium_cost() << endl;
        cout << "   Large - " << this->coffee_arr[i].get_large_cost() << endl;
		if (i+1 == this->num_coffee)
		{
		cout << "------------------------------" << endl << endl;
		}
	}
	
}
