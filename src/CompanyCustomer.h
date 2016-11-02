#ifndef COMPANYCUSTOMER_H_
#define COMPANYCUSTOMER_H_

#include "Customer.h"
#include "Service.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CompanyCustomer: public Customer
{
private:
	double cost;
public:
	CompanyCustomer(unsigned int nif, string name, string address, int phoneNumber, double cost);
	~CompanyCustomer();
	int getCost();
	float getDiscount();
	void accumulateService(Service* service);
	CUSTOMER_TYPE getCustomerType();
	ostream & operator<<(ostream &out);
};

#endif /* PRIVATECUSTOMER_H_ */
