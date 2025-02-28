/******************************************************
** Program: coffee_shop.cpp
** Author: Your Name
** Date: 11/01/2023
** Description: This program is going to simulate some of the common functionalities of a coffee shop. The program will allow the user, which is the shop manager, to interact with the shop.
** Input: "menu.txt", "orders.txt", "shop_info.txt"
** Output: depends on the users' choice(10 defferent options)
******************************************************/
#include <iostream>
#include <fstream>
#include "display.h"

using namespace std;

int main()
{
	ifstream file1("menu.txt"), file2("shop_info.txt"), file3("orders.txt");
	if (file1.is_open() && file2.is_open() && file3.is_open())
	{
		//your main function lives here
		cout << "Welcome to Coffee++" << endl;
		int choice = -1;
		Shop s;
		//populate your Shop:
		s.load_data();
		//your code here:


		while (choice != QUIT){
			choice = get_choice();
			perform_action(s, choice);
		}

		cout << "Bye!" << endl;
	}
	file1.close();
    file2.close();
    file3.close();
	return 0;
}
