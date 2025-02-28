#include "shop.h"
#include <iostream>
#include <fstream>

using namespace std;

//function defintions from shop.h goes here
/*********************************************************************
** Function: Shop (Destructor)
** Description: Destructor for the Shop class.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Deallocates memory for the order_arr.
*********************************************************************/
Shop::~Shop(){
    if (this->order_arr !=NULL)
    {
        delete [] this->order_arr;
        this->order_arr = NULL;
    }
}

/*********************************************************************
** Function: Shop (Copy Constructor)
** Description: Copy constructor for the Shop class.
** Parameters: const Shop& s - Reference to a Shop object to be copied.
** Pre-Conditions: None
** Post-Conditions: Creates a copy of the Shop object.
*********************************************************************/
Shop::Shop(const Shop& s){
    this->num_orders = s.num_orders;
    this->order_arr = new Order [this->num_orders];
    for (int i = 0; i < this->num_orders; i++)
    {
        this->order_arr[i] = s.order_arr[i];
    }
}

/*********************************************************************
** Function: operator=
** Description: Assignment operator for the Shop class.
** Parameters: const Shop& s - Reference to a Shop object to be assigned.
** Pre-Conditions: None
** Post-Conditions: Assigns the values of one Shop object to another.
*********************************************************************/
Shop& Shop::operator = (const Shop& s){
	cout << "AOO" << endl;
    if (this == &s)
    {
        return *this;
    }
    if (this->order_arr !=NULL)
    {
        delete [] this->order_arr;
    }
    this->num_orders = s.num_orders;
    this->order_arr = new Order [this->num_orders];
    for (int i = 0; i < this->num_orders; i++)
    {
        this->order_arr[i] = s.order_arr[i];
    }
    return *this;
}

/*********************************************************************
** Function: load_data
** Description: Reads from files to correctly populate coffee, menu, etc.
** Parameters: None
** Pre-Conditions: shop_info.txt file must be available.
** Post-Conditions: Populates the shop with data from files.
*********************************************************************/
void Shop::load_data(){
    ifstream shop_info_txt("shop_info.txt");
    if ((!shop_info_txt))
    {
        cout << "files error!";
    }
    else
    {
        m.load_data();
        getline(shop_info_txt, this->phone);
        getline(shop_info_txt, this->address);
        this->num_orders = 0;
        this->revenue = 0.0;
        for (int i = 0; i < num_orders; i++)
        {
            this->revenue += this->order_arr[i].calculate_order_cost(m);
        }
        shop_info_txt.close();
    }
}

/*********************************************************************
** Function: view_shop_detail
** Description: Prints shop details, including address, phone, revenue, menu, and orders.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Prints shop details.
*********************************************************************/
void Shop::view_shop_detail(){
    cout << "" << endl << "Address: " << this->address << endl;
    cout << "Phone: " << this->phone << endl;
    cout << "The shop revenue is: $" << this->revenue << endl;
    cout << "Here is our menu: " << endl;
    this->m.print_data();

    cout << "Order info: " << endl;
    if (num_orders < 1)
    {
        cout << "(No orders to display)" << endl;
    }
    else
    {
        for (int i = 0; i < num_orders; i++)
        {
            cout << "--------------------" << endl;
            this->order_arr[i].print_data();
            if (i + 1 == num_orders)
            {
                cout << "--------------------" << endl;
            }
        }
    }
}

/*********************************************************************
** Function: check_new_item
** Description: Checks if a new coffee item can be added to the menu.
** Parameters: string n - Coffee name, float s, m, l - Prices for small, medium, and large.
** Pre-Conditions: None
** Post-Conditions: Returns true if the item can be added, false otherwise.
*********************************************************************/
bool Shop::check_new_item(string n, float s, float m, float l){
    bool check = true;
    Coffee* result = this->m.search_coffee_by_name(n);
    if(result != NULL){
        cout << "Failed, this new drink already in the menu!" << endl;
        check = false;
    } else if ((l <= m) || (m <= s) || (s <= 0))
    {
        cout << "Failed, price error!" << endl;
        check = false;
    }

    return check;
}



