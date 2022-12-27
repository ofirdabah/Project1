#include "Date.h"
//
//void Date::setday(int d)throw (DayRange)
//{
//	if ((d < 1) || (d > 31))
//		throw DayRange();
//	day = d;
// 
// 
//}
//void Date::setmonth(int m)throw (MonthRange)
//{
//	if ((m < 1) || (m > 12))
//		throw MonthRange();
//	month = m;
//}
void Date::setyear(int y) throw (YearRange)
{
	if ((y < 1900) || (y > 2022))
		throw YearRange();
	year = y;
}

//------------------------------------------------//

Date::Date(int day, int month, int year) 
{
		this->setday(day);
		this->setmonth(month);
		this->setyear(year);
}