#pragma once
#include <string>
#include "Tree.h"

class TreeParser {
private:
    const std::string TREE_PATTERN = "\\s*\\(\\s*(\\d+)\\s*\\{(.*)\\}\\s*\\)\\s*";

    std::list<std::string> getSubtrees(std::string subtreesString);
public:
    bool isValidTree(const std::string& treeString);
    Tree constructTree(const std::string& treeString);

};