/*********************************************************************
** Function: write_new_orders
** Description: Writes the new orders to the orders.txt file.
** Parameters: Order* order_arr - Pointer to an array of Order objects.
** Pre-Conditions: None
** Post-Conditions: Writes the new orders to the orders.txt file.
*********************************************************************/
void Shop::write_new_orders(Order* order_arr) {
    ofstream new_order("orders.txt");
    new_order << this->num_orders << endl;

    for (int i = 0; i < num_orders; i++) {
        new_order << this->order_arr[i].get_id() << " ";
        new_order << this->order_arr[i].get_coffee_name() << " ";
        new_order << this->order_arr[i].get_coffee_size() << " ";
        new_order << this->order_arr[i].get_quantity() << endl;
    }
    new_order.close();
}
/*********************************************************************
** Function: write_new_menu
** Description: Writes the new menu to the menu.txt file.
** Parameters: Menu& m - Reference to the Menu object.
** Pre-Conditions: None
** Post-Conditions: Writes the new menu to the menu.txt file.
*********************************************************************/
void Shop::write_new_menu(Menu& m) {
    ofstream new_menu("menu.txt");

    if (new_menu.is_open()) {
        new_menu << m.get_num_coffee() << endl;

        for (int i = 0; i < m.get_num_coffee(); i++) {
            new_menu << m.get_coffee_arr()[i].get_name() << " ";
            new_menu << m.get_coffee_arr()[i].get_small_cost() << " ";
            new_menu << m.get_coffee_arr()[i].get_medium_cost() << " ";
            new_menu << m.get_coffee_arr()[i].get_large_cost() << endl;
        }

        new_menu.close();
    } else {
        // Handle error if the file can't be opened
        cerr << "Error: Unable to open the output file." << endl;
    }
}
/*********************************************************************
** Function: add_to_menu
** Description: Handles the "Add coffee to menu" option.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Adds a new coffee item to the menu. 
*********************************************************************/
void Shop::add_to_menu(){
    string n;
    float s, m, l;

    cout << "Enter the name of the new coffee drink (in 1 word): ";
    cin >> n;
    cout << "Enter price of small size (8oz): ";
    cin >> s;

	cout << "Enter price of medium size (12oz): ";
	cin >> m;
	cout << "Enter price of large size (16oz): ";
	cin >> l;

	// --------------------------------------------------
	bool check = check_new_item(n, s, m, l);

	if (check)
	{
		// cout << "TURE" << endl;

		Coffee new_coffee = Coffee(n,s,m,l);
		// cout << new_coffee.get_name()<< endl;
		this->m.add_to_menu(new_coffee);
		this->write_new_menu(this->m);
	}
}

/*********************************************************************
** Function: remove_from_menu
** Description: Handles the "Remove coffee from menu" option. Calls Menu::remove_from_menu(int index_of_coffee_on_menu).
** Parameters: None
** Pre-Conditions: The shop menu must have at least one coffee item.
** Post-Conditions: The selected coffee is removed from the menu.
*********************************************************************/

void Shop::remove_from_menu(){
	//handle "Remove coffee from menu" option
	//Hint: call Menu::remove_from_menu(int index_of_coffee_on_menu);
	//Your code goes here: 
	for (size_t i = 0; i < this->m.get_num_coffee(); i++)
	{
		cout << "  " << i+1 << ". " << this->m.get_coffee_arr()[i].get_name() << endl;
	}
	cout << "Your selection: ";
	int choose;
	cin >> choose;
	this->m.remove_from_menu(choose-1);
	this->write_new_menu(this->m);
}

/*********************************************************************
** Function: search_by_name
** Description: Handles the "Search by coffee name" option. Calls Menu::search_coffee_by_name(string name).
** Parameters: None
** Pre-Conditions: The shop menu must have at least one coffee item.
** Post-Conditions: Displays information about the coffee with the given name.
*********************************************************************/


