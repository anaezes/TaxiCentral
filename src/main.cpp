#include "Menu.h"
#include "CentralTaxis.h"

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	string nameCentralTaxis = "Taxis XPTO";
	string customersFile = "/home/sissi/Documentos/Aeda_trabalho/EmTaxis/customers.txt";
	string servicesFile = "/home/sissi/Documentos/Aeda_trabalho/EmTaxis/services.txt";
	string routesFile = "/home/sissi/Documentos/Aeda_trabalho/EmTaxis/routes.txt";

	CentralTaxis central(nameCentralTaxis, customersFile, servicesFile, routesFile);

	bool customersSuccess = central.readCustomersFile();
	bool servicesSuccess = central.readServicesFile();
	bool routesSuccess = central.readRoutesFile();

	if(!(customersSuccess && servicesSuccess && routesSuccess))
	{
		cout << "Error while reading a file" << endl;
		return -1;
	}
	else
	{
		cout << endl << endl << setw(10) << "Computer says welcome to program!" << endl << endl;
		mainMenu(central);

	}

	return 0;
}
