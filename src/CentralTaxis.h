/*
 * CentralTaxis.h
 *
 */

#ifndef CENTRALTAXIS_H_
#define CENTRALTAXIS_H_

#include "Customer.h"
#include "PrivateCustomer.h"
#include "CompanyCustomer.h"
#include "Service.h"
#include "Route.h"
#include "Date.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class CentralTaxis
{
private:
	string name;
	string customersFile;
	string servicesFile;
	string routesFile;
	vector<Customer*> customers;
	vector<Service*> services;
	vector<Route*> routes;

public:
	CentralTaxis(string name, string customersFile, string servicesFile, string routesFile);

	vector<Customer*> getCustomers() const;
	vector<Service*> getServices() const;
	vector<Route*> getRoutes() const;

	string getCustomersFileName() const;
	string getServicesFileName() const;
	string getRoutesFileName() const;

	void addService(Service* service);
	void addRoute(Route* route);
	void addCustomer(Customer* customer);
	void editCustomerName();
	void editCustomerAddress();
	void editCustomerPhoneNumber();
	void removeCustomer();
	void saveCustomers();

	bool readFile(const string &fileName, vector<string> &fileLines);
	bool readCustomersFile();
	bool readServicesFile();
	bool readRoutesFile();

	void showDiscounts();
};

#endif /* CentralTaxis_H_ */
