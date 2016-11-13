#include <iostream>
#include <stack>

const int SIZE = 100;

bool hasBalancedBrackets(const char* expr);

int main()
{
	char inputExpression[SIZE] = "";
	std::cout << "Expression: ";
	std::cin.getline(inputExpression, SIZE);

	if(hasBalancedBrackets(inputExpression))
	{
		std::cout << "Expression has balanced brackets." << std::endl;
	}
	else
	{
		std::cout << "Expression does not have balanced brackets." << std::endl;
	}

    return 0;
}

bool hasBalancedBrackets(const char* expr)
{
	std::stack<char> bracketStack;
	while(*expr != '\0')
	{
		if(*expr == '(' || *expr == '[' || *expr == '{')
		{
			bracketStack.push(*expr);
		}
		else if(*expr == ')')
		{
			if(bracketStack.empty() || bracketStack.top() != '(')
			{
				return false;
			}
			bracketStack.pop();
		}
		else if(*expr == ']')
		{
			if(bracketStack.empty() || bracketStack.top() != '[')
			{
				return false;
			}
			bracketStack.pop();
		}
		else if(*expr == '}')
		{
			if(bracketStack.empty() || bracketStack.top() != '{')
			{
				return false;
			}
			bracketStack.pop();
		}

		expr++;
	}

	return bracketStack.empty();
}

