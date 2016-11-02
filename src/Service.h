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

class Customer;

using namespace std;

enum PAYMENT_TYPE
{
	Cash,
	ATM,
	Credit,
	EndOfMonth
};

class Service
{
private:
	Customer* customer;
	double cost;
	Route* route;
	Date date;
	PAYMENT_TYPE payment;
	double computeCost();

public:
	static double rateForKm;
	static double rateForExtraMin;
	Service(Customer* customer, double cost, Route* route, Date date, string payment);
	~Service();

	Customer* getCustomer();
	double getCost();
	Route* getRoute();
	Date getDate();
	PAYMENT_TYPE getPayment();

};

void showServices(vector<Service*> services);

void showAllServicesInfo(vector<Service*> services);









































#endif /* SERVICE_H_ */
