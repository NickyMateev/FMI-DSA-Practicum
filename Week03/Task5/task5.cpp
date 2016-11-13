#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

const std::string FILE_PATH = "priceFile.txt";
const double TAX = 0.2;

double calculateTax(double, double);
void calculateMoneyFromFile(std::string);

int main()
{
	calculateMoneyFromFile(FILE_PATH);
    return 0;
}

double calculateTax(double price, double tax)
{
	return price * tax;
}

void calculateMoneyFromFile(std::string filePath)
{
	std::ifstream inputStream(filePath);

	double currAmount = 0.0, currTax = 0.0;
	double totalAmount = 0.0, totalTax = 0.0;
	if (inputStream.is_open())
	{
		std::string line;
		while (getline(inputStream, line))
		{
			try
			{
				std::stringstream(line) >> currAmount;
			}
			catch(...)
			{
				std::cout << "Invalid line: " << line << std::endl;
				continue;
			}

			currTax = calculateTax(currAmount, TAX);
			std::cout << "Item: $" << currAmount << ", Tax: $" << currTax << std::endl;

			totalAmount += currAmount;
			totalTax += currTax;
		}
		inputStream.close();
	}

	std::cout << "\nTotal tax: $" << totalTax << std::endl;
	std::cout << "Total + tax: $" << (totalTax + totalAmount) << std::endl;
}