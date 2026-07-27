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
	int integer; // establising variable user will enter
	cout << "Enter an integer: "; // prompts the user to enter
	cin >> integer; // input saved as the variable here

	bool verdict = isEven(integer); // calls for the function using the integer the user inputted

	// prints depending if the verdict is true or not
	if (verdict)
	{
		cout << integer << " is even." << endl; // if verdict is true then the number is even
	}
	else
	{
		cout << integer << " is odd." << endl; // if the verdict is not true which is the only other thing it could be then the number is odd
	}

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
