/*
 * CentralTaxis.h
 *
 */

#ifndef CENTRALTAXIS_H_
#define CENTRALTAXIS_H_

#include <vector>
#include <string>
using namespace std;

class Customer;
class Service;

class CentralTaxis
{
private:
	string name;
	string customersFile;
	string servicesFile;
	vector<Customer*> customers;
	vector<Service*> services;
public:
	CentralTaxis(string name, string customersFile, string servicesFile);
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
