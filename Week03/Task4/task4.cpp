#include <string>
#include <fstream>
#include <iostream>

const std::string FILE_PATH = "numbers.txt";

bool isPalindrome(std::string);
int getPalindromeCountFromFile(std::string filePath);

int main()
{
	int count = getPalindromeCountFromFile(FILE_PATH);
	std::cout << "Palindrome count in file: " << count << std::endl;
    return 0;
}

bool isPalindrome(std::string str)
{
	for (int i = 0; i < str.size() / 2; ++i)
	{
		if (str.at(i) != str.at(str.size() - i - 1))
		{
			return false;
		}
	}
	return true;
}

int getPalindromeCountFromFile(std::string filePath)
{
	std::ifstream inputStream(filePath);

	int palindromeCount = 0;
	if(inputStream.is_open())
	{
		std::string line;
		while(getline(inputStream, line))
		{
			if(isPalindrome(line))
			{
				palindromeCount++;
			}
		}
		inputStream.close();
	}

	return palindromeCount;
}