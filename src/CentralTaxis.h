/*
 * CentralTaxis.h
 *
 */

#pragma once

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
#include <algorithm>
#include <utility>

class Service;

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

	void editCustomerName();
	void editCustomerAddress();
	void editCustomerPhoneNumber();

	void removeCustomer();
	Customer* insertNewCustomer();
	void saveCustomers();

	void removeRoute();
	void insertNewRoute();
	Route* insertNewRoute(string, string);
	void saveRoutes();

	void insertNewService();
	Customer* processCustomerNewService();
	Route* findRoute(string, string);
	Route* processRouteNewService();
	int processTimeService();
	string processTypeOfPayment(Customer*);
	void saveService();

	bool readFile(const string&, vector<string>&);
	bool readCustomersFile();
	bool readServicesFile();
	bool readRoutesFile();

	void showDiscounts();
};
