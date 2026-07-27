/*============================================================================================

	Programmer:        Emaad Ilyas
	Course:            CS 1A Introduction to Computer Science 1
	Assignemnt:        Lab A17 - Functions IV: pass by reference (SWAP)
	Date written:      2026-07-26
	Date due:          2026-07-26
	Instructor:        Dr. Jefferey Barnett

	Purpose:           This will use a reference parameter to change the caller's variable.
							 Create a void function swap values take 2 int reference parameters and
							 exchange their values, main will read both integers and print before and
							 after the swap which should have their values exchanged.

==============================================================================================*/
#include <iostream>
using namespace std;

void swapValues(int &a, int &b); // prototype above main() promising that the function exists
void orderValues(int &a, int &b); // prototype above main() promising that the function exists

int main()
{

	int a, b; // establishing variables
	cout << "Enter two integers: "; // asking user to enter input
	cin >> a >> b; // input

	cout << "Before swap: " << a << " " << b << endl; // prints the values before swap

	swapValues(a, b); // cals the function to swap values a and b
	cout << "After swap: " << a << " " << b << endl; // prints values after swap

	orderValues(a, b); // calls the function to order the values L to G
	cout << "After swap & order in ascending: " << a << " " << b << endl; // prints values after swap and ordering

	return 0;
}

/* Function:     Least to greatest inator
	Purpose:      The purpose is to order the input from least to greatest
	Parameters:	  tempA - temporarily storing the value of A
					  tempB - temporarily storing the value of B
	Return:       nothing (void)
	Side effect:  Changes the order || orders least to greatest
*/
void orderValues(int &a, int &b)
{
	int tempA = a;
	int tempB = b;
	if (b < a)
	{
		a = tempB;
		b = tempA;
	}
}

/* Function:     Swaps values around-inator
	Purpose:      The purpose is to swap the values of a and b.
	Parameters:   tempA - temporarily storing the value of A.
					  tempB - temporarily storing the value of B.
	Return:       nothing (void)
	Side Effect:  Changes the value for the variables a and b found in the int main()
*/
void swapValues(int &a, int &b)
{
	int tempA = a;
	int tempB = b;
	a = tempB;
	b = tempA;
}

