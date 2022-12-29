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
	char* time_str;
	string content;

public:

	Status(const Status& other) = delete;
	inline string getstatus() { return content; }
	void printStatus();
	
	Status(string newStatus);
	~Status();

	bool operator==(const Status& other) const;
	bool operator!=(const Status& other) const;
};
#endif 

