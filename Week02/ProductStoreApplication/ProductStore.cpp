#include "ProductStore.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Date.h"

const std::string ProductStore::FOOD_FILEPATH = "food.txt";
const std::string ProductStore::NONFOOD_FILEPATH = "nonfood.txt";
const std::string ProductStore::ELECTRONICS_FILEPATH = "electronics.txt";

void ProductStore::copy(const ProductStore& other)
{
	this->foodProducts = other.foodProducts;
	this->nonFoodProducts = other.nonFoodProducts;
	this->electronicProducts = other.electronicProducts;
	this->currentDate = other.currentDate;
	this->foodProductsChanged = other.foodProductsChanged;
	this->nonFoodProductsChanged = other.nonFoodProductsChanged;
	this->electronicsProductsChanged = other.electronicsProductsChanged;
}

OrderResult ProductStore::calculateOrder(Product& product, int quantity)
{
	if (quantity <= 0)
	{
		return OrderResult("Invalid quantity amount.", 0);
	}
	else if(product.getAvailableUnits() == 0)
	{
		return OrderResult("Store has no available units of the specific product.", 0);
	}

	std::string orderText = "Order was successful!";
	double totalProfit = 0;

	if(product.getAvailableUnits() < quantity)
	{
		orderText = "Order quantity coult not be fully satisfied. Units that could not be actualized: " + (quantity - product.getAvailableUnits());
		quantity = product.getAvailableUnits();
	}

	if(product.getProductType() != Product::ELECTRONIC_PRODUCT)
	{
		if(quantity < MIN_QUANTITY_FOOD_NONFOOD)
		{
			totalProfit += product.getPricePerUnit() * quantity;
		}
		else
		{
			totalProfit += product.getPricePerBundle() * quantity;
		}
	}
	else
	{
		if (quantity < MIN_QUANTITY_ELECTRONICS)
		{
			totalProfit += product.getPricePerUnit() * quantity;
		}
		else
		{
			totalProfit += product.getPricePerBundle() * quantity;
		}
	}

	// reducing units in inventory:
	product.reduceAvailableUnits(quantity);

	if(product.getProductType() == Product::FOOD_PRODUCT)
	{
		foodProductsChanged = true;
	}
	else if(product.getProductType() == Product::NONFOOD_PRODUCT)
	{
		nonFoodProductsChanged = true;
	}
	else if(product.getProductType() == Product::ELECTRONIC_PRODUCT)
	{
		electronicsProductsChanged = true;
	}

	return OrderResult(orderText, totalProfit);
}

double ProductStore::calculateProfitLoss(const Product& product, int quantity)
{
	if(product.getAvailableUnits() < quantity)
	{
		quantity = product.getAvailableUnits();
	}

	return product.getBuyingPrice() * quantity;
}

bool ProductStore::isFoodExpired(const Food& food) const
{
	return food.getExpirationDate() < this->currentDate;
}

ProductStore::ProductStore(Date currentDate)
{
	this->currentDate = currentDate;
	this->foodProductsChanged = false;;
	this->nonFoodProductsChanged = false;
	this->electronicsProductsChanged = false;
}

ProductStore::ProductStore(const ProductStore& other)
{
	this->copy(other);
}

ProductStore& ProductStore::operator=(const ProductStore& other)
{
	if(this != &other)
	{
		this->copy(other);
	}

	return *this;
}

ProductStore::~ProductStore()
{
}

void ProductStore::constructFoodProduct(const std::string& line)
{
	char productType;
	std::string name, country;
	double pricePerUnit, pricePerBundle, buyingPrice;
	int availableUnits;

	short day, month, year;
	bool sustainableToLowTemp;

	std::stringstream(line) >> productType >> name >> country >> pricePerUnit >> pricePerBundle >> buyingPrice >> availableUnits >> day >> month >> year >> sustainableToLowTemp;
	Date expirationDate = { day, month, year };

	this->foodProducts.push_back(Food(productType, name, country, pricePerUnit, pricePerBundle, buyingPrice, availableUnits, expirationDate, sustainableToLowTemp));
}

