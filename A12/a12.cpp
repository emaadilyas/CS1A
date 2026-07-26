/* =============================================================================

	Programmer:      Emaad Ilyas
	Course:          CS1A - Introduction to Computer Science with C++
	Assignment:      A12 - Nested FOR loops
	Date Written:    2026-07-17
	Date Due:        2026-07-19
	Instructor:      Dr. Jeffery Barnett

	Purpose:         Program will use nested loops to generate a
						  multiplication table. Include inner and outer
						  loops that show rows and columns, named constants
						  and a structured output to draft the multiplication table.

============================================================================== */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main ()
{

	// creating constants
	const int MIN = 0;
	const int MAX = 12;
	const string ORANGE = "\033[33m";
	const string RESET = "\033[0m";
	const string RED = "\033[31m";

	// creating the top of the ASCII Border
	cout << string(97,'-') << endl;

	// creating the header row for the columns
	cout << RED << setw(5) << "X " << ORANGE << "| " << RESET;
	for (int col = MIN; col <= MAX; col++)
		{
			cout << ORANGE << setw(4) << col << " | " << RESET;
		}
	cout << endl;
	cout << string(97,'-') << endl;

	// creating the big multiplication box
	for (int row = MIN; row <= MAX; row++)
		{
			cout << ORANGE << setw(4) << row << " | " << RESET; // this is creating the vertical header row for the rows

			// this is the nested loop doing printing the full chart
			for (int col = MIN; col <= MAX; col++)
				{
					cout << setw(4) << (row * col) << " | ";

				}
			// this is creating the end of the ASCII box
			cout << endl;
			cout << string(97,'-') << endl;
		}

	return 0;
}
