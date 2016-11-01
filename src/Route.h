/*
 * Route.h
 *
 */

#ifndef ROUTE_H_
#define ROUTE_H_

#include <vector>
#include <string>

using namespace std;

class Route
{
private:
	string source;
	string arrival;
	double distance;
	string expectedTime;

public:
	Route(string source, string arrival, double distance, string expectedTime);
	Route(string source, string arrival);
	~Route();
	string getSource();
	string getArrival();
	double getDistance();
	string getExpectedTime();
	void setSource(string source);
	void setArrival(string arrival);
	void setDistance(double distance);
	void setExpectedTime(string expectedTime);
};
















































#endif /* ROUTE_H_ */
