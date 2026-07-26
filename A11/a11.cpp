/* ====================================================================

	Programmer:       Emaad Ilyas
	Course:           CS1A - Introduction to Computer Science with C++
	Assignment:       Lab A11 - For Loop
	Date Written:     2026-07-17
	Date Due:         2026-07-19
	Instructor:       Dr. Jefferey Barnett

	Purpose:          Program will run a for loop to repeat a certain task
							for a specific number of times. In this case it will
							run a for loop that will calculate the sum of odd
							integers from 1 to 15 (inclusive). Storing the final
		 					variable in an integer named sum.

====================================================================== */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// variable for the total sum
	int sum = 0;

	// for loop establishing a variable that will be gone through, counted, and added
	for (int number = 1; number <= 15; number += 2)
		{
			sum = sum + number;
		}

	// printing the final sum of odd int from 1 to 15
	cout << "The sum of odd integers from 1 - 15 is: " << sum << endl;

		return 0;
}
