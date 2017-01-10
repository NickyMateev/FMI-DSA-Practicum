#include <iostream>
#include <ctime>

int getRand(int min, int max)
{
	srand(time(NULL));
	return (rand() % (max - min) + min);
}

template <typename T>
void swap(T& var1, T& var2)
{
	T temp = var1;
	var1 = var2;
	var2 = temp;
}

template <typename T>
void quickSort(T* arr, int size)
{
	if (size < 2)
	{
		return;
	}

	int low = 0;
	int top = size - 1;
	T pivot = arr[getRand(0, size)];

	while (low < top)
	{
		while (arr[low] < pivot)
		{
			low++;
		}

		while (arr[top] > pivot)
		{
			top--;
		}

		if (low != top)
		{
			swap(arr[low], arr[top]);
		}
	}

	quickSort(arr, low);
	quickSort(arr + low + 1, size - low - 1);
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
	int arr[] = { 2, 34, 91, 32, 41, 53, 3, 5, 42 };

	std::cout << "Original:\n";
	printArr(arr, size);

	quickSort(arr, size);

	std::cout << "\nAfter quick sort:\n";
	printArr(arr, size);

    return 0;
}

