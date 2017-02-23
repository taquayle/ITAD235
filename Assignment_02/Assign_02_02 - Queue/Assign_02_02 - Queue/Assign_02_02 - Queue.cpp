// Assign_02_02 - Queue.cpp : Defines the entry point for the console application.
/*
Question 2 - Queue (25 points)

Implement the Data Structure Queue (Links to an external site.) with the following operations:

	class queue {
	public:
	   queue() {} 
	   bool empty() {}
	   int size() {}
	   int dequeue() {}
	   void queue(int n) {}
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

class Queue
{
	Node* front;
	Node* back;
	int stackSize;

public:
	Queue()
	{
		front = NULL;
		back = NULL;
		stackSize = 0;
	}
	
	bool empty() 
	{
		if(front == NULL) 
			return true;
		else 
			return false;
	}

	int size()	{ return stackSize; }
	

	void enqueue(int n) 
	{
		Node *temp = new Node(n, NULL);

		if(front == NULL){ front = temp; }
		
		else{ back->next = temp;	}

		back = temp;
		stackSize++;
	}

	int dequeue()
	{
		if(front == NULL) return -1;

		Node* temp = front;
		int temp_element = temp->element;
		front = front->next;
		delete temp;
		temp = NULL;
		stackSize--;
		return temp_element;
	}
};

int main()
{
	
	Queue* myStack = new Queue();

	cout << "ENQUEUE:";
	for(int i = 1; i <= 13; i++)
	{
		cout << " " << i;
		myStack->enqueue(i);
	}

	cout << "\t|\tSize after Enqueue: " << myStack->size() << endl << "\nDEQUEUE:";
	while(!myStack->empty())
		cout << " " << myStack->dequeue();
	
	cout << "\t|\tSize after Dequeue: " << myStack->size() << "\n\n";
	system("pause");
	return 0;
}