#include "TreeParser.h"
#include <regex>

bool TreeParser::isValidTree(const std::string &treeString) {
    return std::regex_match(treeString, std::regex(TREE_PATTERN));
}

Tree TreeParser::constructTree(const std::string &treeString) {
    if (!this->isValidTree(treeString)) {
        throw "ERROR: Invalid tree exception!";
    }

    int data;
    std::string subtreesString;

    std::regex rgx(this->TREE_PATTERN);
    std::sregex_iterator iter(treeString.begin(), treeString.end(), rgx);
    data = stoi((*iter)[1]);
    subtreesString = ((*iter)[2]);

    Tree tree(data);

    if (!std::regex_match(subtreesString, std::regex("\\s*"))) {
        std::list<std::string> subtrees = getSubtrees(subtreesString);
        for (std::list<std::string>::const_iterator it = subtrees.begin(); it != subtrees.end(); ++it) {
            tree.addChild(constructTree(*it));
        }
    }

    return tree;
}

std::list<std::string> TreeParser::getSubtrees(std::string subtreesString) {
    std::list<std::string> subtreesList;

    int bracketBalance = 0;
    bool isInsideBracket = false;
    int start = 0, end = 0;
    for (int i = 0; i < subtreesString.size(); ++i) {
        if(subtreesString[i] == '('){
           if(!isInsideBracket){
               isInsideBracket = true;
               start = i;
           }
            bracketBalance++;
        }
        if(subtreesString[i] == ')'){
            bracketBalance--;
        }

        if(bracketBalance == 0 && isInsideBracket){
            end = i;
            subtreesList.push_back(subtreesString.substr(start, end - start + 1));
            isInsideBracket = false;
        }
    }

    return subtreesList;
}
