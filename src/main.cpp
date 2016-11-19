#include "Menu.h"
#include "CentralTaxis.h"

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	string nameCentralTaxis = "Taxis XPTO";
	string vouchersFile = "/home/anasantos/Dropbox/faculdade/2ano/1semestre/AEDA/trabalhos/trabalho1/vouchers.txt";
	string customersFile = "/home/anasantos/Dropbox/faculdade/2ano/1semestre/AEDA/trabalhos/trabalho1/customers.txt";
	string servicesFile = "/home/anasantos/Dropbox/faculdade/2ano/1semestre/AEDA/trabalhos/trabalho1/services.txt";
	string routesFile = "/home/anasantos/Dropbox/faculdade/2ano/1semestre/AEDA/trabalhos/trabalho1/routes.txt";

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
