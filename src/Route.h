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
	double expectedTime;

public:
	Route(string source, string arrival, double distance, double expectedTime);
	~Route();
	string getSource();
	string getArrival();
	double getDistance();
	double getExpectedTime();
	void setSource(string source);
	void setArrival(string arrival);
	void setDistance (double distance);
	void setExpectedTime(double expectedTime);

};
















































#endif /* ROUTE_H_ */
