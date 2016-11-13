#include "Product.h"


Product::Product() : Product(0, "empty", 0.0)
{
}

Product::Product(const int product_id, const std::string name, const double price)
{
	this->productID = product_id;
	this->name = name;
	this->price = price;
}

std::ostream& operator<<(std::ostream& os, const Product& obj)
{
	os << obj.productID << " " << obj.name << " " << obj.price;
	return os;
}
