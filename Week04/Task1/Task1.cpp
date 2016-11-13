#include <string>
#include <stack>
#include <iostream>

std::string infixToPostfix(std::string infixExp);
bool isDigit(char);
bool isOperator(char);
short getPriority(char);

int main()
{
	std::string infix1 = "((12+15)/(45*2))";
	std::string infix2 = "(9*((2+3)/(4+5)))+8";

	try
	{
		std::cout << infix1 << "   ->   " << infixToPostfix(infix1) << std::endl;
	}
	catch(...)
	{
		std::cout << "Error occurred during conversion..." << std::endl;
	}

	try
	{
		std::cout << infix2 << "   ->   " << infixToPostfix(infix2) << std::endl;
	}
	catch (...)
	{
		std::cout << "Error occurred during conversion..." << std::endl;
	}
	
    return 0;
}

std::string infixToPostfix(std::string infixExp)
{
	std::string postfixExp;
	std::stack<char> operatorStack;

	char c;
	for (int i = 0; i < infixExp.size(); ++i)
	{
		c = infixExp.at(i);
		if (isDigit(c))
		{
			postfixExp.push_back(c);
			if(i != infixExp.size() - 1 && !isDigit(infixExp.at(i+1)))
			{
				postfixExp.push_back(' ');
			}
		}
		if (isOperator(c))
		{
			postfixExp.push_back(' ');
			if (!operatorStack.empty())
			{
				while (getPriority(operatorStack.top()) >= getPriority(c))
				{
					postfixExp.push_back(operatorStack.top());
					operatorStack.pop();
				}
			}
			operatorStack.push(c);
		}
		if (c == '(')
		{
			operatorStack.push(c);
		}
		if (c == ')')
		{
			while(operatorStack.top() != '(')
			{
				postfixExp.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.pop(); // removing the '(' -> opening brace
		}
	}

	while (!operatorStack.empty())
	{
		if (operatorStack.top() == '(')
		{
			throw "Invalid expression exception!";
		}

		postfixExp.push_back(operatorStack.top());
		operatorStack.pop();
	}

	return postfixExp;
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

short getPriority(char symbol)
{
	switch (symbol)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		default: return 0;
	}	
}