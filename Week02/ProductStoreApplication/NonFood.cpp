#include "NonFood.h"

void NonFood::copy(const NonFood& other)
{
	this->containsToxic = other.containsToxic;
}

void NonFood::print(std::ostream& os) const
{
	Product::print(os);
	os << containsToxic;
}

NonFood::NonFood(const char product_type, const std::string name, const std::string country, const double price_per_unit, const double price_per_bundle, const double buying_price, const int available_units, const bool contains_toxic)
	: Product(product_type, name, country, price_per_unit, price_per_bundle, buying_price, available_units),
	containsToxic(contains_toxic)
{
	this->containsToxic = contains_toxic;
}

NonFood::NonFood(const NonFood& other) : Product(other)
{
	this->copy(other);
}

NonFood& NonFood::operator=(const NonFood& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->copy(other);
	}

	return *this;
}

NonFood::~NonFood()
{
}

bool NonFood::getContainsToxic() const
{
	return containsToxic;
}

std::ostream& operator<<(std::ostream& os, const NonFood& obj)
{
	obj.print(os);
	return os;
}
