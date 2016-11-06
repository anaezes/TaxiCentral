#include "Customer.h"

/******************************************************/
/*             CUSTOMER CLASS FUNCTIONS               */
/******************************************************/


Customer::Customer(unsigned int nif, string name, string address, int phoneNumber)
{
	this->nif = nif;
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
}

Customer::~Customer()
{

}

string Customer::getName()
{
	return name;
}

string Customer::getAddress()
{
	return address;
}


int Customer::getPhoneNumber()
{

	return phoneNumber;
}

unsigned int Customer::getNif() const
{
	return nif;
}

void Customer::setName(string name)
{
	this->name= name;
}

void Customer::setAddress(string address)
{
	this->address= address;
}

void Customer::setPhoneNumber(int phoneNumber)
{
	this->phoneNumber=phoneNumber;
}






/******************************************************/
/*           CUSTOMERS GENERAL FUNCTIONS              */
/******************************************************/


/*
   Validates all id inputs customers
 */
unsigned int readCustomerNif()
{
	string input;
	unsigned int nif;

	cout << "NIF customer: ";
	cin >> input ;

	std::stringstream convertor(input);

	if(is_number(input))
	{
		std::stringstream convertor(input);
		convertor >> nif;
		return nif;
	}
	else
		throw InvalidNifException();

}

unsigned int readCustomerPhoneNumber()
{
	string input;
	unsigned int phone;

	cout << "Phone number: ";
	cin >> input ;

	std::stringstream convertor(input);

	if(is_number(input))
	{
		std::stringstream convertor(input);
		convertor >> phone;
		return phone;
	}
	else
		throw InvalidPhoneNumberException();

}

/*
  Function used while sorting customers
  by name.
 */
bool compareByName( Customer* name_a,Customer* name_b)
{
	return name_a->getName() < name_b->getName();
}


void printCustomerTable()
{
	cout << setw(3) << "TYPE" << setw(14) << "NIF" << setw(25) << "Name" << setw(54) << "Address"
			<< setw(20) << "Phone" << setw(20) << "Points/Cost" << endl;
	cout << " ----------------------------------------------------------------"
			"-------------------------------------------------------------------------- " << endl;
}
/*
  Function used while sorting customers
  by name.
 */

void showAllCustomersInfo(vector<Customer*> customers)
{

	std::sort(customers.begin(), customers.end(), compareByName);

	printCustomerTable();
	for(size_t i = 0; i < customers.size() ; i++)
		cout << customers[i]->getInformation();

	cout << endl << endl;
}

string Customer::getInformation()
{
	stringstream information;
	information << setw(15) << this->getNif();
	information << setw(25) << this->getName();
	information << setw(55) << this->getAddress();
	information << setw(20) << this->getPhoneNumber();
	return information.str();
}


/*
 * returns a string with all information
 * of the customer in the format needed
 */
string Customer::toFileFormat()
{
	stringstream information;
	information << this->getNif() << ";" <<this->getName() << ";"
			<< this->getAddress() << ";" << this->getPhoneNumber();

	return information.str();
}

Customer* customerExists(unsigned int nif, vector<Customer*> customers)
{
	for(size_t i= 0 ; i < customers.size(); i++)
	{
		if(customers[i]->getNif() == nif)
			return customers[i];
	}

	return NULL;
}

void showCustomersInfoByNif(vector<Customer*> customers)
{
	try {
		unsigned int nif = readCustomerNif();
		Customer* customer = customerExists(nif, customers);

		if(customer !=  NULL)
		{
			printCustomerTable();
			cout << customer->getInformation() << endl;
		}
		else
			cout << "Customer not found!" << endl << endl;
	}
	catch(InvalidNifException &e)
	{
		cout << e;
	}
}

void showCustomersInfoByName(vector<Customer*> customers)
{
	string name;
	cout << "Name: " ;
	cin.ignore();
	getline(cin, name);
	cout << endl << endl;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	bool found = false;
	size_t i = 0;
	while(!found && i < customers.size())
	{

		string nameCustomer = customers[i]->getName();
		std::transform(nameCustomer.begin(), nameCustomer.end(), nameCustomer.begin(), ::tolower);

		if(nameCustomer == name)
			found = true;
		else
			i++;
	}

	if(found)
	{
		printCustomerTable();
		cout << customers[i]->getInformation() << endl;
	}
	else
		cout << "Customer not found!" << endl;
}
