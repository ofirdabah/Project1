#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Datexception : public exception
{
public:
	virtual const char* what() const override { return "Invalid date!"; }
};

class Yearexception : public Datexception
{
public:
virtual const char* what() const override {return "Invalid year!\n";}
};

class Monthexception : public Datexception
{
public:

	virtual const char* what() const override { return "Invalid month!\n"; }
};

class Dayexception : public Datexception
{
public:
	virtual const char* what() const override { return "Invalid Day!\n"; }
};

class Date
{
	int day;
	int month;
	int year;

public:
	inline void setyear(int y) noexcept (false);
	inline void setmonth(int m) noexcept (false);
	inline void setday(int d) noexcept (false);

	inline const int getyear() const { return year; }
	inline const int getmonth() const { return month; }
	inline const int getday() const { return day; }

	void print() { cout << day << "/" << month << "/" << year; }
	Date();
	Date(int day, int month, int year);

};

#endif 