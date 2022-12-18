#include <iostream>
#include "add_rec.h"
#include "phone_list.h"
#include "search_rec.h"
#include "ex_it.h"
using namespace std;
void title(void)
{
	cout << "\n\n\t\t----------------------------------------------------------------------------------";
	cout << "\n\t\t\t\t               Phone Record        ";
	cout << "\n\t\t----------------------------------------------------------------------------------";
}
int MainMenu()
{
	title();
	cout << "\n\n\n\n\n\t\t\t\t1. Add Phone Record\n";
	cout << "\n\t\t\t\t2. List Phone Record\n";
	cout << "\n\t\t\t\t3. Search Phone Record\n";
	cout << "\n\t\t\t\t4. Exit\n";
	cout << "\n\n\n \n\t\t\t\tChoose from 1 to 4:";
	int choose;
	cin >> choose;
	int stop = choose;
	switch (choose)
	{

	case 1:
		Add_Phone_rec();
		break;
	case 2:
		Phone_list();
		break;
	case 3:
	Search_rec();
		break;
	case 4:
	
		stop = ex_it();
		break;

	default:
		cout << "\n\n\t\t\tInvalid entry. Please enter right option :)";
	}

	return stop;
}
