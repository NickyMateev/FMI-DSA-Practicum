#pragma once
#include "Product.h"
#include <ostream>

class Electronics : public Product 
{
private:
	int warranty;

	void copy(const Electronics& other);
protected:
	virtual void print(std::ostream& os) const;
public:
	Electronics(const char product_type, const std::string name, const std::string country, const double price_per_unit, const double price_per_bundle, const double buying_price, const int available_units, const int warranty);
	Electronics(const Electronics& other);
	Electronics operator=(const Electronics& other);
	~Electronics();

	int getWarranty() const;

	friend std::ostream& operator<<(std::ostream& os, const Electronics& obj);
};
