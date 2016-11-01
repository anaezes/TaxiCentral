/*
 * Customer.h
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include <iostream>

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
	~Customer();
	string getName();
	string getAddress();
	int getPhoneNumber();
	float getPoints();
	unsigned int getNif() const;
	void setName(string name);
	void setAddress(string address);
	void setPhoneNumber(int phoneNumber);
	virtual float getDiscount() = 0;
	virtual void accumulateService = 0;

};












































#endif /* CUSTOMER_H_ */
