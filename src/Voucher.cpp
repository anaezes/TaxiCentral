#include "Voucher.h"

Voucher::Voucher(Date duration, double value)
{
	this->duration = duration;
	this-> value = value;
}

Date Voucher::getDuration()
{
	return duration;
}

double Voucher::getValue()
{
	return value;
}
