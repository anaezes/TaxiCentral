#include "Customer.h"
#include <iostream>

// define class Customer

Customer::Customer(string name, string address, unsigned int nif) :
historic()
{
	this->name = name;
	this->address = address;
	this->nif = nif;
}


Customer::~Customer()
{

}
string Customer::getName()
{
return name;
}
d
string Customer::getAddress()
{
	return address;
}

unsigned int Customer::getNif() const;
{
	return nif;
}

vector<Service*> Customer::getHistoric()
{
return historic;
}

void Customer::setName(string name)
{
	}

void Customer::setAddress(string address)
{
}
