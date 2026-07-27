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

int main()
{

	int a, b;
	cout << "Enter two integers: ";
	cin >> a >> b;

	cout << "Before swap: " << a << " " << b << endl;

	swapValues(a, b);


	cout << "After swap: " << a << " " << b << endl;


	return 0;
}

void swapValues(int &a, int &b)
{
	int tempA = a;
	int tempB = b;
	a = tempB;
	b = tempA;
}
