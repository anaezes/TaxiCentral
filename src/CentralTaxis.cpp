#include "CentralTaxis.h"


CentralTaxis::CentralTaxis(string name, string vouchersFile, string customersFile, string servicesFile, string routesFile) :
mapVouchers(),
customers(),
services(),
routes()
{
	this->name = name;
	this->vouchersFile = vouchersFile;
	this->customersFile = customersFile;
	this->servicesFile = servicesFile;
	this->routesFile =routesFile;

}

void CentralTaxis::loadVouchers(map<int,Voucher*> &mapVouchers)
{
	this->mapVouchers.insert(mapVouchers.begin(), mapVouchers.end());
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

Customer* CentralTaxis::insertNewCustomer()
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
		return newCustomer;

	}
	catch(InvalidNifException &e)
	{
		cout << e;
		return NULL;
	}
	catch(InvalidPhoneNumberException &e)
	{
		cout << e;
		return NULL;
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

Route* CentralTaxis::insertNewRoute(string source, string arrival)
{
	try{

		double distance = readDistance();

		int expectedTime = readExpectedTime();

		Route* newRoute = new Route(source,arrival,distance,expectedTime);

		routes.push_back(newRoute);
		saveRoutes();
		cout << endl << "Success, new route's was added. " << endl << endl;
		return newRoute;

	}
	catch(InvalidDistanceException &e)
	{
		cout << e;
		return NULL;
	}
	catch(InvalidExpectedTimeException &e)
	{
		cout << e;
		return NULL;
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
 * Funtions for Services
 *
 *
 * */

Customer* CentralTaxis::processCustomerNewService()
{

	//register customer or not ?
	cout << "1 for registered customer " << endl;
	cout << "2 for not registered customer " << endl;

	char option;
	bool valid = false;
	while(!valid)
	{
		cout << "> " ;
		cin >> option;
		option = tolower(option);

		if(option == '1' || option == '2')
			valid = true;
		else
		{
			cout << "Option not valid, try again";
			cin.ignore(20);
		}
	}

	if(option == '1')
	{
		try{
			unsigned int nif = readCustomerNif();
			Customer* customer = customerExists(nif, customers);

			if(customer != NULL)
				return customer;
		}
		catch(InvalidNifException &e)
		{
			cout << e;
		}
	}
	else
	{
		cout << TAB << "1 - For insert new client" << endl;
		cout << TAB << "2 - Proceed without registering" << endl;
		valid = false;
		while(!valid)
		{
			cout << "> " ;
			cin >> option;
			option = tolower(option);

			if(option == '1' || option == '2')
				valid = true;
			else
				cout << "Option not valid, try again";
		}

		if(option == '1')
		{
			Customer* customer = insertNewCustomer();
			return customer;
		}
	}

	return NULL;
}

Route* CentralTaxis::findRoute(string source, string arrival)
{
	std::transform(source.begin(), source.end(), source.begin(), ::tolower);
	std::transform(arrival.begin(), arrival.end(), arrival.begin(), ::tolower);

	size_t i = 0;
	while(i < routes.size())
	{
		string currArrival = routes[i]->getArrival();
		std::transform(currArrival.begin(), currArrival.end(), currArrival.begin(), ::tolower);
		string currSource = routes[i]->getSource();
		std::transform(currSource.begin(), currSource.end(), currSource.begin(), ::tolower);

		if( currArrival== arrival && currSource == source)
			return routes[i];
		i++;
	}

	return NULL;
}

Route* CentralTaxis::processRouteNewService()
{
	string source;
	cout << "Source: ";
	cin.ignore();
	getline(cin, source);

	string arrival;
	cout << "Arrival: ";
	getline(cin, arrival);

	Route* route = findRoute(source, arrival);

	if(route == NULL)
	{
		cout << "Route not exist yet...";
		cout << endl << "Please insert new route:" << endl;
		route = insertNewRoute(source, arrival);
	}

	return route;
}

int CentralTaxis::processTimeService()
{

	string input;
	double time = 0;

	cout << "Time of this service (minutes): ";

	bool valid = false;
	while(!valid)
	{
		cin >> input ;

		if(is_number(input))
		{
			std::stringstream convertor(input);
			convertor >> time;
			return time;
		}
		else
		{
			cout << endl << "Time not valid, try again: ";
			cin.ignore(100);
		}
	}

	return time;
}

string CentralTaxis::processTypeOfPayment(Customer* customer)
{
	char payment;

	cout << endl;
	cout << TAB_BIG << "Chose type of payment: " << endl;
	cout << TAB << "1- For Cash" << endl;
	cout << TAB << "2- For ATM" << endl ;
	bool valid = false;
	if(customer == NULL)
	{
		while(!valid)
		{
			cout << "> ";
			cin >> payment;

			if(payment == '1' || payment == '2')
				valid = true;
			else
				cout << endl << "payment type not valid, try again."<< endl;
			cin.ignore(100);
		}
	}
	else
	{
		cout << TAB << "3- For Credit" << endl;
		cout << TAB << "4- For end of month" << endl ;
		while(!valid)
		{
			cout << "> ";
			cin >> payment;


			if(payment == '1' || payment == '2' || payment == '3' || payment == '4')
				valid = true;
			else
				cout << endl << "payment type not valid, try again."<< endl;
			cin.ignore(100);
		}
	}

	switch (payment)
	{
	case '1':
		return "Cash";
		break;
	case '2':
		return "ATM";
		break;
	case '3':
		return "Credit";
		break;
	case '4':
		return "EndOfMonth";
		break;
	}

	return "EndOfMonth"; //security
}

void CentralTaxis::processExtraRateService(double &cost, string payment)
{
	double rate = 0;

	if(payment == "Credit")
	{
		rate = (ceil(0.02*cost*100))/100;
		cout << "Rate for Credit Payment = " << rate << endl;
	}

	else if(payment == "EndOfMonth")
	{
		rate = (ceil(0.05*cost*100))/100;
		cout << "Rate for End of month Payment = " << rate << endl;
	}

	cost += rate;
	cout << "Total cost: " << cost << endl;
}

bool CentralTaxis::useDiscount(Customer* customer, float discount)
{
	if(customer->getCustomerType() == Customer::CompanyCustomer)
		return true;


	cout << "You have a discount of : " << (100*discount) << " percentage." << endl;
	cout << "Do you want to use it ?" << endl;
	cout << "1 for yes " << endl;
	cout << "2 for no " << endl;

	char option;
	bool valid = false;
	while(!valid)
	{
		cout << "> " ;
		cin >> option;
		option = tolower(option);

		if(option == '1' || option == '2')
			valid = true;
		else
		{
			cout << "Option not valid, try again";
			cin.ignore(100);
		}
	}

	if(option == '1')
	{
		PrivateCustomer* tmp = dynamic_cast<PrivateCustomer*>(customer);
		tmp->resetPoints();
		return true;
	}
	else
		return false;
}

void CentralTaxis::insertNewService()
{
	/* A faltar: se cliente não for nulo verificar se tem descontos ativos */

	Customer* customer = processCustomerNewService();
	Route* route = processRouteNewService();
	Date dateOfDay(realTime());
	int time = processTimeService();
	string payment = processTypeOfPayment(customer);

	// computes cost and applies discount (if any)
	double cost = Service::rateForKm * route->getDistance() + (time - route->getExpectedTime()) * Service::rateForExtraMin;

	float discount = 0;
	if (customer != NULL)
	{
		discount = customer->getDiscount();
		if(!useDiscount(customer, discount))
			discount = 0;

		else
		{
			cout << "Cost of this service: " << cost << endl;
			cost -= cost*discount;
			cout << "Cost of this service with discount: " << cost << endl;
		}
	}

	if(discount == 0)
		cout << "Cost of this service: " << cost << endl;

	if(customer != NULL && (payment == "Credit" || payment == "EndOfMonth"))
		processExtraRateService(cost, payment);

	Service* newService = new Service(customer, cost, route, dateOfDay, time, payment);

	services.push_back(newService);
	saveService();
	cout << endl << "Success, new Service was added. " << endl;


	if(customer != NULL)
	{
		customer->accumulateService(newService);
		saveCustomers();
	}
}

void CentralTaxis::saveService()
{
	ofstream c_file;
	c_file.open(servicesFile);

	c_file << services.size() << endl;

	for(size_t i = 0; i < services.size() ; i++)
	{
		c_file << services[i]->toFileFormat();

		if(i < services.size()-1)
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

void printVoucherTable()
{
	cout << setw(12) << "NIF" << setw(20) << "Expires at" << setw(15) << " %" << endl;
	cout << " ---------------------------------------------------- " << endl;
}

void CentralTaxis::showDiscounts()
{
	if(mapVouchers.size() != 0)
	{
		printVoucherTable();
		for (auto const& it : mapVouchers)
			std::cout << setw(12) << it.first << setw(35) << it.second->getInformation() << endl;
	}
	else
		cout << "No vouchers available" << endl;
}




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

bool CentralTaxis::readVouchersFile(map<int, Voucher*> &mapVouchers)
{
	vector<string> vouchersLines;

	/* try to get the file lines */
	if(!readFile(vouchersFile, vouchersLines))
		return false;
	else
	{
		int nVouchers;
		stringstream ss(vouchersLines[0]);
		ss >> nVouchers;

		for(int i = 1; i <= nVouchers ; i++)
		{
			string substring;
			stringstream line(vouchersLines[i]);


			int nif;
			Date date;
			double value;

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
					date = currItem;
				else if(item == 2)
				{
					stringstream ss(currItem);
					ss >> value;
				}

				item++;
			}

			Voucher* newVoucher = new Voucher(date, value);
			mapVouchers.insert( std::pair<int,Voucher*>(nif,newVoucher));
		}
	}

	cout << "pim: " << mapVouchers.size() << endl;
	return true;
}

bool CentralTaxis::readCustomersFile(const map<int, Voucher*> &mapVouchers)
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
					currItem = currItem.substr(0, currItem.size());
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
			{
				Voucher* voucher = NULL;
				if(mapVouchers.find(nif) != mapVouchers.end())
					voucher = mapVouchers.find(nif)->second;
				newCustomer = new CompanyCustomer(nif, name, address, phoneNumber, cost, voucher);
			}
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
			Date date;
			unsigned int time;
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
					date = currItem;
				else if(item == 4)
				{
					stringstream ss(currItem);
					ss >> time;
				}
				else if(item == 5)
				{
					stringstream ss(currItem);
					ss >> cost;
				}
				else if(item == 6)
					paymentType = currItem.substr(0, currItem.size());

				item++;
			}

			size_t j;
			for(j = 0; j < customers.size(); j++)
			{
				if(customers[j]->getNif() == nif)
					break;
			}

			Route* routeService = new Route(origin, destination);

			Service* newService = new Service(customers[j], cost, routeService, date, time, paymentType);

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
