#include <iostream>
#include <cmath>

template <typename T>
void swap(T& var1,T& var2)
{
	T temp = var1;
	var1 = var2;
	var2 = temp;
}

template <typename T>
T min(T var1, T var2)
{
	return var1 < var2 ? var1 : var2;
}

template <typename T>
void merge(T* arr, int end1, int end2)
{
	int i = 0, j = end1, k = 0;

	T* tempArray = new T[end2];
	while (i < end1 && j < end2)
	{
		if (arr[i] < arr[j])
		{
			tempArray[k] = arr[i];
			i++;
		}
		else
		{
			tempArray[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i < end1)
	{
		tempArray[k] = arr[i];
		i++;
		k++;
	}

	while (j < end2)
	{
		tempArray[k] = arr[j];
		j++;
		k++;
	}

	for (int i = 0; i < end2; i++)
	{
		arr[i] = tempArray[i];
	}

	delete[] tempArray;
}

template <typename T>
void mergeSort(T* arr, int size)
{
	for (int i = 1; i < size; i *= 2)
	{
		for (int j = 0; j < size - i; j += 2 * i)
		{
			merge(arr + j, i, min(2 * i, size - j));
		}
	}
}

template <typename T>
void printArr(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}

int main()
{
	int size = 9;
	int arr[] = {2, 34, 91, 32, 41, 53, 3, 5, 42};

	std::cout << "Original:\n";
	printArr(arr, size);

	mergeSort(arr, size);

	std::cout << "\nAfter merge sort:\n";
	printArr(arr, size);

    return 0;
}

