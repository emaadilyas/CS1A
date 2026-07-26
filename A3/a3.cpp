/* ============================================================================

	Programmer:               Emaad Ilyas
	Course:                   CS 1A - Introduction to Computer Science I
	Assignment:               Lab A3 - Variables and Output
	Date Written:             2026-06-25
	Due date:                 2026-06-28
	Instructor:               Dr. Jeffery Barnett

	Purpose:                  Declare typed variable, assign values, compute
	                          the total cost, and print a clean readable result.

============================================================================= */

// both of these allow the code to do input
// and output and make it easy to read and write
#include <iostream>
#include <string>
using namespace std;


// start of the main code
int main() {

// all assigned variables needed for rest of code

string studentName = "Ada";
int units = 12;
double costPerUnit = 46.50;
double totalCost = units * costPerUnit;

// code that uses variables to write the desired output

cout << "Student: " << studentName << endl;
cout << "Units: " << units << endl;
cout << "Cost per unit: " << costPerUnit << endl;
cout << "Total cost: " << totalCost << endl;


return 0;
}
