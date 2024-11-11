// Specification file for the NodeTree class
#ifndef TREENODE_H
#define TREENODE_H
class TreeNode {
	friend class Tree;
public:
	//constructor
	TreeNode(const int d);
	//return copy of node's data
	int getData() const;
private:
	TreeNode* left; //pointer to left
	int data;
	TreeNode* right; //pointer to right
};


#endif