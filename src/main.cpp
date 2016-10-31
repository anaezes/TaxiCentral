#include"Menu.h"
#include "Service.h"
#include "CentralTaxis.h"
#include "Customer.h"

#include<iostream>

using namespace std;

int main()
{

  CentralTaxis central;

  vector <Customer> customers;
  vector<Service> &services;

  string fileCustomers;
  string fileServices;

  central.requestFiles(fileCustomers, fileServices);

  mainMenu(customers,services,fileCustomers,fileServices);

  return 0;
}
