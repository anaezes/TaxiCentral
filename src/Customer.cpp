#include "Customer.h"

/******************************************************/
/*             CUSTOMER CLASS FUNCTIONS               */
/******************************************************/


Customer::Customer(unsigned int nif, string name, string address, int phoneNumber)
{
	this->nif = nif;
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
}

Customer::~Customer()
{

}

string Customer::getName()
{
	return name;
}

string Customer::getAddress()
{
	return address;
}


int Customer::getPhoneNumber()
{

	return phoneNumber;
}

unsigned int Customer::getNif() const
{
	return nif;
}

void Customer::setName(string name)
{
	this->name= name;
}

void Customer::setAddress(string address)
{
	this->address= address;
}

void Customer::setPhoneNumber(int phoneNumber)
{
	this->phoneNumber=phoneNumber;
}






/******************************************************/
/*           CUSTOMERS GENERAL FUNCTIONS              */
/******************************************************/

/*
  Function used while sorting customers
  by name.
 */
bool compareByName( Customer* name_a,Customer* name_b)
{
	return name_a->getName() < name_b->getName();
}

ostream& Customer::operator<<(std::ostream &out)
{
	out << setw(5) << nif;
	out << setw(25) << name;
	out << setw(20) << address;
	out << setw(20) << phoneNumber;

	return out;
}

/*
  Function used while sorting customers
  by name.
 */

void showAllCustomersInfo(vector<Customer*> customers)
{

	std::sort(customers.begin(), customers.end(), compareByName);

	cout << setw(5) << "TYPE" << setw(5) << "NIF" << setw(25) << "Name" << setw(20) << "Address"
			<< setw(15) << "PhoneNumber" << setw(10) << "Points/Cost" << endl;
	cout << " ---------------------------------------------------------------- " << endl;

	for(size_t i = 0; i < customers.size() ; i++)
	{
		cout << customers[i];
	}

	cout << endl << endl;
}

