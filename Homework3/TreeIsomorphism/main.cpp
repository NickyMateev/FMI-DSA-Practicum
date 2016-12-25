#include <iostream>
#include <regex>
#include "Tree.h"
#include "TreeParser.h"
#include <queue>


bool areTreesIsomorphic(Tree tree1, Tree tree2);
std::vector<int> getChildrenCount(Tree tree);

int main() {

    std::string treeString1, treeString2;
    std::cout << "Tree 1: ";
    getline(std::cin, treeString1);
    std::cout << "Tree 2: ";
    getline(std::cin, treeString2);

    /* Uncomment to use already hardcoded tree strings:
    treeString1 = "(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})";
    treeString2 = "(7 {(15 {(7 {}) (10 {}) (8 {})}) (3 {})})";
    */

    TreeParser treeParser;
    Tree tree1, tree2;

    try {
        tree1 = treeParser.constructTree(treeString1);
    } catch(...) {
        std::cout << "An exception occurred during construction of the first tree." << std::endl;
        return 0;
    }

    try {
        tree2 = treeParser.constructTree(treeString2);
    } catch(...) {
        std::cout << "An exception occurred during construction of the second tree." << std::endl;
        return 0;
    }

    if(areTreesIsomorphic(tree1, tree2)){
        std::cout << "The two trees are isomorphic." << std::endl;
    } else {
        std::cout << "The two trees ARE NOT isomorphic." << std::endl;
    }

    return 0;
}

bool areTreesIsomorphic(Tree tree1, Tree tree2) {
    std::vector<int> tree1Count = getChildrenCount(tree1);
    std::vector<int> tree2Count = getChildrenCount(tree2);

    if (tree1Count.size() != tree2Count.size()) {
        return false;
    }

    std::sort(tree1Count.begin(), tree1Count.end());
    std::sort(tree2Count.begin(), tree2Count.end());

    for (int i = 0; i < tree1Count.size(); ++i) {
        if (tree1Count[i] != tree2Count[i]) {
            return false;
        }
    }

    return true;
}

// using BFS, this function returns a vector with the number of children each node has in the tree:
std::vector<int> getChildrenCount(Tree tree) {
    std::queue<Tree> queue;
    queue.push(tree);

    std::vector<int> childrenArray;
    while (!queue.empty()) {
        Tree currTree = queue.front();
        queue.pop();
        childrenArray.push_back(currTree.getSubtrees().size());

        for (std::list<Tree>::const_iterator it = currTree.getSubtrees().begin();
             it != currTree.getSubtrees().end(); it++) {
            queue.push(*it);
        }
    }

    return childrenArray;
}