void Shop::search_by_name(){
	//handle "Search by coffee name" option
	//Hint: call Menu::search_coffee_by_name(string name);
	//Your code goes here: 
	string name;
	Coffee* result;
	cout << "Enter the coffee name: " << endl;
	cin >> name;
	result = this->m.search_coffee_by_name(name);
	if (result == NULL)
	{
		cout << "Sorry, we don’t have that product at the moment." << endl;
	} else {
		// string n = result->get_name();
		cout << endl << "Results: " << endl;
		cout << "1. " << result->get_name() << endl << "   Small: " << result->get_small_cost() << endl << "   Medium: " << result->get_medium_cost() << endl << "   Large: " << result->get_large_cost() << endl;
	}
	return;
}

/*********************************************************************
** Function: search_by_price
** Description: Handles the "Search by coffee price" option. Calls Menu::search_coffee_by_price(float budget).
** Parameters: None
** Pre-Conditions: The shop menu must have at least one coffee item.
** Post-Conditions: Displays the coffee items below or equal to the specified budget.
*********************************************************************/


void Shop::search_by_price(){
	//handle "Search by coffee price" option
	//Hint: call Menu::search_coffee_by_price(float budget);
	//Your code goes here: 
	float budget;
	cout << "Enter your budget for one drink, and I will list out our products that below or equal to your budget: ";
	cin >> budget;
	// if (IS_FLOAT(budget))
	// {
    cout << endl;
	this->m.search_coffee_by_price(budget);
		// budget_menu.print_data();
		
	// } else {
	// 	cout << "wrong data type!";
	// }
	
}

/*********************************************************************
** Function: calculate_cost
** Description: Calculates the cost of a coffee based on its index, size, and quantity.
** Parameters: int c (index of the coffee), char s (size of the coffee), int q (quantity of the coffee).
** Pre-Conditions: The shop menu must have at least one coffee item.
** Post-Conditions: Returns the calculated cost of the coffee.
*********************************************************************/


float Shop::calculate_cost(int c, char s, int q){
	float cost;
	if (s == 's'){
		cost = this->m.get_coffee_arr()[c].get_small_cost()*q;
	} else if (s == 'm'){
		cost = this->m.get_coffee_arr()[c].get_medium_cost()*q;
	} else if (s == 'l'){
		cost = this->m.get_coffee_arr()[c].get_large_cost()*q;
	}
	return cost;
}

/*********************************************************************
** Function: add_new_order
** Description: Adds a new order to the shop's order array.
** Parameters: int c (index of the coffee), char s (size of the coffee), int q (quantity of the coffee), float co (cost of the coffee).
** Pre-Conditions: The shop menu and order array must exist.
** Post-Conditions: A new order is added to the order array, and the shop's revenue is updated.
*********************************************************************/

void Shop::add_new_order(int c, char s, int q, float co){
	Order new_order((this->num_orders)+1, this->m.get_coffee_arr()[c].get_name(), s, q);
	Order* new_order_arr = new Order[(this->num_orders)+1];
	for (int i = 0; i < this->num_orders; i++)
	{
		new_order_arr[i] = this->order_arr[i];
	}
	new_order_arr[this->num_orders] = new_order;
	delete [] this->order_arr;
	this->order_arr = new_order_arr;
	this->num_orders++;
	this->revenue+=co;
}
/*********************************************************************
** Function: confirm
** Description: Handles the confirmation process for placing an order.
** Parameters: string confirm (user's confirmation choice), int c (index of the coffee), char s (size of the coffee), int q (quantity of the coffee), float co (cost of the coffee).
** Pre-Conditions: The order array must exist.
** Post-Conditions: The user's order is confirmed or canceled based on their choice.
*********************************************************************/


