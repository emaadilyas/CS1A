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


int main() {

	// blank variable for stuff to be
	int age;
	int driveAge = 16;


	// asks the user the question
	cout << "Enter your age: ";
	cin >> age;

	int yearsLeft = driveAge - age;

	// checks if they're eligible to drive
		if (age >= 16) {
		cout << "You are legally old enough to drive." << endl;
		}

			// shows the other case if user isnt old enough
			else {
			cout << "You are not old enough to drive." << endl;

				if (age < 16 && yearsLeft == 1) {
				cout << "You can drive in " << yearsLeft << " year." << endl;
					}
					else {
						cout << "You can drive in " << yearsLeft << " years." << endl;
						}
			}

return 0;
}

/* Reflection: Adding the else changed the behavior from A7 since it gave it an actual other case scenario
					if the original condition wasn't filled correctly and positively. One branch will either run the default
					text if you're old enough, or it will run you aren't old enough and will let you know how many years you have
					until you can drive. It will give a false on if you can drive if you input 15 and will tell you that you have
					to wait "1 year" and every other number would be "x years" plural.
*/
