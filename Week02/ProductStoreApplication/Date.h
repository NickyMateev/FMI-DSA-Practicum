#pragma once

class Date
{
private:
	short day;
	short month;
	short year;

	static const short DEFAULT_DAY = 1;
	static const short DEFAULT_MONTH = 1;
	static const short DEFAULT_YEAR = 2010;
public:
	Date();
	Date(const short day, const short month, const short year);

	short getDay() const;
	short getMonth() const;
	short getYear() const;

	friend bool operator==(const Date& lhs, const Date& rhs);
	friend bool operator!=(const Date& lhs, const Date& rhs);
	friend bool operator<(const Date& lhs, const Date& rhs);
	friend bool operator<=(const Date& lhs, const Date& rhs);
	friend bool operator>(const Date& lhs, const Date& rhs);
	friend bool operator>=(const Date& lhs, const Date& rhs);
};
