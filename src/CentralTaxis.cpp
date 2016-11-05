#include "CentralTaxis.h"


CentralTaxis::CentralTaxis(string name, string customersFile, string servicesFile, string routesFile) :
customers(),
services(),
routes()
{
	this->name = name;
	this->customersFile = customersFile;
	this->servicesFile = servicesFile;
	this->routesFile =routesFile;
}

vector<Customer*> CentralTaxis::getCustomers() const
{
	return customers;
}


vector<Service*> CentralTaxis::getServices() const
{
	return services;
}

vector<Route*> CentralTaxis::getRoutes() const
{
	return routes;
}

string CentralTaxis::getCustomersFileName() const
{
	return customersFile;
}

string CentralTaxis::getServicesFileName() const
{
	return servicesFile;
}

void CentralTaxis::addCustomer(Customer* customer)
{

}

void CentralTaxis::addService(Service* service)
{
}


/*
 *
 * Functions for Customers
 *
 *
 * */
void CentralTaxis::editCustomerName()
{
	try{
		unsigned int nif = readCustomerNif();

		Customer* customer = customerExists(nif, customers);

		if(customer ==  NULL)
			cout << "Customer not found! " << endl << endl;
		else
		{
			string newName;
			cout << "New name: ";
			cin.ignore();
			getline(cin, newName);

			customer->setName(newName);
			saveCustomers();
			cout << endl << "Success, customer's name was modified. " << endl << endl;
		}
	}
	catch(InvalidNifException &e)
	{
		cout << e;
	}
}


void CentralTaxis::editCustomerAddress()
{
	try{
		unsigned int nif = readCustomerNif();

		Customer* customer = customerExists(nif, customers);

		if(customer ==  NULL)
			cout << "Customer not found! " << endl << endl;
		else
		{
			string newAddress;
			cout << "New address: ";
			cin.ignore();
			getline(cin, newAddress);

			customer->setAddress(newAddress);
			saveCustomers();
			cout << endl << "Success, customer's address was modified. " << endl << endl;
		}
	}
	catch(InvalidNifException &e)
	{
		cout << e;
	}
}

void CentralTaxis::editCustomerPhoneNumber()
{
	try{
		unsigned int nif = readCustomerNif();

		Customer* customer = customerExists(nif, customers);

		if(customer ==  NULL)
			cout << "Customer not found! " << endl << endl;
		else
		{
			int newPhone = readCustomerPhoneNumber();

			customer->setPhoneNumber(newPhone);
			saveCustomers();
			cout << endl << "Success, customer's phone number was modified. " << endl << endl;
		}

	}
	catch(InvalidNifException &e)
	{
		cout << e;
	}
	catch(InvalidPhoneNumberException &e)
	{
		cout << e;
	}
}

void CentralTaxis::removeCustomer()
{
	try{
		unsigned int nif = readCustomerNif();

		bool found = false;
		size_t i = 0;
		while (i < customers.size() && !found)
		{
			if(customers[i]->getNif() == nif)
			{
				found = true;
				delete customers[i];
				customers[i] = NULL;
				customers.erase(customers.begin()+i);
			}
			else i++;
		}

		if(found)
		{
			saveCustomers();
			cout << endl << "Success, customer's was removed. " << endl << endl;
		}
		else
			cout << "Customer not found! " << endl << endl;
	}
	catch(InvalidNifException &e)
	{
		cout << e;
	}
}

