#include "Service.h"
#include <iostream>
#include <iomanip>

// define class Customer


double Service::rateForKm = 1.0;
double Service::rateForExtraMin = 0.5;


Service::Service(Customer* customer, double cost, Route* route, Date date, string payment)
{

	this->customer= customer;
	this->cost=cost;
	this->route=route;
	this->date= date;

	if(payment == "cash")
		this->payment = PAYMENT_TYPE::Cash;
	else if(payment == "ATM")
		this->payment = PAYMENT_TYPE::ATM;
	else if(payment == "credit")
		this->payment = PAYMENT_TYPE::Credit;
	else
		this->payment = PAYMENT_TYPE::EndOfMonth;

}

Service::~Service(){}

Customer* Service::getCustomer()
{
	return customer;
}

double Service::getCost()
{
	return cost;
}

Route* Service::getRoute()
{
	return route;
}

Date Service::getDate()
{
	return date;
}

PAYMENT_TYPE Service::getPayment()
 {
 	 return payment;
 }

double Service::computeCost()
{
	return 10.4;
}

void showServices(vector<Service*> services)
{
	 for(size_t i = 0; i < services.size() ; i++)
	    {
	      //cout << setw(5) << services.at(i)->getCustomer()->getNif();
	      cout << setw(12) << services.at(i)->getRoute().getSource();
	     // cout << setw(12) << services.at(i)->getRoute()->getArrival();
	      //cout << setw(10) << services.at(i)->getDate().getDate();
	     // cout << setw(14) << services.at(i)->getRoute()->getDistance();
	      //cout << setw(17) << services.at(i)->getRoute()->getExpectedTime();
	     // cout << setw(15) << services.at(i)->getPayment();

	}
}

void showAllServicesInfo(vector<Service*> services)
{

	 cout << setw(5) << "Customer NIF" << setw(12) << "Source" << setw(12) << "Arrival" << setw(10) << "Date";
	 cout << setw(14) << "Distance"  << setw(17) << "Expected Time"  << setw(15) << "Payment Type" <<  endl;
	 cout << " ----------------------------------------------------------------------------------------------- " << endl;

	 showServices(services);

	cout << endl << endl;
}
