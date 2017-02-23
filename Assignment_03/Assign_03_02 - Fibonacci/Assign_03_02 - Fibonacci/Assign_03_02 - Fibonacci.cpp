// Assign_03_01 - Factorial.cpp : Defines the entry point for the console application.
/*
Problem 2 - Fibonacci (10 points)

Implement a recursive function that prints the Fibonacci series up to the nth number int fibonnaci(int n)
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