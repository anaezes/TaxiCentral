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

bool CentralTaxis::editCustomer(unsigned int nif)
{
	return true;
}

bool CentralTaxis::removeCustomer(unsigned int nif)
{
	return true;
}

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

			Route route;
			Date date;
			string startTime;
			string endTime;

			double cost;
			string paymentType;

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
					date(currItem);
				else if(item == 4)
					startTime = currItem;
				else if(item == 5)
					endTime = currItem;
				else if(item == 5)
				{
					stringstream ss(currItem);
					ss >> cost;
				}
				else if(item == 6)
					paymentType = currItem;

				item++;
			}
			size_t i;
			for(i = 0; i < customers.size(); i++)
			{
				if(customers[i]->getNif() == nif)
					break;
			}

			Route* routeService = new Route(origin, destination);


			Service* newService = new Service(customers[i],cost, routeService, date, paymentType);

			services.push_back(newService);
		}
	}


	return true;
}

bool CentralTaxis::readRoutesFile()
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
