#include <list>
#include <vector>
#include <iostream>


template <typename T>
bool vectorContainsElement(std::vector<T> vector, T element)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		if(vector.at(i) == element)
		{
			return true;
		}
	}

	return false;
}

template <typename T>
bool isListUnique(std::list<T> list)
{
	std::vector<T> visited;
	std::list<T>::iterator it = list.begin();
	while (it != list.end())
	{
		if(vectorContainsElement(visited, *it))
		{
			return false;
		}

		visited.push_back(*it);
		it++;
	}

	return true;
}

int main()
{
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	std::cout << isListUnique(list) << std::endl;
    return 0;
}

