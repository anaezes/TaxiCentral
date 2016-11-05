#include "Menu.h"


using namespace std;

/******************************************
			Customer management
 ******************************************/


void cleanDisplay()
{
	std::system("clear");
}

unsigned short int customersMenu(CentralTaxis &central)
{
	unsigned short int chosenOption;

	/*Menu of customers, where the user can choose what the option that wants*/
	cleanDisplay();

	cout << TAB_BIG << "CUSTOMER MENU MANAGEMENT" << endl;
	cout << endl;
	cout << TAB << "1- Show information about all customers" << endl;
	cout << TAB << "2- Show information about one customer" << endl;
	cout << TAB << "3- Edit customers" << endl;
	cout << TAB << "4- Remove customers" << endl;
	cout << TAB << "5- Insert new customer" << endl << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		showAllCustomersInfo(central.getCustomers());
		break;

	case 2:
		oneCustomerMenu(central);
		break;

	case 3:
		editCustomerMenu(central);
		break;

	case 4:
		central.removeCustomer();
		break;

	case 5:
		central.insertNewCustomer();
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

unsigned short int oneCustomerMenu(CentralTaxis &central)
{
	unsigned short int chosenOption;

	cout << TAB_BIG << "How do you want search?" << endl;
	cout << endl;
	cout << TAB << "1- Through NIF" << endl;
	cout << TAB << "2- Through name" << endl << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		showCustomersInfoByNif(central.getCustomers());
		break;

	case 2:
		showCustomersInfoByName(central.getCustomers());
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

unsigned short int editCustomerMenu(CentralTaxis &central)
{
	unsigned short int chosenOption;
	do
	{

		cout << TAB_BIG << "What do you want to change?" << endl;
		cout << endl;
		cout << TAB << "1- Name" << endl;
		cout << TAB << "2- Address" << endl;
		cout << TAB << "3- Phone Number" << endl;
		cout << TAB << "0- Out if there is not longer anything to be changed" << endl << endl;


		cout << "What is the option that you want? ";
		cin >> chosenOption;
		cout << endl;


		switch (chosenOption)
		{
		case 1:
			central.editCustomerName();
			break;

		case 2:
			central.editCustomerAddress();
			break;

		case 3:
			central.editCustomerPhoneNumber();
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

unsigned short int oneCustomerServicesMenu(CentralTaxis &central)
{
	unsigned short int chosenOption;

	cout << TAB_BIG << "How do you want search?" << endl;
	cout << endl;
	cout << TAB << "1- Through NIF" << endl;
	cout << TAB << "2- Through name" << endl << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		showCustomerServicesByNif(central.getServices(), central.getCustomers());
		break;

	case 2:
		showCustomerServicesByName(central.getServices(), central.getCustomers());
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}
unsigned short int servicesMenu(CentralTaxis &central)
{
	unsigned short int chosenOption;

	/*Menu of services, where the user can choose what the option that wants*/
	cleanDisplay();

	cout << TAB_BIG << "SERVICE MENU MANAGEMENT" << endl;
	cout << endl;
	cout << TAB << "1- Show information about all the services" << endl;
	cout << TAB << "2- Show a day services" << endl;
	cout << TAB << "3- Show services between two dates" << endl;
	cout << TAB << "4- Show services about one customer" << endl;
	cout << TAB << "5- Edit service" << endl;
	cout << TAB << "6- Remove service" << endl;
	cout << TAB << "7- Insert new service" << endl << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		showAllServicesInfo(central.getServices());
		break;

	case 2:
		showServicesDay(central.getServices());
		break;

	case 3:
		showServicesBetweenDays(central.getServices());
		break;

	case 4:
		oneCustomerServicesMenu(central);
		break;

	case 5:
		break;
	case 6:
		break;
	case 7:
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}


/******************************************
				Routes Menu
 ******************************************/

unsigned short int routesMenu(CentralTaxis &central)
{
	unsigned short int chosenOption;

	cleanDisplay();

	cout << TAB_BIG << "ROUTES MENU" << endl;
	cout << endl;
	cout << TAB << "1- Show available routes" << endl;
	cout << TAB << "2- Remove a route" << endl << endl;

	cout << TAB << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		showAvailableRoutes(central.getRoutes());
		break;
	case 2:
		central.removeRoute();
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

unsigned short int mainMenu(CentralTaxis &central)
{
	unsigned short int chosenOption;
	ifstream fin;
	string line;

	do
	{
		cout << endl << endl;
		cout << TAB_BIG << "Main Menu" << endl;
		cout << endl;
		cout << TAB << "1- Customers management" << endl;
		cout << TAB << "2- Services management" << endl;
		cout << TAB << "3- Routes management" << endl;
		cout << TAB << "4- Show discounts availables" << endl;
		cout << TAB << "0- Exit program" << endl << endl;

		cout << TAB << "What is the option that you want? ";
		cin >> chosenOption;
		cout << endl;

		switch (chosenOption)
		{
		case 1:
			customersMenu(central);
			break;

		case 2:
			servicesMenu(central);
			break;

		case 3:
			routesMenu(central);
			break;
		case 4:
			central.showDiscounts();
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
