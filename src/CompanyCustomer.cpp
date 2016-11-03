#include "CompanyCustomer.h"

CompanyCustomer::CompanyCustomer(unsigned int nif, string name, string address, int phoneNumber, double cost):
Customer(nif, name, address, phoneNumber)
{
	this->cost = cost;
}

CompanyCustomer::~CompanyCustomer()
{

}


int CompanyCustomer::getCost()
{
	return cost;
}

float CompanyCustomer::getDiscount()
{
	//apenas para testes (!!!!)
	float a = 0.5;

	return a;
}

void CompanyCustomer::accumulateService(Service* service)
{
}

Customer::CUSTOMER_TYPE CompanyCustomer::getCustomerType()
{
	return CUSTOMER_TYPE::CompanyCustomer;
}

string CompanyCustomer::getInformation()
{
	stringstream information;

	information << setw(3) << "C";
	information << setw(15) << Customer::getInformation();
	information << setw(20) << this->cost;
	information << endl;

	return information.str();
}

/*
 * returns a string with all information
 * of the customer in the format needed
 */
string CompanyCustomer::toFileFormat()
{
	stringstream information;

	information << "C"<< Customer::toFileFormat() <<  ";" << this->cost;

	return information.str();
}
