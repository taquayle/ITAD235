// Assign_04 - Tyler Quayle.cpp : Defines the entry point for the console application.
/*
Problem 1 (10 points)

Implement the Data Structure Tree using the following interface:

class Tree
{
private:
  int _value;
  Tree* _left;
  Tree* _right;
public:
  Tree(int value, Tree* left, Tree* right) {}
 
  int value(); //Returns the value in the top of the tree
 
  Tree* left(); //Returns the left branch of the tree
 
  Tree* right(); //Returns the right branch of the tree
};
 

Problem 2 (10 points)

Using the Tree from part one implement recursively:
int size(Tree* tree);

Problem 3 (15 points)

Using the Tree from part one implement recursively:
int depth(Tree* tree);

 

Problem 4 (15 points)

Using the Tree from part one implement recursively:
int sum(Tree* tree);

 

Problem 5 (25 points)

Using the Tree from part one implement recursively:

//Returns true if the two threes are identical

bool identical(Tree* tree1, Tree* three2);
*/

/*	Tyler Quayle  */
#include "stdafx.h"
#include <iostream>

using namespace std;

class Tree		/*	Problem 1 */
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

int size(Tree* tree)	/*	Problem 2 */
{
	if(tree == NULL)	return 0;

	return 1 + size(tree->left()) + size(tree->right());
};

int depth(Tree* tree)	/*	Problem 3 */
{
	if (tree == NULL)	return 0;
	
	int left_depth = depth(tree->left());
	int right_depth = depth(tree->right());
	
	return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
};

int sum(Tree* tree)	/*	Problem 4 */
{
	if(tree == NULL)	return 0;

	return tree->value() + sum(tree->left()) + sum(tree->right());
};

bool identical(Tree* tree1, Tree* tree2)	/* Problem 5 */
{
    if (tree1 == NULL && tree2 == NULL) {return true;}
    
	if (tree1 == NULL || tree2 == NULL) {return false;}
	
	return	(tree1->value() == tree2->value()) &&
			identical(tree1->left(), tree2->left()) &&
			identical(tree1->right(), tree2->right());
}


int main()
{
	Tree* base = new Tree(8, new Tree(3, new Tree(1, NULL, NULL), new Tree(6, new Tree(4, NULL, NULL), 
		new Tree(7, NULL, NULL))), new Tree(10, NULL, new Tree(14, new Tree(13, NULL, NULL), NULL)));

	Tree* base_not_equal = new Tree(9, new Tree(4, new Tree(1, NULL, NULL), new Tree(7, new Tree(5, NULL, NULL), 
		new Tree(8, NULL, NULL))), new Tree(11, NULL, new Tree(15, new Tree(14, NULL, NULL), NULL)));

	Tree* base_equal = base;

	cout	<< "Size of tree:\t"	<< size(base)	<< endl;

	cout	<< "\nDepth of tree:\t"	<< depth(base)	<< endl;

	cout	<< "\nSum of tree:\t"	<< sum(base)	<< endl;

	cout	<< boolalpha;

	cout	<< "\nTrees identical	(base, base_equal):\t"		<< identical(base, base_equal) << endl;

	cout	<< "\nTrees identical	(base, base_not_equal):\t"	<< identical(base, base_not_equal) << "\n\n";

	system("pause");

	return 0;
}