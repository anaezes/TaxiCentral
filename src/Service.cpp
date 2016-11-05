#include "Service.h"

double Service::rateForKm = 1.0;
double Service::rateForExtraMin = 0.5;


Service::Service(Customer* customer, double cost, Route* route, Date date, string payment)
{

	this->customer= customer;
	this->cost=cost;
	this->route=route;
	this->date= date;

	if(payment == "Cash")
		this->payment = PAYMENT_TYPE::Cash;
	else if(payment == "ATM")
		this->payment = PAYMENT_TYPE::ATM;
	else if(payment == "Credit")
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

string Service::getPaymentAsString()
{
	if(payment == PAYMENT_TYPE::Cash)
		return "cash";
	else if(payment == PAYMENT_TYPE::ATM )
		return "ATM";
	else if(payment == PAYMENT_TYPE::Credit)
		return "Credit";
	else
		return "EndOfMonth";
}

double Service::computeCost()
{
	return 10.4;
}

string Service::getInformation()
{
	stringstream information;
	information << setw(5) << this->getCustomer()->getNif();
	information << setw(20) << this->getRoute()->getSource();
	information << setw(20) << this->getRoute()->getArrival();
	information << setw(17) << this->getDate().dateAsString();
	information << setw(14) << this->getCost();
	information << setw(17) << this->getPaymentAsString();
	return information.str();
}


/*
   Sort transactions by increasing date
*/
bool compareByDate( Service* s1, Service* s2)
{
  return !(s1->getDate() >= s2->getDate());
}

void showAllServicesInfo(vector<Service*> services)
{
	std::sort(services.begin(), services.end(), compareByDate);
	printServicesTable();
	for(size_t i = 0; i < services.size() ; i++)
		cout << services[i]->getInformation() << endl;

	cout << endl << endl;
}

void printServicesTable()
{
	cout << setw(9) << "NIF" << setw(20) << "Source" << setw(20) << "Arrival" << setw(17) << "Date";
	cout << setw(14) << "Cost"  << setw(17)  << "Payment Type" <<  endl;
	cout << " ------------------------------------------------------------------------------------------------- " << endl;
}

void showServicesDay(vector<Service*> services)
{
	string date;
	bool service_found=false;
	bool date_valid=false;
	bool first_time=false;

	do {

	 cout <<"Please enter the day(day/month/year): "<< endl;
	 cin >> date;

	Date valid_date(date);

	if(!valid_date.isValid()){
		cout << "This date isn't valid." << endl;
	}
	else date_valid=true;

	} while(!date_valid);

	cout << endl << endl;

	for(int i=0; i < services.size();i++){

		if(services.at(i)->getDate() == date){
			if(!first_time){
				printServicesTable();
				service_found=true;
				cout << services.at(i)->getInformation() << endl;
				first_time=true;
			}
			else{
			first_time=true;
			service_found=true;
			cout << services.at(i)->getInformation() << endl;
			}
		}

	}

	if(!service_found)
		cout << "Services not found!" << endl;

}

void showServicesBetweenDays(vector<Service*> services)
{
	string date1,date2;
	bool service_found=false;
	bool date_valid=false;
	bool first_time=false;

	do {

		cout <<"Please enter the first day(day/month/year): "<< endl;
		cin >> date1;

		Date valid_date(date1);

		if(!valid_date.isValid()){
			cout << "This date isn't valid." << endl;
		}
		else date_valid=true;

	} while(!date_valid);


	date_valid=false;

	do {

		cout <<"Please enter the second day(day/month/year): "<< endl;
		cin >> date2;

		Date valid_date(date2);

		if(!valid_date.isValid()){
			cout << "This date isn't valid." << endl;
		}
		else date_valid=true;

	} while(!date_valid);

	cout << endl << endl;


	for(int i=0; i < services.size();i++)
	{

		if(services.at(i)->getDate()>= date1 && services.at(i)->getDate()<= date2)
		{
			if(!first_time){
				printServicesTable();
				service_found=true;
				cout << services.at(i)->getInformation() << endl;
				first_time=true;
			}
			else{
			first_time=true;
			service_found=true;
			cout << services.at(i)->getInformation() << endl;
			}
		}

	}

	if(!service_found)
		cout << "Services not found!" << endl;

}

void showCustomerServicesByNif(vector<Service*> services, vector<Customer*> customers)
{
	unsigned int nif = readCustomerNif();
	Customer* customer = customerExists(nif, customers);

	if(customer !=  NULL)
	{
		printServicesTable();

		for(int i=0; i < services.size();i++){
			if(services.at(i)->getCustomer()->getNif() == nif)
				cout << services.at(i)->getInformation() << endl;
		}

	}
	else cout << "Customer Services not found!" << endl << endl;

	/*
		catch(Customer::InvalidNifException &e)
		{
			cout << e;
		}
*/
}

void showCustomerServicesByName(vector<Service*> services, vector<Customer*> customers)
{
	string name;
	cout << "Name: " ;
	cin.ignore();
	getline(cin, name);
	cout << endl << endl;


	bool found = false;
	bool first_time=false;
	size_t i = 0;

	for(int i=0; i < services.size();i++){

		if(services.at(i)->getCustomer()->getName() == name){
			if(!first_time){
				printServicesTable();
				found=true;
				cout << services.at(i)->getInformation() << endl;
				first_time=true;
			}
			else{
			first_time=true;
			found=true;
			cout << services.at(i)->getInformation() << endl;
			}
		}

	}


	if(!found)
		cout << "Customer Services not found!" << endl << endl;

}
