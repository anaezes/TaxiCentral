/*
 * CentralTaxis.h
 *
 */

#ifndef CENTRALTAXIS_H_
#define CENTRALTAXIS_H_

#include "Customer.h"
#include "Service.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Customer;
class Service;

class CentralTaxis
{
private:
	string name;
	string customersFile;
	string servicesFile;
	string routesFile;
	vector<Customer*> customers;
	vector<Service*> services;
	vector<Routes*> routes;
public:
	CentralTaxis(string name, string customersFile, string servicesFile, string routesFile);
	~CentralTaxis();
	vector<Customer*> getCustomers() const;
	vector<Service*> getServices() const;
	string getCustomersFileName() const;
	string getServicesFileName() const;
	void partitionCustomer(string line, vector<Customer> &customers);
	bool readFileCustomers(vector<Customer> &customers, string &fileCustomers);
	void partitionService(string line, vector<Service> &services);
	bool readFileServices(vector<Service> &services, string &fileServices);
//	void partitionRoute(string line, vector<Route> &routes);
//	bool readFileRoute(vector<Route> &customers, string &fileRoutes);
};
#endif /* CentralTaxis_H_ */
