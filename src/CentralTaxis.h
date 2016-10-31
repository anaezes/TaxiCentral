/*
 * CentralTaxis.h
 *
 */

#ifndef CENTRALTAXIS_H_
#define CENTRALTAXIS_H_

#include <vector>
#include <string>
using namespace std;



class CentralTaxis
{
private:

public:
CentralTaxis();
void CentralTaxis::partitionCustomer(string line, vector<Customer> &customers);
bool CentralTaxis::readFileCustomers(vector<Customer> &customers, string &fileCustomers);
void CentralTaxis::partitionService(string line, vector<Service> &services);
bool CentralTaxis::readFileServices(vector<Service> &services, string &fileServices);
void CentralTaxis::partitionRoute(string line, vector<Route> &routes);
bool CentralTaxis::readFileRoute(vector<Route> &customers, string &fileRoutes);
};










































#endif /* CentralTaxis_H_ */
