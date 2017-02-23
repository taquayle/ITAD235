// Assign_03_01 - Factorial.cpp : Defines the entry point for the console application.
/*
Problem 1 - Factorial (10 points)

Implement a recursive function that calculates the factorial of a number: int factorial (int n)
*/

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>

using namespace std;

int factorial (int n)
{
	if(n == 1) return 1;

	return n * factorial(n-1);
}

int main()
{
	int n = 5;
	cout << "\nFactorial of " << n << " is: " << factorial(n) << "\n\n";
	system("pause");
	return 0;
}