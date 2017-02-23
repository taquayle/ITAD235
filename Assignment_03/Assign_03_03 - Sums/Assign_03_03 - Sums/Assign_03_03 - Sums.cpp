// Assign_03_01 - Factorial.cpp : Defines the entry point for the console application.
/*
Problem 3 - Sum (10 points)

Implement a recursive function that sums all the elements in a list int sum(list l)
*/

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>

using namespace std;

int fibonacci (int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n = 12;
	cout << "\n" << n << " iterations into the fibonacci sequence is: " << fibonacci(n) << "\n\n";
	system("pause");
	return 0;
}