#include <iostream>
#include "Tree.h"

using namespace std;

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    destroySubTree(root);
}

void Tree::destroySubTree(TreeNode* nodePtr) {
    if (nodePtr) {
        destroySubTree(nodePtr->left);
        destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

void Tree::insert(int num) {
    insert(root, num);
}

void Tree::insert(TreeNode*& nodePtr, int value) {
    if (nodePtr == nullptr) {
        nodePtr = new TreeNode(value);
    }
    else if (value < nodePtr->getData()) {
        insert(nodePtr->left, value);
    }
    else if (value > nodePtr->getData()) {
        insert(nodePtr->right, value);
    }
}

bool Tree::search(int num) {
    TreeNode* nodePtr = root;

    while (nodePtr) {
        if (num == nodePtr->getData())
            return true;
        else if (num < nodePtr->getData())
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }

    return false;
}

void Tree::displayInOrder() const {
    displayInOrder(root);
}

void Tree::displayInOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->data << endl;
        displayInOrder(nodePtr->right);
    }
}

void Tree::displayPreOrder() const {
    displayPreOrder(root);
}

void Tree::displayPreOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        cout << nodePtr->data << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void Tree::displayPostOrder() const {
    displayPostOrder(root);
}

void Tree::displayPostOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->data << endl;
    }
}

bool Tree::remove(int num) {
    return deleteNode(num, root);
}

bool Tree::deleteNode(int num, TreeNode*& nodePtr) {
    if (nodePtr == nullptr)
        return false;
    else if (num < nodePtr->getData())
        return deleteNode(num, nodePtr->left);
    else if (num > nodePtr->getData())
        return deleteNode(num, nodePtr->right);
    else {
        makeDeletion(nodePtr);
        return true;
    }
}

void Tree::makeDeletion(TreeNode*& nodePtr) {
    TreeNode* tempNodePtr;

    if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    else {
        tempNodePtr = nodePtr->right;

        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;

        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}
