/*
 * Menu.h
 *
 */

#ifndef MENU_H_
#define MENU_H_

#pragma once

#include <vector>
#include <string>

#include "Customer.h"
#include "Service.h"
#include "Route.h"
#include "Date.h"
#include "CentralTaxis.h"
#include "utilities.h"


unsigned short int customersMenu();

unsigned short int oneCustomerMenu();

unsigned short int editCustomerMenu();

unsigned short int serviceMenu();

unsigned short int discountsMenu();

unsigned short int mainMenu(vector<Customer>customers,vector<Service>services,string fileCustomers,string fileServices);












































#endif /* MENU_H_ */
