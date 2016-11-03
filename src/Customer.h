/*
 * Customer.h
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Service.h"

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

class Customer
{
private:
	string name;
	string address;
	unsigned int nif;
	int phoneNumber;

public:
	Customer(unsigned int nif, string name, string address, int phoneNumber);
	virtual ~Customer();

	enum CUSTOMER_TYPE
	{
		CompanyCustomer,
		PrivateCustomer
	};

	string getName();
	string getAddress();
	int getPhoneNumber();
	float getPoints();
	unsigned int getNif() const;
	void setName(string name);
	void setAddress(string address);
	void setPhoneNumber(int phoneNumber);
	virtual float getDiscount() = 0;
	virtual void accumulateService(Service* service) = 0;
	virtual CUSTOMER_TYPE getCustomerType() = 0;
	virtual string getInformation();
};

void showAllCustomersInfo(vector<Customer*> vectorCustomers);




#endif /* CUSTOMER_H_ */
