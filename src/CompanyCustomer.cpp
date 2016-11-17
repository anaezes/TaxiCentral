#include "CompanyCustomer.h"

CompanyCustomer::CompanyCustomer(unsigned int nif, string name, string address, int phoneNumber, double cost):
Customer(nif, name, address, phoneNumber)
{
	this->cost = cost;
	this->voucher = NULL;
}

CompanyCustomer::CompanyCustomer(unsigned int nif, string name, string address, int phoneNumber, double cost, Voucher* voucher):
Customer(nif, name, address, phoneNumber)
{
	this->cost = cost;
	this->voucher = voucher;
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

	cout << "Company discount" << endl;
	if(voucher == NULL)
		return 0;

	Date dateOfDay(realTime());

	//verify if voucher is expired
	if(!(dateOfDay <= voucher->getDuration()))
		return 0;

	return voucher->getValue();
}

void CompanyCustomer::accumulateService(Service* service)
{
	this->cost = cost + service->getCost();
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

	information << "C" << ";" << Customer::toFileFormat() <<  ";" << this->cost;

	return information.str();
}

Voucher* CompanyCustomer::addVoucher(Voucher* voucher)
{
	if(this->voucher == NULL)
	{
		this->voucher = voucher;
		return voucher;
	}
	else
	{
		double value = this->voucher->getValue() + voucher->getValue();

		//Date dateOfDay(realTime());
		Date dateOfDay("30/01/2016");
		Date nextMonth = dateOfDay.getNextMonth();
		this->voucher->setDate(nextMonth);

		if(value <= 0.20)
			this->voucher->setValue(value);
		else
			this->voucher->setValue(0.20);


	}

	return this->voucher;
}

