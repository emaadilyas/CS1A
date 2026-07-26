/* ==============================================================================

	Programmer:       Emaad Ilyas
	Course:           CS 1A - Intro to computer science with c++
	Assignment:       Lab A7 - Decisions (Driving Age)
	Date Written:     2026-07-09
	Date Due:         2026-09-12
	Instructor:       Dr. Jefferey Barnett

	Purpose:          Read an age and use a single if satement to display a message
	                  if the user is legally allowed to drive or not

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

	// checks if they're eligible to drive
	if (age >= 16) {
	cout << "You are legally old enough to drive." << endl;
	}
	// shows the other case if user isnt old enough
		else {
		cout << "You are not old enough to drive." << endl;
		cout << "You can drive in " << driveAge - age << " year(s)" << endl;
		}

return 0;
}

/* Reflection: I chose the edge cases 15, 16, and 18 since they were close to the deciding number
					inputting 16 passed the if statement and said that you were eligible of driving
					and putting 15 failed the if and told how many years until you have to wait until before driving.
					The reason why >= is required is that if the user puts in 16 without having the >= it will fail the user
					even though 16 is old enough to drive, which is why I put the equal sign so its greater than and equal
*/
