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
