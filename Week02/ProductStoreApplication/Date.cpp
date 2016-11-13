#include "Date.h"


Date::Date() : Date(DEFAULT_DAY, DEFAULT_MONTH, DEFAULT_YEAR)
{
}

Date::Date(const short day, const short month, const short year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

short Date::getDay() const
{
	return day;
}

short Date::getMonth() const
{
	return month;
}

short Date::getYear() const
{
	return year;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return lhs.day == rhs.day
		&& lhs.month == rhs.month
		&& lhs.year == rhs.year;
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return !(lhs == rhs);
}


bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.year < rhs.year)
	{
		return true;
	}
	if (rhs.year < lhs.year)
	{
		return false;
	}
	if (lhs.month < rhs.month)
	{
		return true;
	}
	if (rhs.month < lhs.month)
	{
		return false;
	}

	return lhs.day < rhs.day;
}

bool operator<=(const Date& lhs, const Date& rhs)
{
	return !(rhs < lhs);
}

bool operator>(const Date& lhs, const Date& rhs)
{
	return rhs < lhs;
}

bool operator>=(const Date& lhs, const Date& rhs)
{
	return !(lhs < rhs);
}
