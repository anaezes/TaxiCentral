#include"Menu.h"
#include "Service.h"
#include "CentralTaxis.h"
#include "Customer.h"

#include<iostream>

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


	}

	return 0;
}
