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

ostream& CompanyCustomer::operator<<(std::ostream &out)
{
	out << setw(5) << "C";
	cout << this;
	out << setw(15) << cost;

	return out;
}
