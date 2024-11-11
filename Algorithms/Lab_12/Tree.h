#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

class Tree {
public:
    Tree();
    ~Tree();

    void insert(int);
    bool search(int);
    bool remove(int);

    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;

private:
    TreeNode* root = nullptr;

    void insert(TreeNode*&, int);
    void destroySubTree(TreeNode*);
    bool deleteNode(int, TreeNode*&);
    void makeDeletion(TreeNode*&);
    void displayInOrder(TreeNode*) const;
    void displayPreOrder(TreeNode*) const;
    void displayPostOrder(TreeNode*) const;
};

#endif // !TREE_H
