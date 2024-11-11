#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

class Tree {
public:
	Tree();
	~Tree();

	// Binary tree operations
	void insert(int);
	bool search(int);
	bool remove(int);

	// Traversals 
	void displayInOrder() const;

	// New methods
	int subtreeSize(int) const;
	bool isAncestor(int me, int ancestor) const;
	int numberOfChildren(int) const;

private:
	TreeNode* root; // Pointer to the root

	void insert(TreeNode*&, int);
	void displayInOrder(TreeNode*) const;

	// Helper functions for new methods
	int subtreeSize(TreeNode*) const;
	bool isAncestor(TreeNode*, int) const;
	int numberOfChildren(TreeNode*) const;
};

#endif
