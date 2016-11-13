#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Date.h"

using namespace std;

class Voucher
{
private:
	Date duration;
	double value;

public:
	Voucher(Date duration, double value);
	Date getDuration();
	double getValue();
	string getInformation();
};
