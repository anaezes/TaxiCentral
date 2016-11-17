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

string Voucher::getInformation()
{
	stringstream information;
	information << this->getDuration().dateAsString() << setw(15) << (this->getValue()*100);
	return information.str();

}

void Voucher::setValue(double value)
{
	this->value = value;
}

void Voucher::setDate(Date date)
{
	this->duration = date;
}

string Voucher::toFileFormat()
{
	stringstream information;

	information << getDuration().dateAsString()<< ";" << getValue();

	return information.str();
}
