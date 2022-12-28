#include "Date.h"

void Date::setday(int d)throw (Datexception)
{
	if ((d < 1) || (d > 31))
		throw Datexception("Invalid day");
	day = d;
}
void Date::setmonth(int m)throw (Datexception)
{
	if ((m < 1) || (m > 12))
		throw Datexception("Invalid month");
	month = m;
}
void Date::setyear(int y) throw (Datexception)
{
	if ((y < 1900) || (y > 2022))
		throw Datexception("Invalid year");
	year = y;
}

//------------------------------------------------//

Date::Date(int day, int month, int year) 
{
		this->setday(day);
		this->setmonth(month);
		this->setyear(year);
}