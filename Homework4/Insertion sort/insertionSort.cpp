#include <iostream>

void insertionSort(int* arr, int size)
{
	int elem, j;
	for (int i = 1; i < size; i++)
	{
		elem = arr[i];
		j = i;
		while (j > 0 && arr[j - 1] > elem)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = elem;
	}
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}

int main()
{
	int size = 9;
	int arr[] = { 2, 34, 91, 32, 41, 53, 3, 5, 42 };
	
	std::cout << "Original:\n";
	printArr(arr, size);

	insertionSort(arr, size);

	std::cout << "\nAfter insertion sort:\n";
	printArr(arr, size);


    return 0;
}

