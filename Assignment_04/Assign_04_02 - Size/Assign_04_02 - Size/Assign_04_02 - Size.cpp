// Assign_04_02 - Size.cpp : Defines the entry point for the console application.
/*
Problem 2 (10 points)

Using the Tree from part one implement recursively:

//Returns the numbers of elements in the tree

int size();

or

int size(Tree* tree);
*/

/*	Tyler Quayle  */
#include "stdafx.h"
#include <iostream>

using namespace std;

class Tree
{
	private:
	  int _value;
	  Tree* _left;
	  Tree* _right;

	public:
	  Tree(int value, Tree* left, Tree* right) 
	  {
		_value	=	value;
		_left	=	left;
		_right	=	right;
	  };
 
	  int value()	{return _value;};		//Returns the value in the top of the tree
  
	  Tree* left()	{return _left;};		//Returns the left branch of the tree
  
	  Tree* right()	{return _right;};		//Returns the right branch of the tree
};

int size(Tree* tree)
{
	if(tree != NULL)
		return 1 + size(tree->left()) + size(tree->right());
	
	return 0;
};

int depth(Tree* tree)
{
	if (tree == NULL) return 0;
	
	int left_depth = depth(tree->left());
	int right_depth = depth(tree->right());
	
	return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
};

int sum(Tree* tree)
{
	if(tree == NULL) return 0;

	return tree->value() + sum(tree->left()) + sum(tree->right());
};

bool identical(Tree* tree1, Tree* tree2)
{
    if (tree1 == tree2) {return true;}
    
	if (tree1 == NULL || tree2 == NULL) {return false;}
	
	return	(tree1->value() == tree2->value()) &&
			identical(tree1->left(), tree2->left()) &&
			identical(tree1->right(), tree2->right());
}


int main()
{
	Tree* temp = new Tree(8, new Tree(3, new Tree(1, NULL, NULL), new Tree(6, new Tree(4, NULL, NULL), 
		new Tree(7, NULL, NULL))), new Tree(10, NULL, new Tree(14, new Tree(13, NULL, NULL), NULL)));

	Tree* temp_not_equal = new Tree(9, new Tree(4, new Tree(1, NULL, NULL), new Tree(7, new Tree(5, NULL, NULL), 
		new Tree(8, NULL, NULL))), new Tree(11, NULL, new Tree(15, new Tree(14, NULL, NULL), NULL)));

	Tree* temp_equal = new Tree(8, new Tree(3, new Tree(1, NULL, NULL), new Tree(6, new Tree(4, NULL, NULL), 
		new Tree(7, NULL, NULL))), new Tree(10, NULL, new Tree(14, new Tree(13, NULL, NULL), NULL)));

	cout	<< "Size of tree: "<< size(temp) << endl;

	cout	<< "Depth of tree: "<< depth(temp) << endl;

	cout	<< "Sum of tree: "<< sum(temp) << endl;

	cout	<< boolalpha;

	cout	<< "Trees identical: "<< identical(temp, temp_equal) << endl;

	cout	<< "Trees identical: "<< identical(temp, temp_not_equal) << endl;

	system("pause");

	return 0;
}


