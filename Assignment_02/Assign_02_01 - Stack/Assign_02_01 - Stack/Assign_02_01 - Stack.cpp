// Assign_02_01 - Stack.cpp : Defines the entry point for the console application.
/*
Question 1 - Stack (25 Points)

Implement the Data Structure Stack  (Links to an external site.)with the following operations:

class stack {
public:
   stack() {}
   bool empty() {}
   int size() {}
   int top() {}
   void push(int n) {}
   void pop() {}
	};
*/

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>

using namespace std;

class Node
{
public:
	int element;
	Node* next;

	Node(int elem, Node* pnext)
	{
		element = elem;
		next = pnext;
	}
};

class Stack
{
	Node* head;
	int stackSize;

public:
	Stack()
	{
		head = NULL;
		stackSize = 0;
	}
	
	bool empty() 
	{
		if(head == NULL) 
			return true;
		else 
			return false;
	}

	int size()	{ return stackSize; }
	
	void push(int n) 
	{
		Node* newNode = new Node(n, head);
		head = newNode;
		stackSize++;
	}

	int pop() 
	{
		if(head == NULL) return -1;

		Node* temp = head;
		int temp_element = temp->element;
		head = head->next;
		delete temp;
		temp = NULL;
		stackSize--;
		return temp_element;
	}
};

int main()
{
	Stack* myStack = new Stack();

	cout << "PUSH:";
	for(int i = 1; i <= 13; i++)
	{
		cout << " " << i;
		myStack->push(i);
	}

	cout << "\t|\tSize after push: " << myStack->size() << endl << "\nPOP:";
	
	while(!myStack->empty())
		cout << " " << myStack->pop();
	
	cout << "\t|\tSize after pop: " << myStack->size() << "\n\n";
	system("pause");
	return 0;
}