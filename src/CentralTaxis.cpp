#include "CentralTaxis.h"
#include "Customer.h"
#include "Service.h"


CentralTaxis::CentralTaxis(string name, string customersFile, string servicesFile) :
	customers(),
	services()
{
	this->name = name;
	this->customersFile = customersFile;
	this->servicesFile = servicesFile;
}

vector<Customer*> CentralTaxis::getCustomers() const
{
	return customers;
}


vector<Service*> CentralTaxis::getServices() const
{
	return services;
}

string CentralTaxis::getCustomersFileName() const
{
	return customersFile;
}
string CentralTaxis::getServicesFileName() const
{
	return servicesFile;
}

//Customer* CentralTaxis::addCustomer(string name, string adress, unsigned int nif)
//{
//
//}
//Service* CentralTaxis::addService()
//{
//}
//bool CentralTaxis::editCustomer()
//{
//}
//bool CentralTaxis::removeCustomer()
//{
//}
