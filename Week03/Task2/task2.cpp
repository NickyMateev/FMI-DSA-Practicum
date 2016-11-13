#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

const std::string FILE_PATH = "absoluteNumbers.txt";

struct MinMaxAbsolutePair
{
	double min;
	double max;
};

MinMaxAbsolutePair findAbsoluteMinMax(std::string filePath);

int main()
{
	MinMaxAbsolutePair pair = findAbsoluteMinMax(FILE_PATH);
	std::cout << "Absolute min: " << pair.min << std::endl;
	std::cout << "Absolute max: " << pair.max << std::endl;

	return 0;
}

MinMaxAbsolutePair findAbsoluteMinMax(std::string filePath)
{
	std::ifstream inputStream(filePath);

	MinMaxAbsolutePair result = { 0.0, 0.0 };
	double min = 0.0, max = 0.0, currNum = 0.0;

	if (inputStream.is_open())
	{
		std::string line;
		try
		{
			getline(inputStream, line);
			std::stringstream(line) >> currNum;
			min = abs(currNum);
			max = abs(currNum);
		}
		catch (...)
		{
			return result; // invalid start of file, return
		}

		while (getline(inputStream, line))
		{
			try
			{
				std::stringstream(line) >> currNum;
				currNum = abs(currNum);

				if (currNum < min)
				{
					min = currNum;
				}

				if (currNum > max)
				{
					max = currNum;
				}
			}
			catch (...)
			{
				continue; // invalid input, just continue
			}
		}
		inputStream.close();
	}

	result.min = min;
	result.max = max;

	return result;
}


