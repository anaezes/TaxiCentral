#include "Customer.h"

// define class Customer

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
