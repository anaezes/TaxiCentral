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


// Customers functions
void CentralTaxis::editCustomerName()
{
	unsigned int nif = validatInputCustomer();

	if(nif == 0)
		cout << endl << "ID not valid!" << endl << endl;
	else{
		size_t i = 0;
		bool found = false;
		while(!found)
		{
			if(nif == customers[i]->getNif())
				found = true;
			else
				i++;
		}

		if(!found)
			cout << "Customer not found! " << endl;
		else
		{
			string newName;
			cout << "New name: ";
			cin.ignore();
			getline(cin, newName);

			customers[i]->setName(newName);
			saveCustomers();
			cout << endl << "Success, customer was modify. " << endl << endl;
		}
	}
}


void CentralTaxis::editCustomerAddress()
{

}

void CentralTaxis::editCustomerPhoneNumber()
{

}

void CentralTaxis::removeCustomer()
{

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


void CentralTaxis::showDiscounts()
{}

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
	if(!readFile(customersFile, servicesLines))
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
					origin == currItem;
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
					paymentType = currItem;

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
			string expectedTime;

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
					expectedTime = currItem;

				item++;
			}


			Route* newRoute = new Route(source, arrival, distance, expectedTime);
			routes.push_back(newRoute);
		}
	}

	return true;
}
