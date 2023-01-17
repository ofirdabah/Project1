#include "Status.h"
#define STRLEN 30


Status::Status(string newStatus)
{
	content=newStatus;
	if (content == "")
		throw Statusexception();
	time_str = new char[STRLEN];
	time_t t = time(NULL);
	ctime_s(time_str, STRLEN, &t);

}

 void  Status::printStatus () 
{
	cout << content << "\n";
	cout << time_str << "\n";
}

Status::~Status()
{
	delete[]time_str;
}

bool Status::operator==(const Status& other) const
{
	if (content == other.content)
		return true;
}

bool Status::operator!=(const Status& other) const
{
	if (content != other.content)
		return true;
}