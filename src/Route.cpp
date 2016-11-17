#include "Route.h"


// define class Route


Route::Route(string source, string arrival, double distance, int expectedTime)
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


int Route::getExpectedTime()
{
	return expectedTime;
}

string Route::getExpectedTimeinFormat()
{
	int hour = expectedTime / 60;
	int minutes = expectedTime %60;

	stringstream tmp;
	tmp << hour << 'h' << minutes << 'm';

	return tmp.str();
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

void Route::setExpectedTime(int expectedTime)
{
	this->expectedTime = expectedTime;
}


string Route::getInformation()
{

	stringstream information;
	information << setw(20) << this->getSource();
	information << setw(20) << this->getArrival();
	information << setw(17) << this->getDistance();
	information << setw(17) << this->getExpectedTimeinFormat();
	return information.str();
}


string Route::toFileFormat()
{
	stringstream information;

	information << this->getSource() << ";" <<this->getArrival() << ";"
			<< this->getDistance() << ";" << this->getExpectedTime();

	return information.str();
}





/*
 *
 * General functions for routes
 *
 *
 * */



double readDistance()
{
	string input;
	double distance;

	cout << "Distance of this route: ";
	cin >> input ;

	if(is_number(input))
	{
		std::stringstream convertor(input);
		convertor >> distance;
		return distance;
	}
	else
		throw InvalidDistanceException();

}

int readExpectedTime()
{

	string input;
	double expectedTime;

	cout << "Expected time of this route (minutes): ";
	cin >> input ;

	if(is_number(input))
	{
		std::stringstream convertor(input);
		convertor >> expectedTime;
		return expectedTime;
	}
	else
		throw InvalidExpectedTimeException();

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


