#include "stdafx.h"
#include <iostream>
#include <stack>


int main()
{
	std::stack<int> number1, number2;
	int input;

	std::cout << "Enter the first number: " << std::endl;
	for (int i = 0; i < length1; ++i)
	{
		std::cout << "Digit #" << i + 1 << ": ";
		std::cin >> input;
		number1.push(input);
	}

	std::cout << "Enter the second number: " << std::endl;
	for (int i = 0; i < length2; ++i)
	{
		std::cout << "Digit #" << i + 1 << ": ";
		std::cin >> input;
		number2.push(input);
	}

	std::stack<int> sum;
	bool addOne = false;
	int currDigit;
	while(!number1.empty() && !number2.empty())
	{
		currDigit = number1.top() + number2.top();
		if(addOne)
		{
			currDigit++;
		}

		if(currDigit >= 10)
		{
			sum.push(currDigit % 10);
			addOne = true;
		}
		else
		{
			sum.push(currDigit);
			addOne = false;
		}

		number1.pop();
		number2.pop();
	}

	if (!number1.empty() || !number2.empty())
	{
		std::stack<int> remainingDigits = (number1.size() > number2.size()) ? number1 : number2;

		while (!remainingDigits.empty())
		{
			currDigit = remainingDigits.top();
			if (addOne)
			{
				currDigit++;
			}

			if (currDigit >= 10)
			{
				sum.push(currDigit % 10);
				addOne = true;
			}
			else
			{
				sum.push(currDigit);
				addOne = false;
			}

			remainingDigits.pop();
		}
	}

	if(addOne)
	{
		sum.push(1);
	}

	std::cout << "The sum is: ";
	while (!sum.empty())
	{
		std::cout << sum.top();
		sum.pop();
	}
	std::cout << std::endl;


    return 0;
}

