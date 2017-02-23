// Assign_05_02 - Comb Sort.cpp : Defines the entry point for the console application.
//

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>

using namespace std;


void combSort(int input[], int length)
{
	int gap = length;
	double shrink = 1.3;
	bool swapped;
	
	do{
		swapped = false;
		gap = gap/shrink;
		
		if(gap < 1)
			gap = 1;
		
		for(int i=0; i < length-gap; ++i)
		{
			if(input[i] > input[i+gap])
			{
				swapped = true;
				swap(input[i], input[i+gap]);
			}
		}

	}while(gap > 1 || swapped);
}

int main()
{
	
	int data [] = {5,11,7,3,1,13,19,17};
	int arraySize = sizeof(data)/sizeof(data[0]);			//as sizeof() gives size in bytes

	cout << "\nPre Combsort:\t";
	for(int i = 0; i < arraySize; i++)
		cout << " " << data[i];

	combSort(data, arraySize);

	cout << "\n\nPost Combsort:\t";
	for(int i = 0; i < arraySize; i++)
		cout << " " << data[i];

	cout << "\n\n";
	system("pause");
	return 0;
}

