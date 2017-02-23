// Assign_04_01 - Tree.cpp : Defines the entry point for the console application.
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
 
  int value();		//Returns the value in the top of the tree
  
  Tree* left();		//Returns the left branch of the tree
  
  Tree* right();	//Returns the right branch of the tree
};
*/

/*	Tyler Quayle  */
#include "stdafx.h"

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

int main()
{
	return 0;
}

