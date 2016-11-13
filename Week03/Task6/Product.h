#pragma once
#include <string>
#include <ostream>

class Product
{
private:
	int productID;
	std::string name;
	double price;
public:
	Product();
	Product(const int product_id, const std::string name, const double price);

	friend std::ostream& operator<<(std::ostream& os, const Product& obj);
};
