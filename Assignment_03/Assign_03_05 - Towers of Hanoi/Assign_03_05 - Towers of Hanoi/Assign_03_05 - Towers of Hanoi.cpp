// Assign_03_05 - Towers of Hanoi.cpp : Defines the entry point for the console application.
/*
Problem 5 - Towers of Hanoi (25 points)

Implement a recursive solution to the Towers of Hanoi problem. The solution should work for three rodes and 8 disks and print out the steps to solve the problem.
*/

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>

using namespace std;

void towerMove(int n_disks, char fromPeg, char toPeg, char helpPeg)
{
		if(n_disks>1)towerMove(n_disks-1, fromPeg, helpPeg, toPeg);                                                 
   	    
		cout << "D("<< n_disks << ")[" << fromPeg << " -> " << toPeg << "]\t";       
			
		if(n_disks>1) towerMove(n_disks-1, helpPeg, toPeg, fromPeg);      
}


int main()
{
	int number_of_disks = 8;
	char start_peg = 'A', end_peg = 'C', help_peg = 'B';

	cout << "Towers of Hanoi - Moving " << number_of_disks << " disks from peg " << start_peg << " to peg " << end_peg << "\n\n";
	cout << "D(n) indicates disk, 1 being smallest, " << number_of_disks << " being largest\n\n";

	towerMove(number_of_disks, start_peg, end_peg, help_peg);

	cout << "\n\n";
	system("pause");
	return 0;
}

