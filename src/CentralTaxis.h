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
//	Customer* addCustomer(string name, string address, unsigned int nif);
//	Service* addService();
//	bool editCustomer();
//	bool removeCustomer();


};











































#endif /* CentralTaxis_H_ */
