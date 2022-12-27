#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class DateException : public exception{};
class YearRange :public DateException {};
class MonthRange :public DateException {};
class DayRange :public DateException { public:DayRange() { cout << "Invalid day \n"; } };

class Date
{
	int day;
	int month;
	int year;

public:
	inline void setyear(int y)throw (YearRange);
	inline void setmonth(int m)throw (MonthRange);
	inline void setday(int d) throw (DayRange);

	inline const int getyear() const { return year; }
	inline const int getmonth() const { return month; }
	inline const int getday() const { return day; }

	void print() { cout << day << "/" << month << "/" << year; }
	Date();
	Date(int d, int m, int y);

};

#endif 