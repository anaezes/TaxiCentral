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

//Customer* CentralTaxis::addCustomer(string name, string adress, unsigned int nif)
//{
//
//}
//Service* CentralTaxis::addService()
//{
//}
//bool CentralTaxis::editCustomer()
//{
//}
//bool CentralTaxis::removeCustomer()
//{
//}

void CentralTaxis::partitionCustomer(string line, vector<Customer> &customers)
{
  /*Function to separate elements of structure of customers, with the desired format (nif ; name ; address ; phone number ; points) and puts them in a vector*/
 
  size_t l = line.find_first_of(';'); /*Determines the size until you find the first semicolon*/
  string nif = line.substr(0, (l - 1)); /*Separates the first element (nif) of the rest of the elements, that is, extract the first semicolon*/
 
  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
  l = line.find_first_of(';'); /*Find the second semicolon*/
  string name = line.substr(0, (l - 1)); /*Separates the second element (name) of the rest of the elements*/
 
 
  line = line.substr(l + 2); /*The line happens to be from space after the second semicolon*/
  l = line.find_first_of(';'); /*Find the third semicolon*/
  string address = line.substr(0, l - 1); /*Separates the third element (address) of the rest of the elements*/
 
  line = line.substr(l + 2); /*The line happens to be from space after the second semicolon*/
  l = line.find_first_of(';'); /*Find the third semicolon*/
  string phone_number = line.substr(0, l - 1); /*Separates the fourd element (phone number) of the rest of the elements*/
   
  string points = line.substr(l + 2); /*Extracts the rest of the line (points)*/
 
 
  const char * c = nif.c_str();
  unsigned int number = atoi(c); //Convert string to integer

  const char * c1 = phone_number.c_str();
  int number2 = atoi(c1);

  const char * c2 = points.c_str();
  int number3 = atoi(c2); //Convert string to int
 
  /*Correspondence between the parameters of the class and the elements separated and converted into string*/
 
  Customer* newCustomer = new Customer(number, name, address, number2, number3);
 
 
  customers.push_back(newCustomer); //Inserts in the vector customers customer class
 
}
 
bool CentralTaxis::readFileCustomers(vector<Customer> &customers, string &customersFile)
{
  /*Function that reads the contents of a text file, line by line*/
 
  ifstream fin;
  string line;
  int numberTotal;
 
  fin.open(customersFile); /*Open the file; exit program if the file couldn't be opened*/
  if (!fin.is_open())
    return false;
 
  /*Read each line of the file*/
 
  getline(fin, line, '\n');
  numberTotal = atoi(line.c_str());
 
  while (getline(fin, line))
    {
      if (line.size() > 1)/*If the size of line is > 1, calls the function partitionCustomer*/
	partitionCustomer(line, customers);
    }
 
  fin.close(); /*Close the file*/
}
 
void CentralTaxis::partitionService(string line, vector<Service> &services)
{
//  /*Function to separate elements of structure of services, with the desired format (nif ; source ; destiny ; date ; start time ; end time ; cost ; type of payment) and puts them in a vector*/
//
//  size_t l = line.find_first_of(';'); /*Determines the size until you find the first semicolon.*/
//  string nif = line.substr(0, (l - 1)); /*Separates the first element (nif) of the rest of the elements, that is, extract the first semicolon*/
//
//  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
//  l = line.find_first_of(';'); /*Find the second semicolon*/
//  string source = line.substr(0, (l - 1)); /*Separates the second element (source)  of the rest of the elements, that is, extract the first semicolon*/
//
//  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
//  l = line.find_first_of(';'); /*Find the second semicolon*/
//  string destiny = line.substr(0, (l - 1)); /*Separates the third element (destiny)  of the rest of the elements, that is, extract the first semicolon*/
//
//  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
//  l = line.find_first_of(';'); /*Find the second semicolon*/
//  string date = line.substr(0, (l - 1)); /*Separates the fourd element (date)  of the rest of the elements, that is, extract the first semicolon*/
//
//  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
//  l = line.find_first_of(';'); /*Find the second semicolon*/
//  string start_time = line.substr(0, (l - 1)); /*Separates the fifth element (start time)  of the rest of the elements, that is, extract the first semicolon*/
//
//  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
//  l = line.find_first_of(';'); /*Find the second semicolon*/
//  string end_time = line.substr(0, (l - 1)); /*Separates the sixth element (end time)  of the rest of the elements, that is, extract the first semicolon*/
//
//  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
//  l = line.find_first_of(';'); /*Find the second semicolon*/
//  string cost = line.substr(0, (l - 1)); /*Separates the seventh element (cost)  of the rest of the elements, that is, extract the first semicolon*/
//
//  string type_payment = line.substr(l + 2); /*Extracts the rest of the line (type of payment)*/
//
//
//  const char * c = nif.c_str();
//  int number = atoi(c); //Convert string to integer
//
//  const char * c1 = cost.c_str();
//  float number2 = stof(c1); //Convert string to float
//
//  /*Correspondence between the parameters of the structure and the elements separated and converted into string*/
//
//  Service object;
//
//  object.setNif(number);
//  object.setSource(source);
//  object.setDestiny(destiny);
//  object.setDate(date);
//  object.setStartTime(start_time);
//  object.setEndTime(end_time);
//  object.setCost(number2);
//  object.setTypePayment(type_payment);
//
//  services.push_back(object); /*Inserts in the vector services, the structure of services*/
   
}
 
