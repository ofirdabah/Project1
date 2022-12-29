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


Date::Date(int day, int month, int year) noexcept (false)
{
    if (day < 1 || day > 31)
        throw Dayexception();
    if (month < 1 || month > 12)
        throw Monthexception();
    if (year < 1900 || year > 2022)
        throw Yearexception();
    this->day = day;
    this->month = month;
    this->year = year;

}








