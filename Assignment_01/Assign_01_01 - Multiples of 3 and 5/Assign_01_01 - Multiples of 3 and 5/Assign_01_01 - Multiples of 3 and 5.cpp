// Assign_01_01 - Multiples of 3 and 5.cpp : Defines the entry point for the console application.
/*
Problem 1 (25 points)

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Design and implement an algorithm that calculates the sum of all the multiples of 3 or 5 below 1000.
*/

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int N = 1000;
	int sum = 0;

	/* This way only counts multiples of 15 once, way you showed in class multiples of 15 were added twice, 1 for each loop*/
	for (int i = 0; i < N; i++)
		if(i % 5 == 0 || i % 3 == 0) sum += i;

	cout << sum << endl;
	
	system("pause");
	return 0;
}

