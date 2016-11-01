#include "Route.h"

#include <iostream>

// define class Route

Route::Route(string source, string arrival, double distance, double expectedTime)
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

double Route::getExpectedTime()
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

void Route::setDistance (double distance);
{
	this->distance = distance;
}

void Route::setExpectedTime(double expectedTime);
{
	this->expectedTime = expectedTime;
}