bool CentralTaxis::readFileServices(vector<Service> &services, string &fileServices)
{
//  /*Function that reads the contents of a text file, line by line*/
//
//  ifstream fin;
//  string line;
//  int numberTotal;
//
//
//  fin.open(fileServices); /*Open the file; exit program if the file couldn't be opened*/
//  if (!fin.is_open())
//    {
//      return false;
//    }
//
//  /*Read each line of the file*/
//
//  getline(fin, line, '\n');
//  numberTotal = atoi(line.c_str());
//
//  while (getline(fin, line))
//    {
//      if (line.size() > 1) /*If the size of line is > 0, calls the function partitionService*/
//	partitionService(line, services);
//    }
//
//  fin.close(); /*Close the file*/
}

//void CentralTaxis::partitionRoute(string line, vector<Route> &routes)
//{
//  /*Function to separate elements of structure of routes, with the desired format (source ; destiny ; distance (km) ; expected time) and puts them in a vector*/
//
//  size_t l = line.find_first_of(';'); /*Determines the size until you find the first semicolon.*/
//  string source = line.substr(0, (l - 1)); /*Separates the first element (source) of the rest of the elements, that is, extract the first semicolon*/
//
//  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
//  l = line.find_first_of(';'); /*Find the second semicolon*/
//  string destiny = line.substr(0, (l - 1)); /*Separates the second element (destiny)  of the rest of the elements, that is, extract the first semicolon*/
//
//  line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
//  l = line.find_first_of(';'); /*Find the second semicolon*/
//  string distance = line.substr(0, (l - 1)); /*Separates the third element (distance)  of the rest of the elements, that is, extract the first semicolon*/
//
//  string expected_time = line.substr(l + 2); /*Extracts the rest of the line (expected_time)*/
//
//
//  const char * c = source.c_str();
//  int number = atoi(c); //Convert string to integer
//
//  const char * c1 = distance.c_str();
//  float number2 = stof(c1); //Convert string to integer
//
//  /*Correspondence between the parameters of the structure and the elements separated and converted into string*/
//
//  Service object;
//
//  object.setSource(source);
//  object.setDestiny(destiny);
//  object.setDistance(distance);
//  object.setExpectedTime(expected_time);
//
//  routes.push_back(object); /*Inserts in the vector services, the structure of services*/
//}
//
//bool CentralTaxis::readFileRoute(vector<Route> &routes, string &fileRoutes)
//{
//  /*Function that reads the contents of a text file, line by line*/
//
//  ifstream fin;
//  string line;
//  int numberTotal;
//
//
//  fin.open(fileRoutes); /*Open the file; exit program if the file couldn't be opened*/
//  if (!fin.is_open())
//    {
//      return false;
//    }
//
//  /*Read each line of the file*/
//
//  getline(fin, line, '\n');
//  numberTotal = atoi(line.c_str());
//
//  while (getline(fin, line))
//    {
//      if (line.size() > 1) /*If the size of line is > 0, calls the function partitionService*/
//	partitionRoute(line, routes);
//    }
//
//  fin.close(); /*Close the file*/
//}
