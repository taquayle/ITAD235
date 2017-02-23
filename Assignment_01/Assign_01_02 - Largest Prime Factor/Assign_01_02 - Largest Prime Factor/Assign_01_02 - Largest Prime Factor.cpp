// Assign_01_02 - Largest Prime Factor.cpp : Defines the entry point for the console application.
/*
Problem 2 (25 points)

Design and implement an efficient algorithm that given an integer N, returns it's largest prime factor. 
For example for 13195, whose factors are 5, 7, 13 and 29, the answer would be 29.
*/

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const int N = 250457;
	int largest = 0;
	
	bool prime[N];


	for(int i = 2; i < sqrt(N); i++)
	{
		if(prime[N])
		{
			for(int j = i*i; j < N; j += i) 
			{
				prime[j] = false;
			}
		}
	}

			
	for(int i = 1; i < N; i++)
		if(prime[i] && N % i == 0) largest = i;

	cout << "Largest prime facor of " << N << ": " << largest << endl;
	system("pause");
	return 0;
}

