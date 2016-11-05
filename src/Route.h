/*
 * Route.h
 *
 */

#ifndef ROUTE_H_
#define ROUTE_H_

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Route
{
private:
	string source;
	string arrival;
	double distance;
	int expectedTime;

public:
	Route(string source, string arrival, double distance, int expectedTime);
	Route(string source, string arrival);
	~Route();
	string getSource();
	string getArrival();
	double getDistance();
	int getExpectedTime();
	string getExpectedTimeinFormat();
	void setSource(string source);
	void setArrival(string arrival);
	void setDistance(double distance);
	void setExpectedTime(int expectedTime);
	string getInformation();
	string toFileFormat();
};

class InvalidDistanceException
{
public:
	friend ostream & operator<<(std::ostream &out, InvalidDistanceException &e)
	{
		out << "Error: Distance not valid!" << endl << endl;

		return out;
	}
};

class InvalidExpectedTimeException
{
public:
	friend ostream & operator<<(std::ostream &out, InvalidExpectedTimeException &e)
	{
		out << "Error: Expected time not valid!" << endl << endl;

		return out;
	}
};

double readDistance();

int readExpectedTime();

void showAvailableRoutes(vector<Route*> routes);

void printRoutesTable();












































#endif /* ROUTE_H_ */
