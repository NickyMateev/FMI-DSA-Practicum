#include "Tree.h"

Tree::Tree(int data) {
    this->data = data;
}

Tree &Tree::addChild(const Tree &tree) {
    this->children.push_back(tree);
    return *this;
}

int Tree::getRoot() const {
    return this->data;
}

const std::list<Tree> &Tree::getSubtrees() const {
    return this->children;
}

std::ostream& operator<<(std::ostream &os, const Tree& tree) {
    os << '(' << tree.getRoot();
    for (std::list<Tree>::const_iterator it = tree.getSubtrees().begin(); it != tree.getSubtrees().end(); it++) {
        os << ' ' << *it;
    }
    os << ')';

    return os;
}
