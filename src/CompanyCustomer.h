#ifndef COMPANYCUSTOMER_H_
#define COMPANYCUSTOMER_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CompanyCustomer : public Customer
{
private:
	double cost;
public:
	CompanyCustomer(unsigned int nif, string name, string address, int phoneNumber, double cost);
	~CompanyCustomer();
	int getCost();
	float getDiscount();
	void acummulateService(double cost);
};

#endif /* PRIVATECUSTOMER_H_ */