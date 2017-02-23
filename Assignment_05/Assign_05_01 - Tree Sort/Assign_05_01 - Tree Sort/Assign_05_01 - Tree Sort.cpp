// Assign_05_01 - Tree Sort.cpp : Defines the entry point for the console application.
//

/*	Tyler Quayle  */

/* A side note: damn pointers to hell */

#include "stdafx.h"
#include <iostream>

using namespace std;

struct BinaryTree
{
	struct BinaryTree *rightchild;
	int data;
	struct BinaryTree *leftchild;
};

void insert(struct BinaryTree **temp, int num)
{
	if(*temp == NULL)
	{
		*temp = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
		( *temp ) -> leftchild = NULL ;
        ( *temp ) -> data = num ;
        ( *temp ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *temp ) -> data )
            insert ( &( ( *temp ) -> leftchild ), num ) ;
        else
            insert ( &( ( *temp ) -> rightchild ), num ) ;
    }
	return;
}

void InOrder(struct BinaryTree *output)
{
	if(output != NULL)
	{
		InOrder(output->leftchild);
		cout << " " << output->data;
		InOrder(output->rightchild);
	}
	else
		return;
}

void TreeSort(int* data, int size)
{
	struct BinaryTree* searchTree;
	searchTree = NULL;
	
	for(int i = 0; i < size; i++)
		insert(&searchTree, data[i]);

	InOrder(searchTree);
}

int main()
{
	int inputArray [] = { 3, 7, 5, 11, 1, 13, 19, 17, 23 };
	int arraySize = sizeof(inputArray)/sizeof(inputArray[0]);
	
	cout << "\nPre TreeSort:\t";
	for(int i = 0; i < arraySize; i++)
		cout << " " << inputArray[i];
	
	cout<< "\n\nPost TreeSort:\t";
	TreeSort(inputArray, arraySize);
	
	cout<<"\n\n";

	system("pause");
	return 0;
}