#include "TreeNode.h"

TreeNode::TreeNode(const int d)
    : left(nullptr), data(d), right(nullptr) {
}

int TreeNode::getData() const {
    return data;
}
