/* =======================================================================

	Programmer:			Emaad Ilyas
	Course:				CS 1A - Introduction to Computer Science I
	Assignment:			A18 - Strings 1: The Old Way
	Date Written:		2026-08-01
	Date Due:			2026-08-02
	Instructor:			Dr. Jeffrey Barnett

	Purpose:				Demonstrate historical C-style string manipulation
							and other basic string functions instead of the modern
							string variable. Uses char and getline and compares
							it to a target name using strcmp for sorting.

========================================================================*/
#include <iostream>
#include <cstring>
using namespace std;


int main ()
{
	// named constants for the name sizes
	const int NAME_SIZE = 20;
	const int WHOLE_SIZE = 40;

	// establishing the variables and constants
	char first[NAME_SIZE] = "Bjarne";
	char last[NAME_SIZE] = "Stroustrup";
	char whole[WHOLE_SIZE];

	// copying and appending the two halves together
	strcpy(whole, first);
	strcat(whole, " ");
	strcat(whole, last);

	// printing the name and length in characters
	cout << "first name : " << first << "  (" << strlen(first) << " characters)" << endl;
	cout << "last name : " << last << "  (" << strlen(last) << " characters)" << endl;
	cout << "whole name : " << whole << "  (" << strlen(whole) << " characters)" << endl;
	cout << endl;

	// user input area
	char inputName[NAME_SIZE];
	cout << "Enter a last name to check: ";
	cin.getline(inputName, NAME_SIZE);

	// comparing the last names
	int result = strcmp(inputName, last);

	// result if it matches or not
	if (result == 0)
	{
		cout << "Result: MATCH  (strcmp returned 0)" << endl;
	}
	else if (result < 0)
	{
		cout << "Result: no match  (" << inputName << " comes before " << last << ')' << endl;
	}
	else if (result > 1)
	{
		cout << "Result: no match  (" << inputName << " comes after " << last << ')' << endl;
	}

	return 0;
}
