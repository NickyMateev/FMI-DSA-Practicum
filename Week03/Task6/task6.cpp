#include <string>
#include <iostream>
#include <sstream>
#include "Product.h"
#include <fstream>

const std::string FILE_PATH = "products.txt";
const int PRODUCT_COUNT = 8;

void runApplication();
void readProducts(Product*);
void writeToFile(std::string, const Product*, const int);
void readFromFile(std::string);
void findInFile(std::string);
void printHelp();

int main()
{
	runApplication();
    return 0;
}

void runApplication()
{
	Product products[PRODUCT_COUNT];

	std::string userInput;
	short choice;
	while(true)
	{
		printHelp();
		std::cout << "\n\nInput: ";
		try
		{
			getline(std::cin, userInput);
			std::stringstream(userInput) >> choice;
		}
		catch (...)
		{
			std::cout << "Invalid input!\n\n" << std::endl;
			continue;
		}

		switch (choice)
		{
			case 1: readProducts(products);
					writeToFile(FILE_PATH, products, PRODUCT_COUNT);
					break;
			case 2: readFromFile(FILE_PATH);
					break;
			case 3: findInFile(FILE_PATH);
					break;
			case 4: return;
			default: std::cout << "Invalid input choice!\n\n" << std::endl;
				break;
		}
	}
}

void readProducts(Product* products)
{
	int productID;
	std::string name;
	double price;

	std::string userInput;
	for (int i = 0; i < PRODUCT_COUNT; ++i)
	{
		std::cout << "Product #" << i + 1 << std::endl;

		std::cout << "ProductID: ";
		getline(std::cin, userInput);
		std::stringstream(userInput) >> productID;

		std::cout << "Product name: ";
		getline(std::cin, userInput);
		std::stringstream(userInput) >> name;

		std::cout << "Product price: ";
		getline(std::cin, userInput);
		std::stringstream(userInput) >> price;

		std::cout << '\n';
		products[i] = Product(productID, name, price);
	}
}

void writeToFile(std::string filePath, const Product* products, const int size)
{
	std::ofstream outputStream(filePath);
	if(outputStream.is_open())
	{
		for (int i = 0; i < size; ++i)
		{
			outputStream << products[i] << std::endl;
		}
		outputStream.close();
	}
}

void readFromFile(std::string filePath)
{
	bool isFileEmpty = true;

	std::ifstream inputStream(filePath);
	if(inputStream.is_open())
	{
		std::string line;
		while(getline(inputStream, line))
		{
			std::cout << line << std::endl;
			isFileEmpty = false;
		}
		inputStream.close();
	}
	std::cout << "\n\n";

	if (isFileEmpty)
	{
		std::cout << "File is empty.\n\n" << std::endl;
	}
}

void findInFile(std::string filePath)
{
	bool productFound = false;
	std::string userInput;
	int productID = -1;
	std::cout << "Find product by its ID: ";
	getline(std::cin, userInput);
	std::stringstream(userInput) >> productID;

	std::ifstream inputStream(filePath);
	if(inputStream.is_open())
	{
		std::string line;
		int currID = -1;
		while (getline(inputStream, line))
		{
			std::stringstream(line) >> currID;
			if(currID == productID)
			{
				std::cout << "Product found: " << line << "\n\n" << std::endl;
				productFound = true;
				break;
			}
		}
		inputStream.close();
	}

	if (!productFound)
	{
		std::cout << "Product not found.\n" << std::endl;
	}
}

void printHelp()
{
	std::cout << "1) Input products into file" << std::endl;
	std::cout << "2) View products in file" << std::endl;
	std::cout << "3) Find product in file" << std::endl;
	std::cout << "4) Exit" << std::endl;
}