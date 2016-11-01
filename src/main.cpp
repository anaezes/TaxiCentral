#include "Menu.h"
#include "CentralTaxis.h"

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	string nameCentralTaxis = "Taxis XPTO";
	string customersFile = "/home/anasantos/Dropbox/faculdade/2ano/1semestre/AEDA/trabalhos/trabalho1/customers.txt";
	string servicesFile = "/home/anasantos/Dropbox/faculdade/2ano/1semestre/AEDA/trabalhos/trabalho1/services.txt";
	string routesFile = "/home/anasantos/Dropbox/faculdade/2ano/1semestre/AEDA/trabalhos/trabalho1/routes.txt";

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
		cout << endl << endl << setw(10) << "Computer says welcome to program!" << endl;
		mainMenu(central);

	}

	return 0;
}
