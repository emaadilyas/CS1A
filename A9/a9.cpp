/* ==============================================================================

	Programmer:       Emaad Ilyas
	Course:           CS 1A - Intro to computer science with c++
	Assignment:       Lab A7 - Decisions (Driving Age)
	Date Written:     2026-07-09
	Date Due:         2026-09-12
	Instructor:       Dr. Jefferey Barnett

	Purpose:          Read an age and use a single if satement to display a message
	                  if the user is legally allowed to drive or not. If not old enough
							program will output the number of years left until the user is
							legally allowed to drive.

================================================================================= */

// basic inclusions that I put
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// initial variables required for problem
	const int DRIVING_AGE = 16;
	int age;
	char ownsCar;

	// asks the user their age
	cout << "Enter your age: ";
	cin >> age;

	int years_left = DRIVING_AGE - age;

	if (age >= DRIVING_AGE)
	{
		// asks the user if they have car or not
		// Put inside the if since its only relavent if they're old enough
		cout << "Do you own a car? (y/n): ";
		cin >> ownsCar;


		// having it in both lowercase and uppercase Y makes it more normal since they're both the same response
		// just sometimes some people have caps lock on, they both mean the same thing
		if (ownsCar == 'y' || ownsCar == 'Y')
		{
			cout << "Yes you can drive." << endl;
		}

		else
		{
			cout << "You can drive, but you need to purchase a car first!" << endl;
		}
	}
	else
	{
		cout << "Sorry you aren't old enough, but come back in " << years_left << " years and make sure to bring a car." << endl;
	}

return 0;
}

/* Reflection: First the question exists inside of the if because it's only relavent to ask if the user is able to drive
					if the user is not even old enough to drive it doesn't matter if they like inherited a car or have saved
				   for one, they cannot drive until they're old enough.
*/
