#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
    friend class Tree;

public:
    TreeNode(const int d);
    int getData() const;

private:
    TreeNode* left = nullptr;
    int data;
    TreeNode* right = nullptr;
};

#endif // !TREENODE_H
