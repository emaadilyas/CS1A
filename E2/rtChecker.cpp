/* ==================================================================================

	Programmer:     Ilyas Emaad
	Course:         CS 1A - Intro to Compsci
	Assignment:     E2 - Right Triangle Checker
	Date Written:   2026-07-10
	Date Due:       2026-07-15
	Instructor:     Dr. Jeffery Barnett

	Purpose:        User inputs 3 number the computer checks if it is a
						 right triangle or not and outputs its findings back to the user

==================================================================================== */

#include <iostream>
using namespace std;

int main()
{
	double a;
	double b;
	double c;

	cout << "Enter value for 'a': ";
	cin >> a;
	if (cin.fail())
	{
		cout << "That wasn't a valid number." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		return 1;
	}

	cout << "Enter value for 'b': ";
	cin >> b;
	if (cin.fail())
	{
		cout << "That wasn't a valid number." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		return 1;
	}

	cout << "Enter value for 'c': ";
	cin >> c;

	if (cin.fail())
	{
		cout << "That wasn't a valid number." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		return 1;
	}

	if (a > 0 && b > 0 && c > 0)
	{
		if ((a * a) + (b * b) == (c * c))
		{
			cout << "Right Triangle." << endl;
		}
		else
		{
			cout << "Valid legnths, but not a right triangle" << endl;
		}
	}
	else
	{
			cout << "Error: Negative numbers aren't real geometric values, please input positive numbers" << endl;
	}

	return 0;
}

