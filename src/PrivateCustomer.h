#ifndef PRIVATECUSTOMER_H_
#define PRIVATECUSTOMER_H_

#include "Customer.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class PrivateCustomer : public Customer
{
private:
	int points;
public:
	PrivateCustomer(unsigned int nif, string name, string address, int phoneNumber, int points);
	~PrivateCustomer();
	int getPoints();
	float getDiscount();
	void acummulateService(double cost);
};

#endif /* PRIVATECUSTOMER_H_ */
