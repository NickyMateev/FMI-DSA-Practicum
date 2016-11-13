#include "Product.h"

void Product::copy(const Product& other)
{
	this->productType = other.productType;
	this->name = other.name;
	this->country = other.country;
	this->pricePerUnit = other.pricePerUnit;
	this->pricePerBundle = other.pricePerBundle;
	this->buyingPrice = other.buyingPrice;
	this->availableUnits = other.availableUnits;
}

void Product::print(std::ostream& os) const
{
	os << this->productType << " ";
	os << this->name<< " ";
	os << this->country<< " ";
	os << this->pricePerUnit<< " ";
	os << this->pricePerBundle<< " ";
	os << this->buyingPrice << " ";
	os << this->availableUnits << " ";
}

Product::Product(const char product_type, const std::string name, const std::string country, const double price_per_unit, const double price_per_bundle, const double buying_price, const int available_units)
{
	this->productType = product_type;
	this->name = name;
	this->country = country;
	this->pricePerUnit = price_per_unit;
	this->pricePerBundle = price_per_bundle;
	this->buyingPrice = buying_price;
	this->availableUnits = available_units;
}

Product::Product(const Product& other)
{
	this->copy(other);
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		this->copy(other);
	}

	return *this;
}

Product::~Product()
{
}

char Product::getProductType() const
{
	return productType;
}

std::string Product::getName() const
{
	return name;
}

std::string Product::getCountry() const
{
	return country;
}

double Product::getPricePerUnit() const
{
	return pricePerUnit;
}

double Product::getPricePerBundle() const
{
	return pricePerBundle;
}

double Product::getBuyingPrice() const
{
	return buyingPrice;
}

int Product::getAvailableUnits() const
{
	return availableUnits;
}


void Product::reduceAvailableUnits(int quantity)
{
	if (quantity > this->availableUnits)
	{
		this->availableUnits = 0;
	}
	else
	{
		this->availableUnits -= quantity;
	}
}

std::ostream& operator<<(std::ostream& os, const Product& obj)
{
	obj.print(os);
	return os;
}
