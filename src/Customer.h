/*
 * Customer.h
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Service.h"
#include <vector>
#include <string>
using namespace std;


class Customer
{
private:
	string name;
	string address;
	unsigned int nif;
	int phoneNumber;
	float points;
	vector<Service *> historic;
public:
	Customer(string name, string address, unsigned int nif);
	~Customer();
	string getName();
	string getAddress();
	unsigned int getNif(unsigned int n) const;
	vector<Service*> getHistoric();
	void setName(string name);
	void setAddress(string address);

	virtual float getDiscount() = 0;

};












































#endif /* CUSTOMER_H_ */
