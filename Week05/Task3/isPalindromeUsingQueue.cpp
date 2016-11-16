#include <string>
#include <stack>
#include <iostream>

bool isPalindrome(std::string number);

int main()
{
	std::string num = "12321", num2 = "123421";

	std::cout << "Is " << num << " a palindrome? -> " << (isPalindrome(num) ? "Yes" : "No") << std::endl;
	std::cout << "Is " << num2 << " a palindrome? -> " << (isPalindrome(num2) ? "Yes" : "No") << std::endl;

    return 0;
}

bool isPalindrome(std::string number)
{
	std::stack<int> frontNumbers;
	std::stack<int> backNumbers;

	for (int i = 0; i < number.size() / 2; ++i) 
	{ 
		frontNumbers.push(number.at(i));
		backNumbers.push(number.at(number.size() - i - 1));
	}

	while(!frontNumbers.empty() || !backNumbers.empty())
	{
		if(frontNumbers.top() != backNumbers.top())
		{
			return false;
		}
		frontNumbers.pop();
		backNumbers.pop();
	}

	return true;
}
