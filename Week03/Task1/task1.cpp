#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const std::string FILE_PATH = "numbers.txt";

struct MinMaxPair
{
	double min;
	double max;
};

MinMaxPair findMinMax(std::string filePath);

int main()
{
	MinMaxPair pair = findMinMax(FILE_PATH);
	std::cout << "Min: " << pair.min << std::endl;
	std::cout << "Max: " << pair.max << std::endl;

    return 0;
}

MinMaxPair findMinMax(std::string filePath)
{
	std::ifstream inputStream(filePath);

	MinMaxPair result = {0.0, 0.0};
	double min = 0.0, max = 0.0, currNum = 0.0;

	if (inputStream.is_open())
	{
		std::string line;
		try
		{
			getline(inputStream, line);
			std::stringstream(line) >> currNum;
			min = currNum;
			max = currNum;
		}
		catch(...)
		{
			return result; // invalid start of file, return
		}

		while (getline(inputStream, line))
		{
			try
			{
				std::stringstream(line) >> currNum;

				if (currNum < min)
				{
					min = currNum;
				}

				if(currNum > max)
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
