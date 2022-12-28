#include "Date.h"

void Date::setday(int d)
{
	day = d;
}
void Date::setmonth(int m)
{
	month = m;
}
void Date::setyear(int y) 
{
	year = y;
}


//------------------------------------------------//


Date::Date(int day, int month, int year) throw (Datexception)
{
    if (day < 1 || day > 31)
        throw Datexception("Invalid day");
    if (month < 1 || month > 12)
        throw Datexception("Invalid month");
    if (year < 1900 || year > 2100)
        throw Datexception("Invalid year");
    this->day = day;
    this->month = month;
    this->year = year;

}