void ProductStore::constructNonFoodProduct(const std::string& line)
{
	char productType;
	std::string name, country;
	double pricePerUnit, pricePerBundle, buyingPrice;
	int availableUnits;

	bool containsToxic;

	std::stringstream(line) >> productType >> name >> country >> pricePerUnit >> pricePerBundle >> buyingPrice >> availableUnits >> containsToxic;
	this->nonFoodProducts.push_back(NonFood(productType, name, country, pricePerUnit, pricePerBundle, buyingPrice, availableUnits, containsToxic));
}

void ProductStore::constructElectronicsProduct(const std::string& line)
{
	char productType;
	std::string name, country;
	double pricePerUnit, pricePerBundle, buyingPrice;
	int availableUnits;

	int warranty;

	std::stringstream(line) >> productType >> name >> country >> pricePerUnit >> pricePerBundle >> buyingPrice >> availableUnits >> warranty;
	this->electronicProducts.push_back(Electronics(productType, name, country, pricePerUnit, pricePerBundle, buyingPrice, availableUnits, warranty));
}

void ProductStore::loadProducts()
{
	// just to be safe:
	foodProducts.clear();
	nonFoodProducts.clear();
	electronicProducts.clear();

	std::string line;

	// loading food products:
	std::ifstream inputStream(FOOD_FILEPATH);
	if (inputStream.is_open())
	{
		while(std::getline(inputStream, line))
		{
			constructFoodProduct(line);
		}
		inputStream.close();
	}

	// loading nonFood products:
	inputStream.open(NONFOOD_FILEPATH);
	if(inputStream.is_open())
	{
		while(std::getline(inputStream, line))
		{
			constructNonFoodProduct(line);
		}
		inputStream.close();
	}

	// loading electronic products:
	inputStream.open(ELECTRONICS_FILEPATH);
	if(inputStream.is_open())
	{
		while (std::getline(inputStream, line))
		{
			constructElectronicsProduct(line);
		}
		inputStream.close();
	}

}

OrderResult ProductStore::order(std::string productName, int quantity)
{
	Product* productToFind = NULL;

	for (int i = 0; i < foodProducts.size(); ++i)
	{
		if (foodProducts.at(i).getName().compare(productName) == 0)
		{
			productToFind = &foodProducts.at(i);
			break;
		}
	}

	if (productToFind == NULL)
	{
		for (int i = 0; i < nonFoodProducts.size(); ++i)
		{
			if (nonFoodProducts.at(i).getName().compare(productName) == 0)
			{
				productToFind = &nonFoodProducts.at(i);
				break;
			}

		}
	}

	if (productToFind == NULL)
	{
		for (int i = 0; i < electronicProducts.size(); ++i)
		{
			if (electronicProducts.at(i).getName().compare(productName) == 0)
			{
				productToFind = &electronicProducts.at(i);
				break;
			}

		}
	}

	if (productToFind == NULL)
	{
		return OrderResult("Product does not exist in the store inventory.", 0);
	}

	if (productToFind->getProductType() == Product::FOOD_PRODUCT)
	{
		if (isFoodExpired(*(Food*)productToFind))
		{
			foodProductsChanged = true;
			double profitLoss = calculateProfitLoss(*productToFind, quantity);
			return OrderResult("Product was available at the store inventory, but had an expired expiraton date!", (-1) * profitLoss);
		}
	}

	return calculateOrder(*productToFind, quantity);
}

void ProductStore::updateProductsFile()
{
	std::ofstream fileOutput;
	if (foodProductsChanged)
	{
		fileOutput.open(FOOD_FILEPATH);
		for (Food foodProduct : foodProducts)
		{
			if (!isFoodExpired(foodProduct))
			{
				fileOutput << foodProduct << std::endl;
			}
		}
		fileOutput.close();
		foodProductsChanged = false;
	}
	else if (nonFoodProductsChanged)
	{
		fileOutput.open(NONFOOD_FILEPATH);
		for (NonFood nonFoodProduct : nonFoodProducts)
		{
			fileOutput << nonFoodProduct << std::endl;
		}
		fileOutput.close();
		nonFoodProductsChanged = false;
	}
	else if (electronicsProductsChanged)
	{
		fileOutput.open(ELECTRONICS_FILEPATH);
		for (Electronics electronicProduct : electronicProducts)
		{
			fileOutput << electronicProduct << std::endl;
		}
		fileOutput.close();
		electronicsProductsChanged = false;
	}
}
