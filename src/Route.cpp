#include "Route.h"


// define class Route


Route::Route(string source, string arrival, double distance, string expectedTime)
{
	this->source = source;
	this->arrival = arrival;
	this->distance = distance;
	this->expectedTime = expectedTime;
}

Route::Route(string source, string arrival)
{
	this->source = source;
	this->arrival = arrival;
}


Route::~Route() {}

string Route::getSource()
{
	return source;
}

string Route::getArrival()
{
	return arrival;
}

double Route::getDistance()
{
	return distance;
}


string Route::getExpectedTime()
{
	return expectedTime;
}

void Route::setSource(string source)
{
	this->source = source;
}

void Route::setArrival(string arrival)
{
	this->arrival = arrival;
}

void Route::setDistance(double distance)
{
	this->distance=distance;
}

void Route::setExpectedTime(string expectedTime)
{
	this->expectedTime = expectedTime;
}


string Route::getInformation()
{

	stringstream information;
	information << setw(20) << this->getSource();
	information << setw(20) << this->getArrival();
	information << setw(17) << this->getDistance();
	information << setw(17) << this->getExpectedTime();
	return information.str();
}


void showAvailableRoutes(vector<Route*> routes)
{
	printRoutesTable();

	  for(size_t i = 0; i < routes.size(); i++)
		 cout << routes[i]->getInformation() << endl;

	cout << endl << endl;
}

void printRoutesTable()
{
	cout << endl << setw(20)<< "Source" << setw(20) << "Arrival" << setw(17) << "Distance"<< setw(17) << "Expected Time" << endl;
		cout << " ----------------------------------------------------------------------------- " << endl;
}
