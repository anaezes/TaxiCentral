/*
 * Menu.h
 *
 */

#pragma once


#include <vector>
#include <string>
using namespace std;

#include "Customer.h"
#include "Service.h"
#include "Route.h"
#include "Date.h"
#include "CentralTaxis.h"
#include "utilities.h"


unsigned short int customersMenu(CentralTaxis &central);

unsigned short int oneCustomerMenu(CentralTaxis &central);

unsigned short int editCustomerMenu(CentralTaxis &central);

unsigned short int serviceMenu(CentralTaxis &central);

unsigned short int discountsMenu(CentralTaxis &central);

unsigned short int mainMenu(CentralTaxis &central);

void cleanDisplay();
