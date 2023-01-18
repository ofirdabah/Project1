#include "Status.h"
#define STRLEN 30


Status::Status(string newStatus)
{
	content=newStatus;
	if (content == "")
		throw Statusexception();
	char * time_str = new char[STRLEN];
	time_t t = time(NULL);
	ctime_s(time_str, STRLEN, &t);
	timeStr.assign(time_str, time_str + 24);
	delete []time_str;
}

Status::Status(string newStatus,string time)
{
	content = newStatus;
	timeStr = time;
}

 void  Status::printStatus () 
{
	cout << content << "\n";
	cout << timeStr << "\n";
}

Status::~Status(){}

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

 ostream& operator<<(ostream& os, const Status& s)
{
	return os << s.content << endl << s.timeStr;
}