void CentralTaxis::insertNewCustomer()
{
	try{

		char typeCustomer;
		bool typeValid = false;
		cout << "Type of Customer - 'P' for Private or 'C' for Company : ";

		while(!typeValid)
		{

			cin.ignore();
			cin >> typeCustomer;

			if(typeCustomer == 'P' || typeCustomer == 'C')
				typeValid = true;
			else
				cout << "Type of Customer wrong, try again : ";

		}

		unsigned int nif = readCustomerNif();

		string name;
		cout << "Name: ";
		cin.ignore();
		getline(cin, name);

		string address;
		cout << "Address: ";
		getline(cin, address);

		unsigned int phoneNumber = readCustomerPhoneNumber();

		Customer* newCustomer;
		if(typeCustomer == 'P')
			newCustomer = new PrivateCustomer(nif, name, address, phoneNumber, 0);
		else
			newCustomer = new CompanyCustomer(nif, name, address, phoneNumber, 0);

		customers.push_back(newCustomer);
		saveCustomers();
		cout << endl << "Success, new customer's was added. " << endl << endl;

	}
	catch(InvalidNifException &e)
	{
		cout << e;
	}
	catch(InvalidPhoneNumberException &e)
	{
		cout << e;
	}
}

/*
  Save customers in file after modification
 */
void CentralTaxis::saveCustomers()
{
	ofstream c_file;
	c_file.open(customersFile);

	c_file << customers.size() << endl;

	for(size_t i = 0; i < customers.size() ; i++)
	{
		c_file << customers[i]->toFileFormat();

		if(i < customers.size()-1)
			c_file << endl;
	}

	c_file.close();
}


/*
 *
 * Functions for Routes
 *
 *
 * */

void CentralTaxis::removeRoute()
{

	string source;
	cout << "Insert source: ";
	cin.ignore();
	getline(cin,source);
	std::transform(source.begin(), source.end(), source.begin(), ::tolower);

	string arrival;
	cout << "Insert arrival: ";
	getline(cin,arrival);
	std::transform(arrival.begin(), arrival.end(), arrival.begin(), ::tolower);

	size_t i = 0;
	bool found = false;

	while(!found && i < routes.size())
	{
		string currArrival = routes[i]->getArrival();
		std::transform(currArrival.begin(), currArrival.end(), currArrival.begin(), ::tolower);

		string currSource = routes[i]->getSource();
		std::transform(currSource.begin(), currSource.end(), currSource.begin(), ::tolower);

		if(currArrival == arrival && currSource == source)
		{
			found = true;
			delete routes[i];
			routes[i] = NULL;
			routes.erase(routes.begin()+i);
		}
		i++;
	}

	if(found)
	{
		saveRoutes();
		cout << endl << "Success, routes's was removed. " << endl << endl;
	}
	else
		cout << "Route not found! " << endl << endl;
}

void CentralTaxis::insertNewRoute()
{
	try{
		string source;
		cout << "Source: ";
		cin.ignore();
		getline(cin, source);
		cout << endl;

		string arrival;
		cout << "Arrival: ";
		getline(cin, arrival);
		cout << endl;

		double distance = readDistance();

		int expectedTime = readExpectedTime();

		Route* newRoute = new Route(source,arrival,distance,expectedTime);

		routes.push_back(newRoute);
		saveRoutes();
		cout << endl << "Success, new route's was added. " << endl << endl;

	}
	catch(InvalidDistanceException &e)
	{
		cout << e;
	}
	catch(InvalidExpectedTimeException &e)
	{
		cout << e;
	}
}

void CentralTaxis::saveRoutes()
{
	ofstream c_file;
	c_file.open(routesFile);

	c_file << routes.size() << endl;

	for(size_t i = 0; i < routes.size() ; i++)
	{
		c_file << routes[i]->toFileFormat();

		if(i < routes.size()-1)
			c_file << endl;
	}

	c_file.close();
}









/*
 *
 * Funtions for Discounts
 *
 *
 * */

void CentralTaxis::showDiscounts()
{}











/*
 *
 *  Functions to read files
 *
 *
 * */











/*
  Reads a given file and separates it to a vector
  of its lines. Returns true if success.
 */
bool CentralTaxis::readFile(const string &fileName, vector<string> &fileLines)
{
	ifstream cFile;
	string line;

	/* try to open the file */
	cFile.open(fileName.c_str());

	if(!cFile.is_open())
		return false;
	else
	{
		/* Read file content */
		while(getline(cFile, line))
			fileLines.push_back(line); /*store line in the vector*/
		cFile.close();
		return true;
	}
}

