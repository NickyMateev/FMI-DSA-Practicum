#include <queue>
#include <iostream>

const int SIZE = 10;

void fillQueue(std::queue<int>& queue, int size);
int getMinInQueue(std::queue<int> queue);

int main()
{
	std::queue<int> queue;
	fillQueue(queue, SIZE);

	int minElem = getMinInQueue(queue);
	std::cout << "Min in queue: " << minElem << std::endl;
    return 0;
}

void fillQueue(std::queue<int>& queue, int size)
{
	for (int i = 0; i < size; i++)
	{
		queue.push(i);
	}
}

int getMinInQueue(std::queue<int> queue)
{
	int min = queue.front();
	while(!queue.empty())
	{
		if (queue.front() < min)
		{
			min = queue.front();
		}
		queue.pop();
	}
	return min;
}
