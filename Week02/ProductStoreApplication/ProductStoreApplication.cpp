// ProductStoreApplication.cpp : Defines the entry point for the console application.

#include <iostream>
#include "ProductStore.h"
#include <fstream>
#include <sstream>

const int CURRENT_DAY = 4;
const int CURRENT_MONTH = 11;
const int CURRENT_YEAR = 2016;

Date getCurrentDate();
void runApplication();

int main()
{
	runApplication();
    return 0;

}

Date getCurrentDate()
{
	return Date(CURRENT_DAY, CURRENT_MONTH, CURRENT_YEAR);
}

void runApplication()
{
	ProductStore productStore(getCurrentDate());

	std::string input;
	std::string productName;
	int quantity;
	OrderResult result;

	std::cout << "Welcome! Please make an order...\n" << std::endl;
	while (true)
	{
		productStore.loadProducts();
		std::cout << "\n\nProduct name: ";
		std::getline(std::cin, productName);
		std::cout << "Quantity : ";
		std::getline(std::cin, input);
		std::stringstream(input) >> quantity;

		result = productStore.order(productName, quantity);
		std::cout << "\n Order result:\n";
		std::cout << result << std::endl;

		productStore.updateProductsFile();

		std::cout << "\n\n\nDo you want to continue making orders?\n Enter 'q' to exit or any other key to continue... ";
		std::getline(std::cin, input);

		if(input.compare("q") == 0)
		{
			break;
		}
	}	
	
}