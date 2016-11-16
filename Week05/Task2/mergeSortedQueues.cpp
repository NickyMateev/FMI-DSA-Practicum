#include <queue>
#include <iostream>

const int SIZE = 10;

std::queue<int> getSortedEvenQueue();
std::queue<int> getSortedOddQueue();
std::queue<int> mergeSortedQueues(std::queue<int> queue1, std::queue<int> queue2);
void printQueue(std::queue<int> queue);

int main()
{
	std::queue<int> evenQueue = getSortedEvenQueue();
	std::queue<int> oddQueue = getSortedOddQueue();
	std::cout << "Even queue:" << std::endl;
	printQueue(evenQueue);
	std::cout << std::endl;

	std::cout << "Odd queue:" << std::endl;
	printQueue(oddQueue);
	std::cout << std::endl;

	std::queue<int> mergedQueue = mergeSortedQueues(evenQueue, oddQueue);
	std::cout << "Merged queue:" << std::endl;
	printQueue(mergedQueue);
	std::cout << std::endl;

    return 0;
}

std::queue<int> getSortedEvenQueue()
{
	std::queue<int> queue;
	for (int i = 0; i < SIZE; ++i)
	{
		if(i % 2 == 0)
		{
			queue.push(i);
		}
	}	
	return queue;
}

std::queue<int> getSortedOddQueue()
{
	std::queue<int> queue;
	for (int i = 0; i < SIZE; ++i)
	{
		if(i % 2 != 0)
		{
			queue.push(i);
		}
	}	
	return queue;
}

std::queue<int> mergeSortedQueues(std::queue<int> queue1, std::queue<int> queue2)
{
	std::queue<int>	resultQueue;
	
	while (!queue1.empty() && !queue2.empty())
	{
		if (queue1.front() < queue2.front())
		{
			resultQueue.push(queue1.front());
			queue1.pop();
		}
		else
		{
			resultQueue.push(queue2.front());
			queue2.pop();
		}
	}

	if (!queue1.empty() || !queue2.empty())
	{
		std::queue<int> remainingElements = queue1.size() > queue2.size() ? queue1 : queue2;
		while (!remainingElements.empty())
		{
			resultQueue.push(remainingElements.front());
			remainingElements.pop();
		}
	}

	return resultQueue;
}

void printQueue(std::queue<int> queue)
{
	while (!queue.empty())
	{
		std::cout << queue.front() << std::endl;
		queue.pop();
	}
}