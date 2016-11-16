#include <iostream>
#include <queue>

const int DIMENSION = 5;
const int START_NODE = 3; // change this value to start from some other node(1-5)

struct Node
{
	int elem;
	int distance;
};

void fillOutMatrix(int matrix[][DIMENSION]);
std::vector<Node> getDistances(int matrix[][DIMENSION], Node startNode);
bool vectorContains(std::vector<Node> vector, Node node);
void printDistances(std::vector<Node> distances, Node startNode);

int main()
{
	int matrix[DIMENSION][DIMENSION];
	fillOutMatrix(matrix);

	Node startNode = { START_NODE, 0 };
	std::vector<Node> distances = getDistances(matrix, startNode);
	printDistances(distances, startNode);

    return 0;
}

// function which hard-codes some values in a matrix in order to generate a relationship matrix:
void fillOutMatrix(int matrix[][DIMENSION])
{
	// 1st row:
	matrix[0][0] = 0;
	matrix[0][1] = 1;
	matrix[0][2] = 1;
	matrix[0][3] = 0;
	matrix[0][4] = 0;

	// 2nd row:
	matrix[1][0] = 1;
	matrix[1][1] = 0;
	matrix[1][2] = 1;
	matrix[1][3] = 1;
	matrix[1][4] = 0;

	// 3rd row:
	matrix[2][0] = 1;
	matrix[2][1] = 1;
	matrix[2][2] = 0;
	matrix[2][3] = 0;
	matrix[2][4] = 1;

	// 4th row:
	matrix[3][0] = 0;
	matrix[3][1] = 1;
	matrix[3][2] = 0;
	matrix[3][3] = 0;
	matrix[3][4] = 0;

	// 5th row:
	matrix[4][0] = 0;
	matrix[4][1] = 0;
	matrix[4][2] = 1;
	matrix[4][3] = 0;
	matrix[4][4] = 0;

}

// startNode is a node between 1 and DIMENSION
std::vector<Node> getDistances(int matrix[][DIMENSION], Node startNode)
{
	std::queue<Node> queue;
	std::vector<Node> visited;

	visited.push_back(startNode);
	queue.push(startNode);

	Node currentNode; 
	while(!queue.empty())
	{
		currentNode = queue.front();
		queue.pop();

		for (int i = 0; i < DIMENSION; ++i)
		{
			if (matrix[currentNode.elem - 1][i])
			{
				if (!vectorContains(visited, Node{ i + 1, -1 })) // -1 is an arbitrary value(used only to create the object), in reality - we can choose whatever value we want 
				{
					Node nodeToAdd{ i + 1, currentNode.distance + 1 };
					visited.push_back(nodeToAdd);
					queue.push(nodeToAdd);
				}
			}
		}

	}

	return visited;
}

bool vectorContains(std::vector<Node> vector, Node node)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if(vector.at(i).elem == node.elem)
		{
			return true;
		}
	}

	return false;
}

void printDistances(std::vector<Node> distances, Node startNode)
{
	for (Node node : distances)
	{
		std::cout << "Node #" << node.elem << " -> Distance to Node #" << startNode.elem << " is: " << node.distance << std::endl;
	}	
}