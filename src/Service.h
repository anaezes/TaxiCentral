/*
 * Service.h
 *
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include "Route.h"
#include "Date.h"

#include <vector>
#include <string>

using namespace std;

class Service
{
private:
	Customer* customer;
	double cost;
	Route* route;
	Date date;
	string payment;

public:
	static double rateForKm;
	static double rateForExtraMin;
	Service(Customer* customer, double cost, Route* route, Date date, string payment);
	~Service();
	Customer* getCustomer();
	double getCost();
	Route getRoute();
	Date getDate();
	string getPayment();
};











































#endif /* SERVICE_H_ */
