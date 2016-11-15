#include <iostream>
#include <stack>


int main()
{
	int num;
	do
	{
		std::cout << "Input: ";
		std::cin >> num;
	}
	while (num <= 0);

	std::stack<int> stack;
	while(num != 0)
	{
		stack.push(num);
		num--;
	}

	long factorial = 1;
	while(!stack.empty())
	{
		factorial *= stack.top();
		std::cout << stack.top() << "! = " << factorial << std::endl;
		stack.pop();
	}

    return 0;
}

