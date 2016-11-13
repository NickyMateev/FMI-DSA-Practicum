#pragma once
#include <string>
#include <ostream>

class Product
{
private:
	char productType;
	std::string name;
	std::string country;
	double pricePerUnit;
	double pricePerBundle;
	double buyingPrice;
	int availableUnits;

	void copy(const Product& other);
protected:
	virtual	void print(std::ostream& os) const;
public:
	Product(const char product_type, const std::string name, const std::string country, const double price_per_unit, const double price_per_bundle, const double buying_price, const int available_units);
	Product(const Product& other);
	Product& operator=(const Product& other);
	virtual ~Product();

	char getProductType() const;
	std::string getName() const;
	std::string getCountry() const;
	double getPricePerUnit() const;
	double getPricePerBundle() const;
	double getBuyingPrice() const;
	int getAvailableUnits() const;

	void reduceAvailableUnits(int quantity);

	friend std::ostream& operator<<(std::ostream& os, const Product& obj);

	static const char FOOD_PRODUCT = 'F';
	static const char NONFOOD_PRODUCT = 'N';
	static const char ELECTRONIC_PRODUCT = 'E';
};
