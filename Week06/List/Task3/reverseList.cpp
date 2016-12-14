#include <vector>
#include <iostream>

template <typename T>
struct Node
{
	T value;
	Node* next;
};
template <typename T>
Node<T>* revertList(Node<T>* ptr)
{
	std::vector<Node<T>*> pointers;
	while(ptr != NULL)
	{
		pointers.push_back(ptr);
		ptr = ptr->next;
	}

	for (int i = pointers.size() - 1; i >= 0; i--)
	{
		if(i == 0)
		{
			pointers[i]->next = NULL;
		}
		else
		{
			pointers[i]->next = pointers[i - 1];
		}
	}
	
	return pointers[pointers.size() - 1];
}

template <typename T>
void printList(Node<T>* firstElem)
{
	while(firstElem != NULL)
	{
		std::cout << firstElem->value << std::endl;
		firstElem = firstElem->next;
	}
}



int main()
{
	Node<int> elem1, elem2, elem3, elem4;
	elem1.value = 1;
	elem2.value = 2;
	elem3.value = 3;
	elem4.value = 4;

	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = NULL;

	Node<int>* ptr = &elem1;
	std::cout << "Before reverse:" << std::endl;
	printList(ptr);

	std::cout << "\nAfter reverse:" << std::endl;
	Node<int>* newPtr = revertList(ptr);
	printList(newPtr);
	
    return 0;
}

