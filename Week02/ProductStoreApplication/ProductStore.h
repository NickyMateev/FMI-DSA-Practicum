#pragma once
#include <vector>
#include "Product.h"
#include "Food.h"
#include "NonFood.h"
#include "Electronics.h"
#include "OrderResult.h"

class ProductStore
{
private:
	std::vector<Food> foodProducts;
	std::vector<NonFood> nonFoodProducts;
	std::vector<Electronics> electronicProducts;
	Date currentDate;

	static const int MIN_QUANTITY_FOOD_NONFOOD = 10;
	static const int MIN_QUANTITY_ELECTRONICS = 2;

	// flags needed to track changes after each requested order 
	bool foodProductsChanged;
	bool nonFoodProductsChanged;
	bool electronicsProductsChanged;

	void copy(const ProductStore& other);
	OrderResult calculateOrder(Product& product, int quantity);
	double calculateProfitLoss(const Product& product, int quantity);
	bool isFoodExpired(const Food& food) const;
public:
	ProductStore(Date currentDate);
	ProductStore(const ProductStore& other);
	ProductStore& operator=(const ProductStore& other);
	~ProductStore();

	void constructFoodProduct(const std::string& line);
	void constructNonFoodProduct(const std::string& line);
	void constructElectronicsProduct(const std::string& line);

	void loadProducts();
	OrderResult order(std::string productName, int quantity);
	void updateProductsFile();
	
	static const std::string FOOD_FILEPATH;
	static const std::string NONFOOD_FILEPATH;
	static const std::string ELECTRONICS_FILEPATH;
};
