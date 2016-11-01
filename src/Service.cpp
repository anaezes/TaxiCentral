#include "Service.h"
#include <iostream>

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
