#include "Service.h"

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

string Service::getInformation()
{
	stringstream information;

	 //information << setw(5) << this->getCustomer()->getNif();
	 information << setw(12) << this->getRoute()->getSource();
	 information << setw(12) << this->getRoute()->getArrival();
	 information << setw(10) << this->getDate().getDate();
	 information << setw(14) << this->getRoute()->getDistance();
	 information << setw(17) << this->getRoute()->getExpectedTime();
	 information << setw(15) << this->getPayment();

	   return information.str();
}

void showServices(vector<Service*> services)
{

	 for(size_t i = 0; i < services.size() ; i++)
	    {
		 	 cout << services.at(i)->getInformation();
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
