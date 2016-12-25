#pragma once
#include <iostream>
#include <list>


class Tree {
private:
    int data;
    std::list<Tree> children;
public:
    Tree(int data = 0);
    Tree& addChild(const Tree& tree);
    int getRoot() const;
    const std::list<Tree>& getSubtrees() const;

    friend std::ostream& operator<<(std::ostream &os, const Tree& tree);
};
