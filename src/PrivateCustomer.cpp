#include "PrivateCustomer.h"

PrivateCustomer::PrivateCustomer(unsigned int nif, string name, string address, int phoneNumber, int points) :
Customer(nif, name, address, phoneNumber)
{
	this->points = points;
}

PrivateCustomer::~PrivateCustomer()
{

}


int PrivateCustomer::getPoints()
{
	return points;
}

float PrivateCustomer::getDiscount()
{
	//apenas para testes (!!!!)
	float b = 0.7;

	return b;
}

void PrivateCustomer::accumulateService(Service* service)
{
}

Customer::CUSTOMER_TYPE PrivateCustomer::getCustomerType()
{
	return CUSTOMER_TYPE::PrivateCustomer;
}

string PrivateCustomer::getInformation()
{

	stringstream information;

	information << setw(3) << "P";
	information << setw(15) << Customer::getInformation();
	information << setw(20) << this->points;
	information << endl;

	return information.str();
}

/*
 * returns a string with all information
 * of the customer in the format needed
 */
string PrivateCustomer::toFileFormat()
{
	stringstream information;

	information << "P"<< Customer::toFileFormat() << ";" << this->points;

	return information.str();
}
