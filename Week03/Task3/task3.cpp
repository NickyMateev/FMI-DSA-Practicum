#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

const std::string FILE_PATH = "decimalNumbers.txt";

long decimalToBinary(int);
void printBinaryNumbersFromFile(std::string);

int main()
{
	printBinaryNumbersFromFile(FILE_PATH);
    return 0;
}

long decimalToBinary(int decimal)
{
	std::string binaryString;
	while(decimal != 0)
	{
		binaryString.push_back('0' + (decimal % 2));
		decimal /= 2;
	}

	long binaryNum = 0;
	for (int i = 0; i < binaryString.size(); ++i)
	{
		binaryNum += (binaryString.at(i) - '0') * (pow(10, i));
	}

	return binaryNum;
}

void printBinaryNumbersFromFile(std::string filePath)
{
	std::ifstream inputStream(filePath);

	std::cout << "Decimal to Binary:" << std::endl;
	int currNum = 0;
	if(inputStream.is_open())
	{
		std::string line;
		while(getline(inputStream, line))
		{
			try
			{
				std::stringstream(line) >> currNum;
				std::cout << currNum << " : ";
				std::cout << decimalToBinary(currNum) << std::endl;
			}
			catch (...)
			{
				std::cout << "Invalid line input: " << line << std::endl;
			}
		}
		inputStream.close();
	}
}