bool CentralTaxis::readCustomersFile()
{
	vector<string> customersLines;

	/* try to get the file lines */
	if(!readFile(customersFile, customersLines))
		return false;
	else
	{
		int nCustomers;
		stringstream ss(customersLines[0]);
		ss >> nCustomers;

		for(int i = 1; i <= nCustomers ; i++)
		{
			string substring;
			stringstream line(customersLines[i]);

			string typeCustomer;
			unsigned int nif;
			string name;
			string address;
			int phoneNumber;
			int points;
			double cost;

			int item = 0;
			string currItem;
			while(getline(line,currItem, ';'))
			{
				if(item == 0)
					typeCustomer = currItem;
				else if(item == 1)
				{
					stringstream ss(currItem);
					ss >> nif;
				}
				else if(item == 2)
					name = currItem;
				else if(item == 3)
					address = currItem;
				else if(item == 4)
				{
					stringstream ss(currItem);
					ss >> phoneNumber;
				}
				else if(item == 5)
				{
					currItem = currItem.substr(0, currItem.size()-1);
					stringstream ss(currItem);
					if(typeCustomer == "P")
						ss >> points;
					else
						ss >> cost;
				}

				item++;
			}


			Customer* newCustomer;
			if(typeCustomer == "P")
				newCustomer = new PrivateCustomer(nif, name, address, phoneNumber, points);
			else
				newCustomer = new CompanyCustomer(nif, name, address, phoneNumber, cost);

			customers.push_back(newCustomer);
		}
	}

	return true;
}

bool CentralTaxis::readServicesFile()
{
	vector<string> servicesLines;

	/* try to get the file lines */
	if(!readFile(servicesFile, servicesLines))
		return false;
	else
	{
		int nCustomers;
		stringstream ss(servicesLines[0]);
		ss >> nCustomers;

		for(int i = 1; i <= nCustomers ; i++)
		{
			string substring;
			stringstream line(servicesLines[i]);

			unsigned int nif;

			string origin;
			string destination;

			string startTime;
			string endTime;

			double cost;
			string paymentType;
			Date date1;
			int item = 0;
			string currItem;
			while(getline(line,currItem, ';'))
			{
				if(item == 0)
				{
					stringstream ss(currItem);
					ss >> nif;
				}
				else if(item == 1)
					origin = currItem;
				else if(item == 2)
					destination = currItem;
				else if(item == 3)
					date1 = currItem;
				else if(item == 4)
					startTime = currItem;
				else if(item == 5)
					endTime = currItem;
				else if(item == 6)
				{
					stringstream ss(currItem);
					ss >> cost;
				}
				else if(item == 7)
					paymentType = currItem.substr(0, currItem.size()-1);

				item++;
			}

			size_t j;
			for(j = 0; j < customers.size(); j++)
			{
				if(customers[j]->getNif() == nif)
					break;
			}

			Route* routeService = new Route(origin, destination);

			Service* newService = new Service(customers[j], cost, routeService, date1, paymentType);

			services.push_back(newService);
		}
	}

	return true;
}

bool CentralTaxis::readRoutesFile()
{
	vector<string> routesLines;

	/* try to get the file lines */
	if(!readFile(routesFile, routesLines))
		return false;
	else
	{
		int nRoutes;
		stringstream ss(routesLines[0]);
		ss >> nRoutes;

		for(int i = 1; i <= nRoutes ; i++)
		{
			string substring;
			stringstream line(routesLines[i]);

			string source;
			string arrival;
			double distance;
			int expectedTime;

			int item = 0;
			string currItem;
			while(getline(line,currItem, ';'))
			{
				if(item == 0)
					source = currItem;
				else if(item == 1)
					arrival = currItem;
				else if(item == 2)
				{
					stringstream ss(currItem);
					ss >> distance;
				}
				else if(item == 3)
				{
					stringstream ss(currItem);
					ss >> expectedTime;
				}
				item++;
			}


			Route* newRoute = new Route(source, arrival, distance, expectedTime);
			routes.push_back(newRoute);
		}
	}

	return true;
}
