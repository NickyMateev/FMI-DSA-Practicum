#include <list>
#include <vector>
#include <iostream>

int doubleNumber(int n)
{
	return n * 2;
}

bool isPositive(int n)
{
	return n > 0;
}

void transformList(std::list<int>& list, int (*function) (int), bool (*predicate) (int))
{
	std::vector<int> elementsToRemove;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		if(predicate(*it))
		{
			*it = function(*it);
		}
		else
		{
			elementsToRemove.push_back(*it);
		}
		
	}

	for (int elem : elementsToRemove)
	{
		list.remove(elem);
	}
}

int main()
{
	std::list<int> list;
	list.push_back(4);
	list.push_back(1);
	list.push_back(-3);
	list.push_back(12);
	list.push_back(-10);
	list.push_back(5);
	transformList(list, doubleNumber, isPositive);

	for (int elem : list)
	{
		std::cout << elem << std::endl;
	}

    return 0;
}

