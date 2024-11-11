//implementation file for the TreeNode class
#include "TreeNode.h"

TreeNode::TreeNode(const int d)
	: left(nullptr), //pointer to left
	data(d), //tree node data
	right(nullptr) // pointer to right
{
	
}// end TreeNode constructor

// return copy of node's data
int TreeNode::getData() const {
	return data;
}//end getData function