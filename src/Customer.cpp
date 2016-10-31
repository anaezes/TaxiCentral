#include "Customer.h"
#include <iostream>

// define class Customer

Customer::Customer(unsigned int nif, string name, string address, int phoneNumber, int points)
{
	this->nif = nif;
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->points = points;
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

float Customer::getPoints()
{
	return points;
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

//void Customer::setPoints(float points)
//{
//	this->points=points;
//}

void Customer::setPhoneNumber(int phoneNumber)
{
	this->phoneNumber=phoneNumber;
}
