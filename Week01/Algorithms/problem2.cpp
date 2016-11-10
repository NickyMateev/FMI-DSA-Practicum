#include <iostream>
using namespace std;

const long SIZE = 1000000;

int binarySearch(int* arr, int size, int key)
{
  int min = 0, max = size - 1;
  int mid = -1;

  while(min <= max)
  {
    mid = (min + max) / 2;
    if(arr[mid] == key)
    {
      return mid;
    }
    else if(arr[mid] < key)
    {
      min = mid + 1;
    }
    else // arr[mid] > key
    {
      max = mid - 1;
    }
  }

  return -1;
}

int findCount(int* arr, int size, int number)
{
  int count = 0;

  int numberToFind = 0;
  for(int i = 0; i < (size / 2); i++)
  {
    if(arr[i] < 1) // just to be safe
    {
      continue;
    }
    else
    {
      numberToFind = number - arr[i];
      if(numberToFind <= arr[i])
      {
        break;
      }

      if(binarySearch(arr, size, numberToFind) != -1)
      {
        cout << "Found: " <<  arr[i] << " + " << numberToFind << " = " << number << endl;
        count++;
      }
    }

  }

  return count;
}

// Demo:
int main()
{
  // the array contains only positive numbers in increasing order
  int arr[SIZE];

  // filling in the array with the numbers from 1 to 1,000,000
  for(int i = 0; i < SIZE; i++)
  {
    arr[i] = i + 1;
  }

  cout << "\nTotal results: " << findCount(arr, SIZE, 26) << endl;

  return 0;
}
