#include "Date.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

// define class Date

Date::Date()
{
}

Date::Date(unsigned int day, unsigned int month, unsigned int year, string startTime, string endTime)
{
	setYear(year);
	setMonth(month);
	setDay(day);
	setStartTime(startTime);
	setEndTime(endTime);
}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date::Date(string yearMonthDay)
{
	sscanf(yearMonthDay.c_str(), "%d/%d/%d", &year, &month, &day);
}

unsigned int Date::getDay() const
{
	return day;
}

unsigned int Date::getMonth() const
{
	return month;
}

unsigned int Date::getYear() const
{
	return year;
}

string Date::getStartTime()
{
	return startTime;
}

string Date::getEndTime()
{
	return endTime;
}

string Date::getDate()
{
	stringstream ss;
	ss << to_string(year) << "/" << to_string(month) << "/" << to_string(day);
	return ss.str();
}

void Date::setDay(unsigned int day)
{
	this->day = day;
}

void Date::setMonth(unsigned int month)
{
	this->month = month;
}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

void Date::setStartTime(string startTime)
{
	this->startTime = startTime;
}
void Date::setEndTime(string endTime)
{
	this->endTime = endTime;
}

void Date::show()
{
	cout << year << "/" << month << "/" << day << endl;
}

bool Date::isLeapYear()
{

	if(year % 2 == 0 && year % 100 != 0)
		return true;
	else if(year % 400 == 0)
		return true;
	else
		return false;
}

unsigned int Date::nDays()
{
	if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if(isLeapYear())
			return 29;
		else
			return 28;
	}
	else
		return 31;
}

bool Date::isValid()
{
	if(day <= nDays() && (month > 0 && month < 13))
		return true;
	else
		return false;
}

bool Date::operator==(const Date& date)
{
	return year == date.getYear() && month == date.getMonth() && day == date.getDay();
}

bool Date::operator>(const Date &date)
{
	int date1 = year * 10000 + month * 100 + day;
	int date2 = date.getYear() * 10000 + date.getMonth() * 100 + date.getDay();

	return (date1 > date2);
}

bool Date::operator<(const Date &date)
{
	int date1 = year * 10000 + month * 100 + day;
	int date2 = date.getYear() * 10000 + date.getMonth() * 100 + date.getDay();

	return (date1 < date2);
}
