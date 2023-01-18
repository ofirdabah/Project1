#define _CRT_SECURE_NO_WARNINGS
#ifndef STATUS_H
#define STATUS_H
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Statusexception : public exception
{
public:
	virtual const char* what() const override { return "Empty status is invalid!\n"; }
};

class Status
{
protected:
	string timeStr;
	string content;

public:

	Status(const Status& other) = delete;
	virtual void printStatus();
	
	Status(string newStatus);
	Status(string newStatus, string time);
	virtual ~Status();

	inline const string GetTime() const { return timeStr; }
	inline const string GetContent() const { return content; }

	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;

	 friend ostream& operator<<(ostream& os, const Status& d);
};
#endif 

