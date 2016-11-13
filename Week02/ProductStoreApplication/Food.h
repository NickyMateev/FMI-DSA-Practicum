#pragma once
#include "Product.h"
#include "Date.h"
#include <ostream>

class Food : public Product
{
private:
	Date expirationDate;
	bool sustainableToLowTemp;

	void copy(const Food& other);
protected:
	virtual void print(std::ostream& os) const;
public:
	Food(const char product_type, const std::string name, const std::string country, const double price_per_unit, const double price_per_bundle, const double buying_price, const int available_units, const Date expiration_date, const bool sustainable_to_low_temp);
	Food(const Food& other);
	Food& operator=(const Food& other);
	virtual ~Food();

	Date getExpirationDate() const;
	bool isSustainableToLowTemp() const;

	friend std::ostream& operator<<(std::ostream& os, const Food& obj);
};
