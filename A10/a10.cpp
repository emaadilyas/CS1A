/* ==============================================================================

	Programmer:           Emaad Ilyas
	Course:               CS 1A - Introduction to Computer Science 1
	Assignment:           Lab 10 - WHILE LOOP
	Date Written:         2026-07-17
	Date Due:             2026-07-19
	Instructor:           Dr. Jefferey Barnett

	Purpose: 				 Program will trigger a loop of reading for test grades
								 until the user enters the number which will end the loop.
								 Then the program will calculate the average of all the test
								 scores with a counter based on the nmumber of tests added.

================================================================================ */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

	// establshing variables that will be used in the loop
	double totalTestScore = 0;
	double testScore;
	int numberOfTests = 0;
	double testAverage;
	int sentinel = -1;
	double highestScore;

	// asking the user to input scores so the while loop can function
	cout << "Enter test score (-1 to stop): ";
	cin >> testScore;
	highestScore = testScore;

	// the while loop that will calculate the scores
	while (testScore != sentinel)
	{
		// Adding the total score count and then the counter math will be done to calculate average
		totalTestScore = totalTestScore + testScore;
		numberOfTests = numberOfTests + 1;

		if (testScore > highestScore)
			{
				highestScore = testScore;
			}

		// prompts the user to continue in sending test scores
		cout << "Enter test score (-1 to stop): ";
		cin >> testScore;
	}
	// switch in case if they input -1 at the start
	switch (testScore == sentinel && numberOfTests == 0)
	{
		case true:
			cout << "No scores entered" << endl;
			break;

		// the normal case for what happens if they correctly input the scores
		default:
			// calculates the average and prints it out in %
			cout << fixed << setprecision(2); 										// percentages have decimals
			testAverage = totalTestScore / (double)numberOfTests;
			cout << "You entered " << numberOfTests << " scores." << endl;
			cout << "Average: " << testAverage << endl;
			cout << "Highest score: " << highestScore << endl;
			break;
	}
	return 0;
}

/* Reflection: The problem is while look instead of a for loop for one big reason.
					the program isnt told how many total tests were taken and has to creat
					it's own counter to math the average out. A for loop is usually used when
					the computer is told or already knows the currrent total of inputs its going
					to recieve so it doesn't need to cointinously going since it knows when to stop.
					A while loop on the other hand doesn't know when it's going to stop so isntead it
					has to be told when to stop by the user.
*/
