#ifndef DATE_H
#define DATE_H

#include <iostream>
/
using namespace std;

class Datexception : public exception
{
private:
	string message;

public:
	Datexception(const string& message) : message(message) {}

	const char* what() const
	{
		return message.c_str();
	}
};

class Date
{
	int day;
	int month;
	int year;

public:
	inline void setyear(int y)throw (Datexception);
	inline void setmonth(int m)throw (Datexception);
	inline void setday(int d) throw (Datexception);

	inline const int getyear() const { return year; }
	inline const int getmonth() const { return month; }
	inline const int getday() const { return day; }

	void print() { cout << day << "/" << month << "/" << year; }
	Date();
	Date(int day, int month, int year);

};

#endif 