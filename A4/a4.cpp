/* ====================================================================

	Programmer:          Ilyas, Emaad
	Course:              CS 1A - Introduction to Computer Science I
	Assignemnt:          Lab A4 - Expressions & Arithmetic
	Date Written:        2026-06-25
	Date Due:            2026-06-28
	Instructor:          Dr. Jeffery Barnett

	Purpose:             Evaluate six arithmetic expressions, storing each in an
                      	appropriately typed variable, and print each results.

==================================================================== */

// Basic inclusions for every code I write
#include <iostream>
using namespace std;

// start of the code chunk im thats going
// to have the project
int main() {

// global variables being set
int a = 7;
int b = 3;
double c = 2.5;

// expression variables based on variables above
int expr1 = a + b * 2;
int expr2 = (a + b) * 2;
int expr3 = a / b;
double expr4 = a / c;
double expr5 = (a + b) / c;
int expr6 = a % b;

// printing out the equivalent number to
// the expressions that were created above
cout << expr1 << endl;
cout << expr2 << endl;
cout << expr3 << endl;
cout << expr4 << endl;
cout << expr5 << endl;
cout << expr6 << endl;
cout << endl;

// EXTRA CREDIT
double expr7 = (double)a / b;
cout << expr7 << endl;
/* (double) in this specific equation makes C++ treat
	it as a temporary double, making it for only this print
	a double while b is still an int
*/

// ends it all
return 0;
}
