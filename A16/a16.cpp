/* =================================================================================================

	Programmer:       Emaad Ilyas
	Course:           CS 1A - Introduction to Computer Science 1
	Assignment:       Lab A16 - Functions III: Pass by value
	Date Written:     2026-07-26
	Date Due:         2026-07-26
	Instructor:       Dr. Jefferey Barnett

	Purpose:          This program will demonstrate a pass-by-value by showing changes made
							without editing any of the previous variables. Using void function called
							inside an int main() to do this, showing the score before and after the call.

==================================================================================================== */
#include <iostream>
using namespace std;

void addBonus(int functionScore); // prototype for the variable to be called for above the main()

int main()
{
	int score; // establishing variable score
	cout << "Enter your score: "; // prompting the user to input a number for variable
	cin >> score; // where the user will enter their input

	cout << "Before the call: " << score << endl; // printing the score before the call

	addBonus(score); // calling the function

	cout << "After the call: " << score << endl; // printing after the function

	return 0;
}

/* Function:     Pass by Value function score
	Purpose:      To add 100 to the inputted score
	Parameters:   functionScore - the score that the user had inputted
	Return:       none
	Side Effect:  Prints text to console
*/
void addBonus(int functionScore)
{
	functionScore += 100; // adds 100 to score
	cout << "Inside the function: " << functionScore << endl; // prints the score function
}

/* If the parameter was a reference instead of a copy the value from inside
	of the function would stick to the variable outside of the funciton
	and after the call would also print as 150 instead of just 50
*/
