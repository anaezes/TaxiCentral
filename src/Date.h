/*
 * Date.h
 *
 */

#ifndef DATE_H_
#define DATE_H_

#include <vector>
#include <string>

using namespace std;

class Date
{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	string startTime;
	string endTime;

public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year, string startTime, string endTime);
	Date(unsigned int year, unsigned int month, unsigned int day);
	Date(string yearMonthDay);
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
	string getStartTime();
	string getEndTime();
	string getDate();
	void setDay(unsigned day);
	void setMonth(unsigned month);
	void setYear(unsigned year);
	void setStartTime(string startTime);
	void setEndTime(string endTime);
	void show();
	bool isLeapYear();
	unsigned int nDays();
	bool isValid();
	bool operator==(const Date& date);
	bool operator>(const Date &date);
	bool operator<(const Date &date);


};













































#endif /* DATE_H_ */
