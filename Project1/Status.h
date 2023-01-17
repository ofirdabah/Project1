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
	char* time_str;
	string content;

public:

	Status(const Status& other) = delete;
	virtual void printStatus();
	
	Status(string newStatus);
	virtual ~Status();

	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
};
#endif 

