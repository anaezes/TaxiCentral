#include "Menu.h"

using namespace std;

/******************************************
Customer management
******************************************/

unsigned short int customersMenu()
{
	unsigned short int chosenOption;
	int id = 0;

	/*Menu of customers, where the user can choose what the option that wants*/
	clearScreen();

	cout << TAB_BIG << "CUSTOMER MENU MANAGEMENT" << endl;
	cout << endl;
	cout << TAB << "1- Show information about all customers" << endl;
	cout << TAB << "2- Show information about one customer" << endl;
	cout << TAB << "3- Show customers in alphabetical order" << endl;
	cout << TAB << "4- Edit customers" << endl;
	cout << TAB << "5- Remove customers" << endl;
	cout << TAB << "6- Insert new customer" << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		break;

	case 2:
		oneCustomerMenu();
		break;

	case 3:
		break;

	case 4:
		editCustomerMenu();
		break;

	case 5:
		break;
	case 6:
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

unsigned short int oneCustomerMenu()
{
	unsigned short int chosenOption;

	cout << TAB_BIG << "How do you want search?" << endl;
	cout << endl;
	cout << TAB << "1- Through NIF" << endl;
	cout << TAB << "2- Through name" << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		break;

	case 2:
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

unsigned short int editCustomerMenu()
{
	unsigned short int chosenOption;
	do
	{

		cout << TAB_BIG << "What do you want to change?" << endl;
		cout << endl;
		cout << TAB << "1- Name" << endl;
		cout << TAB << "2- Accession date" << endl;
		cout << TAB << "3- Adress" << endl;
		cout << TAB << "0- Out if there is not longer anything to be changed" << endl;


		cout << "What is the option that you want? ";
		cin >> chosenOption;
		cout << endl;


		switch (chosenOption)
		{
		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 0:
			return 0;

		default:
			cout << "Invalid option. Try again." << endl;
			break;
		}
	} while (chosenOption != 0);
	return 0;
}

/******************************************
Service management
******************************************/
unsigned short int serviceMenu()
{
	unsigned short int chosenOption;

	/*Menu of services, where the user can choose what the option that wants*/
	clearScreen();

	cout << TAB_BIG << "SERVICE MENU MANAGEMENT" << endl;
	cout << endl;
	cout << TAB << "1- Show information about all the services" << endl;
	cout << TAB << "2- Show a day services" << endl;
	cout << TAB << "3- Show services between two dates" << endl;
	cout << TAB << "4- Show services in chronological order" << endl;
	cout << TAB << "5- Show services about one customer" << endl;
	cout << TAB << "6- Edit service" << endl;
	cout << TAB << "7- Remove service" << endl;
	cout << TAB << "8- Insert new service" << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}


/******************************************
Discounts Menu
******************************************/

unsigned short int discountsMenu()
{
	unsigned short int chosenOption;
	unsigned int id;

	clearScreen();

	cout << TAB_BIG << "DISCOUNTS MENU" << endl;
	cout << endl;
	cout << TAB << "1- Show available discounts" << endl;

	cout << TAB << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		break;
	default:
		cout << "Invalid option. Try again." << endl;
		break;

	}
	return 0;
}

/******************************************
Main Menu
******************************************/

unsigned short int mainMenu(vector<Customer>customers,vector<Service>services,string fileCustomers,string fileServices)
{
	unsigned short int chosenOption;
	ifstream fin;
	string line;

	if (readFileCustomers(customers, fileCustomers) && readFileProducts(products, fileProducts) && vendevar.readFileTransactions(transactions, fileTransactions))
	{
		do
		{
			cout << TAB_BIG << "Main Menu" << endl;
			cout << endl;
			cout << TAB << "1- Customers management" << endl;
			cout << TAB << "2- Services management" << endl;
			cout << TAB << "3- Discounts" << endl;
			cout << TAB << "0- Exit program" << endl << endl;

			cout << TAB << "What is the option that you want? ";
			cin >> chosenOption;
			cout << endl;

			switch (chosenOption)
			{
			case 1:
				customersMenu();
				break;

			case 2:
				serviceMenu();
				break;

			case 3:
				discountsMenu();
				break;
			case 0:
				return 0;

			default:
				cout << "Invalid option. Try again." << endl;
				break;
			}

		} while (chosenOption != 0);
	}

	else
	{
		cout << "File not found!\n";
		requestFiles(fileCustomers, fileProducts, fileTransactions);
	}


	return 0;

}
