#include <list>
#include <iostream>

template <typename T>
bool listContainsElement(std::list<T> list, T element)
{
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if(*it == element)
		{
			return true;
		}
	}

	return false;
}

template <typename T>
std::list<T> getUniqueList(std::list<T> list) // function removes duplicate elements
{
	std::list<T> result;
	for (T elem : list)
	{
		if(!listContainsElement(result, elem))
		{
			result.push_back(elem);
		}
	}

	return result;
}

template <typename T>
std::list<T> getListUnion(std::list<T> list1, std::list<T> list2)
{
	std::list<T> firstList = getUniqueList(list1);
	std::list<T> secondList = getUniqueList(list2);

	for (T elem : secondList)
	{
		if(!listContainsElement(firstList, elem))
		{
			firstList.push_back(elem);
		}
	}

	return firstList;
}

template <typename T>
std::list<T> getListIntersection(std::list<T> list1, std::list<T> list2)
{
	std::list<T> firstList = getUniqueList(list1);
	std::list<T> secondList = getUniqueList(list2);

	std::list<T> result;
	for (T elem : firstList)
	{
		if (listContainsElement(secondList, elem))
		{
			result.push_back(elem);
		}
	}

	return result;
}

template <typename T>
std::list<T> getListDifference(std::list<T> list1, std::list<T> list2)
{
	std::list<T> firstList = getUniqueList(list1);
	std::list<T> secondList = getUniqueList(list2);

	std::list<T> result;
	for (T elem : firstList)
	{
		if (!listContainsElement(secondList, elem))
		{
			result.push_back(elem);
		}
	}

	return result;
}

int main()
{
	std::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	std::list<int> l2;
	l2.push_back(3);
	l2.push_back(4);
	l2.push_back(5);
	l2.push_back(6);

	std::list<int> l3 = getListDifference(l1, l2);
	for (int element : l3)
	{
		std::cout << element << std::endl;
	}

    return 0;
}

