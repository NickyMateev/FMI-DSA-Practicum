#include "Electronics.h"

void Electronics::copy(const Electronics& other)
{
	this->warranty = other.warranty;
}

void Electronics::print(std::ostream& os) const
{
	Product::print(os);
	os << this->warranty;
}

Electronics::Electronics(const char product_type, const std::string name, const std::string country, const double price_per_unit, const double price_per_bundle, const double buying_price, const int available_units, const int warranty)
	: Product(product_type, name, country, price_per_unit, price_per_bundle, buying_price, available_units)
{
	this->warranty = warranty;
}

Electronics::Electronics(const Electronics& other) : Product(other)
{
	this->copy(other);
}

Electronics Electronics::operator=(const Electronics& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->copy(other);
	}
	
	return *this;
}

Electronics::~Electronics()
{
}

int Electronics::getWarranty() const
{
	return warranty;
}

std::ostream& operator<<(std::ostream& os, const Electronics& obj)
{
	obj.print(os);
	return os;
}