void Shop::comfirm(string comfirm, int c, char s, int q, float co){
	// if (!((cf=="1")||(cf=="2")))
	// {
	// 	cout << "the option doesn't exsit!"<< endl;
	// } else if(cf == "1"){
	// 	add_new_order(c, s, q, co);
	// 	cout << "Order "
	// } else if(cf == "2"){

	// }

	string cf = comfirm;
	
	while (true)
	{
		if (!((cf=="1")||(cf=="0")))
		{
			cout << "the option doesn't exsit! Please enter again!"<< endl;

			cin >> cf;
		}
		if (cf == "0")
		{
			cout << "Your order has been canceled" << endl;
			break;
		}
		if (cf == "1")
		{
			add_new_order(c, s, q, co);
			cout << endl << "Your order has been placed. Your order number is " << this->num_orders << "." << endl;
			break;
		}
		
	}
}

/*********************************************************************
** Function: con_place
** Description: Handles the process of placing an order by taking user input for coffee selection, size, and quantity.
** Parameters: int choice (index of the coffee), char size (size of the coffee), int q (quantity of the coffee).
** Pre-Conditions: The shop menu and order array must exist.
** Post-Conditions: The user's order is confirmed or canceled based on their input, and the order array and revenue are updated accordingly.
*********************************************************************/

void Shop::con_place(int choice, char size, int q){
	if (((choice >= 0)&&(choice < this->m.get_num_coffee()))&&((size == 's')||(size == 'm')||(size == 'l'))&&(q>0))
	{
		float cost = this->calculate_cost(choice, size, q);
		cout << endl << "Your total cost is: $" << cost << endl;

		cout << "Confirmed? 1-yes, 0-no: ";
		string cf;
		cin >> cf;
		this->comfirm(cf, choice, size, q, cost);
		this->write_new_orders(this->order_arr);
	} else {
		cout << "The option doesn't exsit!" << endl;
	}
}
/*********************************************************************
** Function: place_order
** Description: Handles the "Place order" option by displaying the menu and taking user input for coffee selection, size, and quantity.
** Parameters: None
** Pre-Conditions: The shop menu and order array must exist.
** Post-Conditions: The user's order is confirmed or canceled based on their input, and the order array and revenue are updated accordingly.
*********************************************************************/
void Shop::place_order(){
    cout << endl;
    for (size_t i = 0; i < this->m.get_num_coffee(); i++) {
        cout << "  " << i+1 << ". " << this->m.get_coffee_arr()[i].get_name() << endl;
    }
    cout << "Your selection: ";
    int choice, q;
    char size;
    cin >> choice;
    choice--;
    cout << endl << this->m.get_coffee_arr()[choice].get_name() << endl << "   Small: " << this->m.get_coffee_arr()[choice].get_small_cost() << endl << "   Medium: " << this->m.get_coffee_arr()[choice].get_medium_cost() << endl << "   Large: " << this->m.get_coffee_arr()[choice].get_large_cost() << endl;
    cout << endl << "Enter the size: s-small, m-medium, l-large: ";
    cin >> size;
    cout << "Enter quantity: ";
    cin >> q;
    con_place(choice,size,q);
}


/*********************************************************************
** Function: clone_shop
** Description: Handles the "Clone a shop" option. The purpose of this option is to test the big three implementation.
** Parameters: None
** Pre-Conditions: The shop must exist.
** Post-Conditions: A cloned shop is created using the copy constructor and the assignment operator, and a success message is displayed.
*********************************************************************/
Shop Shop::clone_shop() {
    Shop cloned_shop;

    cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}


/*********************************************************************
** Function: compare
** Description: Compares the quantities of small, medium, and large sizes for a specific coffee and determines the most popular size.
** Parameters: int& q (output parameter for the quantity), int s (quantity of small size), int m (quantity of medium size), int l (quantity of large size), string& size (output parameter for the most popular size).
** Pre-Conditions: The order array must exist.
** Post-Conditions: The most popular size and its quantity are determined, and the quantity is returned.
*********************************************************************/
int Shop::compare(int& q, int s, int m, int l, string& size) {
    int result;
    if ((s > m) && (s > l)) {
        q = s;
        size = "s"; // Use double quotes for string literals
        int result = s;
    } else if ((m > s) && (m > l)) {
        q = m;
        size = "m";
        int result = s;
    } else if((l > s) && (l > m)){
        q = l;
        size = "l";
        int result = s;
    }
    return result;
}



