#include "Menu.h"
#include "CentralTaxis.h"

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	string nameCentralTaxis = "Taxis XPTO";
	string vouchersFile = "/home/sissi/Documentos/Aeda_trabalho/EmTaxis/vouchers.txt";
	string customersFile = "/home/sissi/Documentos/Aeda_trabalho/EmTaxis/customers.txt";
	string servicesFile = "/home/sissi/Documentos/Aeda_trabalho/EmTaxis/services.txt";
	string routesFile = "/home/sissi/Documentos/Aeda_trabalho/EmTaxis/routes.txt";

	map<int, Voucher*> mapVouchers;

	CentralTaxis central(nameCentralTaxis, vouchersFile, customersFile, servicesFile, routesFile);
	bool vouchersSuccess = central.readVouchersFile(mapVouchers);
	bool customersSuccess = central.readCustomersFile(mapVouchers);
	bool servicesSuccess = central.readServicesFile();
	bool routesSuccess = central.readRoutesFile();
	central.loadVouchers(mapVouchers);

	if(!(vouchersSuccess && customersSuccess && servicesSuccess && routesSuccess))
	{
		cout << "Error while reading a file" << endl;
		return -1;
	}
	else
		mainMenu(central);

	return 0;
}
