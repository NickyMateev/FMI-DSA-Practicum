#pragma once
#include "Product.h"
#include <ostream>

class NonFood : public Product
{
private:
	bool containsToxic;

	void copy(const NonFood& other);
protected:
	virtual void print(std::ostream& os) const;
public:
	NonFood(const char product_type, const std::string name, const std::string country, const double price_per_unit, const double price_per_bundle, const double buying_price, const int available_units, const bool contains_toxic);
	NonFood(const NonFood& other);
	NonFood& operator=(const NonFood& other);
	virtual ~NonFood();
	
	bool getContainsToxic() const;

	friend std::ostream& operator<<(std::ostream& os, const NonFood& obj);
};
