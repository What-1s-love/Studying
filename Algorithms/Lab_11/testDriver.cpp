// Бєліков В.В.
// ОПП на мові С++
// Лабораторна робота 11
// Кінцевий строк подання: 29 жовтня
// Використано часу приблизно 130 хв
// Це моя власна робота. Не було використано сторонньої допомоги
//
// Завдання: реалізувати бінарне дерево та додати нові три методи.
// 


#include <iostream>
#include "Tree.h"

using namespace std;

void instructions();
void testFunction();

int main() {
	testFunction();

	return 0;
}//end main

// display program instructions to user
void instructions() {

}// end function instructions

//This function can be used to test Tree class;
// It builds a binary tree with 5 nodes;
// The DeleteNode function is used to remove 
void testFunction()
{
	Tree tree;

	//Insert some values into the tree
	cout << "Inserting nodes.\n";
	tree.insert(5);
	tree.insert(8);
	tree.insert(3);
	tree.insert(12);
	tree.insert(9);

	// display inorder
	cout << "Inorder traversal:\n";
	tree.displayInOrder();
	cout << endl;

	//search 3
	if (tree.search(3))
		cout << "3 is found in the tree.\n";
	else
		cout << "3 was not found in the tree.\n";

	cout << endl;

	//search 100
	if (tree.search(100))
		cout << "100 is found in the tree.\n";
	else
		cout << "100 was not found in the tree.\n";

	cout << endl;

	// Testing subtreeSize
	cout << "Subtree size of node 8: " << tree.subtreeSize(8) << endl;

	// Testing isAncestor
	if (tree.isAncestor(3, 8))
		cout << "8 is an ancestor of 9.\n";
	else
		cout << "8 is not an ancestor of 9.\n";

	// Testing numberOfChildren
	cout << "Number of children of node 5: " << tree.numberOfChildren(3) << endl;

	return;
}