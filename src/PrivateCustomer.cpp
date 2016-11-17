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
	if(points < 50)
		return 0;
	else if(points >= 50 && points < 100)
		return 0.1;
	else if(points >= 100 && points < 150)
		return 0.2;
	else if(points >= 150 && points < 200)
		return 0.3;
	else if(points >= 200 && points < 250)
		return 0.4;
	else
		return 0.5;

}

void PrivateCustomer::accumulateService(Service* service)
{
	int pointsService = (int)service->getCost()/10;
	this->points = this->points + pointsService;
	cout << "Points after this service: " << this->points << endl;
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

	information << "P" << ";" << Customer::toFileFormat() << ";" << this->points;

	return information.str();
}

void PrivateCustomer::resetPoints()
{
	this->points = 0;
}




