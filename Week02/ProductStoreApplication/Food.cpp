#include "Food.h"

void Food::copy(const Food& other)
{
	this->expirationDate = other.expirationDate;
	this->sustainableToLowTemp = other.sustainableToLowTemp;
}

void Food::print(std::ostream& os) const
{
	Product::print(os);
	os << this->expirationDate.getDay() << " ";
	os << this->expirationDate.getMonth() << " ";
	os << this->expirationDate.getYear() << " ";
	os << this->sustainableToLowTemp << " ";
}

Food::Food(const char product_type, const std::string name, const std::string country, const double price_per_unit, const double price_per_bundle, const double buying_price, const int available_units, const Date expiration_date, const bool sustainable_to_low_temp)
	: Product(product_type, name, country, price_per_unit, price_per_bundle, buying_price, available_units)
{
	this->expirationDate = expiration_date;
	this->sustainableToLowTemp = sustainable_to_low_temp;
}

Food::Food(const Food& other) : Product(other)
{
	this->copy(other);
}

Food& Food::operator=(const Food& other)
{
	if(this != &other)
	{
		Product::operator=(other);
		this->copy(other);
	}

	return *this;
}

Food::~Food()
{
}

Date Food::getExpirationDate() const
{
	return expirationDate;
}

bool Food::isSustainableToLowTemp() const
{
	return sustainableToLowTemp;
}

std::ostream& operator<<(std::ostream& os, const Food& obj)
{
	obj.print(os);
	return os;
}