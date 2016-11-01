#include "Service.h"
#include <iostream>

// define class Customer

Service::Service(Customer* customer, double cost, Route* route, Date date, string payment)
{

	this->customer= customer;
	this->cost=cost;
	this->route=route;
	this->date= date;
	this->payment= payment;

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

Route Service::getRoute()
{
	return route;
}

Date Service::getDate()
{
	return date;
}

string Service::getPayment()
 {
 	 return payment;
 }

