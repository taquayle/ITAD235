// Assign_02_03 - Missing Number Problem.cpp : Defines the entry point for the console application.
/*
Question 3 - Missing Number Problem (25 points)

Using the stack you implemented in Question 1. Write an efficient algorithm that solves the missing number problem defined us:
Given a list of N-1 numbers, which includes all numbers between 1 and N except for 1, find the missing number.
The signature for the file is:

int Missing(stack s)

Make sure the code works for the following input, output combinations:

null -> -1
{} -> 1
{1} -> 2
{2} -> 1
{1, 3} -> 2
{1, 2} -> 3
{1, 4, 3, 7, 6, 2} -> 5
*/

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>
#include <time.h>

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

int missing(Stack* s)
{
	if(s->empty())
	{
		cout << "Stack is empty: ";
		return -1;
	}
	
	int missingSum = ((s->size()+1)*(s->size() + 2))/2;
	int stackSum  = 0;
	
	while(!s->empty())
	{
		stackSum += s->pop();
		//s->pop();
	}
	cout << "\nSum of stack (n-1): " << stackSum;
	cout << "\nSum of numbers (n): " << missingSum;
	cout << "\n\nNumber missing: "; 
	return missingSum-stackSum;
}

// Didn't know I could just put last case in manually until class and had already done this
Stack* fillStack(int *case_array, int n)
{
	Stack* temp = new Stack();
	cout << "\n-------------------\n"<< "\nPushing: { ";
	for(int i = 0; i < n; i++)
	{
		cout << *(case_array+i) << ", ";
		temp->push(*(case_array+i));
	}
	cout << "}\n";
	return temp;
}


int main()
{

	int case_2[] = {1};
	int case_3[] = {2};
	int case_4[] = {1, 3};
	int case_5[] = {1, 2};
	int case_6[] = {1, 4, 3, 7, 6, 2};

	Stack* myStack = new Stack();

	cout << missing(myStack) << endl;

	myStack = fillStack(case_2,1);
	cout << missing(myStack) << endl;

	myStack = fillStack(case_3,1);
	cout << missing(myStack) << endl;
	
	myStack = fillStack(case_4,2);
	cout << missing(myStack) << endl;
	
	myStack = fillStack(case_5,2);
	cout << missing(myStack) << endl;
	
	myStack = fillStack(case_6,6);
	cout << missing(myStack) << endl << endl;

	system("pause");
	return 0;
}