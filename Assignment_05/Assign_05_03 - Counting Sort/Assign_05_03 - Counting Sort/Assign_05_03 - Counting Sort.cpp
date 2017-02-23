// Assign_05_03 - Counting Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;



void CountSort( int* input, int input_length )
{
	int min = 0;
	int max = 0;
	int j = 0;
		
	for( int i = 0; i < input_length; i++ )
	{
		if( input[i] > max ) max = input[i];
		if( input[i] < min ) min = input[i];
	}
		
	int sort_length = ( max - min ) + 1; 
		
	int* temp = new int[sort_length];
		
	for( int i = 0; i < sort_length; i++ ) temp[i] = 0; 
		
	for( int i = 0; i < input_length; i++ ) temp[input[i] - min]++;
 
	for( int i = min; i <= max; i++ )
	{
		while( temp[i - min] )
		{
			input[j++] = i;
			temp[i - min]--;
		}
	}
 
	delete [] temp;
}
 
int main()
{
	
	int data [] = {5,11,7,3,1,13,19,17,5,11,3,1};
	int arraySize = sizeof(data)/sizeof(data[0]);			//as sizeof() gives size in bytes

	cout << "\nPre CountSort:\t";
	for(int i = 0; i < arraySize; i++)
		cout << " " << data[i];

	CountSort(data, arraySize);

	cout << "\n\nPost CountSort:\t";
	for(int i = 0; i < arraySize; i++)
		cout << " " << data[i];

	cout << "\n\n";
	system("pause");
	return 0;
}

