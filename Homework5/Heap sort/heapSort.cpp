#include <iostream>

template <typename T>
void swap(T& var1, T& var2)
{
	T temp = var1;
	var1 = var2;
	var2 = temp;
}

template <typename T>
void shiftRight(T *arr, int low, int high) {

	int root = low;
	int leftChild = -1;
	do
	{
		leftChild = root * 2 + 1;
		int rightChild = leftChild + 1;
		int swapIndex = root;

		if (leftChild > high)
		{
			break;
		}
		if (arr[swapIndex] < arr[leftChild])
		{
			swapIndex = leftChild;
		}
		if (rightChild <= high && arr[swapIndex] < arr[rightChild])
		{
			swapIndex = rightChild;
		}
		if (swapIndex != root)
		{
			swap(arr[swapIndex], arr[root]);
			root = swapIndex;
		}
		else
		{
			break;
		}

	} while (leftChild <= high);
}

template <typename T>
void heapify(T *arr, int low, int high)
{
	int midIndex = (high - low - 1) / 2;

	while (midIndex >= 0)
	{
		shiftRight(arr, midIndex, high);
		--midIndex;
	}
}

template <typename T>
void heapsort(T *arr, int size)
{
	int high = size - 1;
	heapify(arr, 0, high);

	while (high > 0)
	{
		swap(arr[high], arr[0]);
		--high;
		shiftRight(arr, 0, high);
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
	int arr[] = { 2, 34, 91, 32, 41, 53, 3, 5, 42 };

	std::cout << "Original:\n";
	printArr(arr, size);

	heapsort(arr, size);

	std::cout << "\nAfter merge sort:\n";
	printArr(arr, size);

    return 0;
}