/*********************************************************************
** Function: best_seller
** Description: Determines and displays the best-selling coffee based on the most popular size and quantity.
** Parameters: None
** Pre-Conditions: The shop menu and order array must exist.
** Post-Conditions: The best-selling coffee, its most popular size, and the corresponding quantity are displayed.
*********************************************************************/
void Shop::best_seller() {
    string n, size, sizef;
    int q = 0, qf = 0, s = 0, m = 0, l = 0; // Initialize variables
    for (int i = 0; i < this->m.get_num_coffee(); i++) {
        // Reset quantities for each coffee
        s = m = l = 0;
        for (int j = 0; j < this->num_orders; j++) {
            if (this->order_arr[j].get_coffee_name() == this->m.get_coffee_arr()[i].get_name()) {
                if (this->order_arr[j].get_coffee_size() == 's') {
                    s += order_arr[j].get_quantity();
                } else if (this->order_arr[j].get_coffee_size() == 'm') {
                    m += order_arr[j].get_quantity();
                } else if (this->order_arr[j].get_coffee_size() == 'l') {
                    l += order_arr[j].get_quantity();
                }
            }
        }
        int temp = this->compare(q, s, m, l, size);
        if (q > qf) {
            qf = q;
            n = this->m.get_coffee_arr()[i].get_name();
            sizef = size;
        }
    }
    if (qf == 0) {
        size = "";
    }
    cout << "The best seller is [" << n << "], the size is [" << sizef << "], and it's quantity is [" << qf << "]." << endl;
}


/*********************************************************************
** Function: sortFloatArrayDescending
** Description: Sorts a float array and a corresponding Coffee array in descending order.
** Parameters: float sell[] (the float array to be sorted), Coffee c[] (the corresponding Coffee array), int size (size of the arrays).
** Pre-Conditions: The arrays must exist.
** Post-Conditions: The arrays are sorted in descending order based on the float values.
*********************************************************************/
void Shop::sortFloatArrayDescending(float sell[], Coffee c[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sell[j] < sell[j + 1]) {
                // Swap the elements in descending order
                Coffee tempc = c[j];
                float tempf = sell[j];
                c[j] = c[j + 1];
                sell[j] = sell[j + 1];
                c[j + 1] = tempc;
                sell[j + 1] = tempf;
            }
        }
    }
}


/*********************************************************************
** Function: top_3_popular
** Description: Determines and displays the top 3 popular coffees based on their total sales.
** Parameters: None
** Pre-Conditions: The shop menu and order array must exist.
** Post-Conditions: The top 3 popular coffees and their total sales are displayed.
*********************************************************************/
void Shop::top_3_popular(){
    Coffee* new_order = this->m.get_coffee_arr();
    float sell[this->m.get_num_coffee()];
    for (int i = 0; i < this->m.get_num_coffee(); i++) {
        sell[i] = 0.00;
        for (int j = 0; j < this->num_orders; j++) {
            if (this->order_arr[j].get_coffee_name() == this->m.get_coffee_arr()[i].get_name()) {
                if (this->order_arr[j].get_coffee_size() == 's') {
                    sell[i] += (this->m.get_coffee_arr()[i].get_small_cost() * this->order_arr[j].get_quantity());
                }
                if (this->order_arr[j].get_coffee_size() == 'm') {
                    sell[i] += (this->m.get_coffee_arr()[i].get_medium_cost() * this->order_arr[j].get_quantity());
                }
                if (this->order_arr[j].get_coffee_size() ==
 'l')
				{
					sell[i] += (this->m.get_coffee_arr()[i].get_large_cost() * this->order_arr[j].get_quantity());
				}
			}
		}
	}
	sortFloatArrayDescending(sell, new_order, this->m.get_num_coffee());
	cout << endl << "1: " << new_order[0].get_name() << " - $" << sell[0] << endl;
	cout << "2: " << new_order[1].get_name() << " - $" << sell[1] << endl;
	cout << "3: " << new_order[2].get_name() << " - $" << sell[2] << endl;
}