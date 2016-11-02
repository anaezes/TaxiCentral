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

void showAvailableRoutes(vector<Route*> routes)
{
	cout << endl << setw(10)<< "Source" << setw(20) << "Arrival" << setw(20) << "Distance"<< setw(20) << "Expected Time" << endl;
	cout << " --------------------------------------------------------------------- " << endl;

	  for(size_t i = 0; i < routes.size(); i++)
	    cout << setw(10) << routes.at(i)->getSource() << setw(20) << routes.at(i)->getArrival() << setw(15) << routes.at(i)->getDistance() << setw(20) << routes.at(i)->getExpectedTime() << endl;

	cout << endl;
}

