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
	int points;
	//vector<Service *> historic;
public:
	Customer(unsigned int nif, string name, string address, int phoneNumber, int points);
	~Customer();
	string getName();
	string getAddress();
	int getPhoneNumber();
	float getPoints();
	unsigned int getNif() const;
	vector<Service*> getHistoric();
	void setName(string name);
	void setAddress(string address);
	//void setPoints(float points);
	void setPhoneNumber(int phoneNumber);
	virtual float getDiscount() = 0;

};












































#endif /* CUSTOMER_H_ */
