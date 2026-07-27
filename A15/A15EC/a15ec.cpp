/* =================================================================================

	Programmer:       Emaad Ilyas
	Course:           CS 1A - Introduction to Computer Science 1
	Assignment:       Functions 2: Odd or Even (a bool function)
	Date Written:     2026-07-26
	Date Due:         2026-07-26
	Instructor:       Dr. Jeffery Barnett

	Purpose:          Write a value returning function that returns a bool decision
							and then uses an if statement to report whether the inputted
							number is even or odd.

===================================================================================== */
#include <iostream>
using namespace std;


bool isEven(int number); // prototype above the main()

int main()
{
clear	int evenCounter = 0;

	for (int integer = 1; integer <= 20; integer++)
	{
		bool verdict = isEven(integer); // calls for the function using the integer the user inputted

		// prints depending if the verdict is true or not
		if (verdict)
		{
			evenCounter++;
		}
	}
	cout << "There are " << evenCounter << " even numbers between 1 and 20 (inclusive)." << endl;

	return 0;
}


/* Function:     Determining if the integer is even or not
	Purpose:      Determines if inputted value is even or not
	Parameters:   number - the integer that needs to be checked
	Return:       decision - true if number is even, false if odd
	Side effect:  none
*/
bool isEven(int number)
{
	bool decision = number % 2 == 0; // if remainder is 0 then it is true (1), if not then it returns false (0)
	return decision; // returns 1 or 0 depending if it is equal to 0 or not
}
