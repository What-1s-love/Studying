#include <iostream>
#include "Tree.h"

using namespace std;

// Constructor
Tree::Tree() : root(nullptr) {}

Tree::~Tree() {}

// insert() passes num to the recursive
void Tree::insert(int num) {
	insert(root, num);
}

void Tree::insert(TreeNode*& nodePtr, int value) {
	if (nodePtr == nullptr)
		nodePtr = new TreeNode(value);
	else if (value < nodePtr->getData())
		insert(nodePtr->left, value);
	else if (value > nodePtr->getData())
		insert(nodePtr->right, value);
}

bool Tree::search(int num) {
	TreeNode* nodePtr = root;
	while (nodePtr) {
		if (nodePtr->getData() == num)
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

// New methods

// Calculates the size of the subtree rooted at the node with the given data
int Tree::subtreeSize(int value) const {
	TreeNode* nodePtr = root;
	while (nodePtr && nodePtr->getData() != value) {
		nodePtr = (value < nodePtr->getData()) ? nodePtr->left : nodePtr->right;
	}
	return subtreeSize(nodePtr);
}

// Helper for subtreeSize
int Tree::subtreeSize(TreeNode* nodePtr) const {
	if (!nodePtr) return 0;
	return 1 + subtreeSize(nodePtr->left) + subtreeSize(nodePtr->right);
}

// Checks if ancestor is an ancestor of me
bool Tree::isAncestor(int me, int ancestor) const {
	TreeNode* nodePtr = root;
	while (nodePtr && nodePtr->getData() != ancestor) {
		nodePtr = (ancestor < nodePtr->getData()) ? nodePtr->left : nodePtr->right;
	}
	return isAncestor(nodePtr, me);
}

// Helper for isAncestor
bool Tree::isAncestor(TreeNode* nodePtr, int value) const {
	if (!nodePtr) return false;
	if (nodePtr->getData() == value) return true;
	return isAncestor(nodePtr->left, value) || isAncestor(nodePtr->right, value);
}

// Counts the number of children of the node with the given data
int Tree::numberOfChildren(int value) const {
	TreeNode* nodePtr = root;
	while (nodePtr && nodePtr->getData() != value) {
		nodePtr = (value < nodePtr->getData()) ? nodePtr->left : nodePtr->right;
	}
	return numberOfChildren(nodePtr);
}

// Helper for numberOfChildren
int Tree::numberOfChildren(TreeNode* nodePtr) const {
	if (!nodePtr) return 0;
	int count = 0;
	if (nodePtr->left) count++;
	if (nodePtr->right) count++;
	return count;
}
