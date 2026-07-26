/* ============================================================================

	Programmer:     Emaad Ilyas
	Course:         CS1A - Introduction to Computer Science with C++
	Assignment:     Lab A13 - Loops | Reading & Writing Files (Score Report)
	Date Written:   2026-07-21
	Date Due:       2026-07-26
	Instructor:     Dr. Jefferey Barnett

	Purpose:			 Program will take information from a text file, compute
						 statistics, and write out a report to a second file. It
						 will take class test scores txt file and use those numbers
  						 to write a report out to another txt file.

============================================================================== */
// inclusions for the programs to work
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{

	ifstream infile("scores.txt"); // opening the file for reading

	if (!infile) // checking if the file can be read
	{
		cout << "Error: could not open the source file.";
		return 1;
	}
		else
		{
			cout << "Report written to report.txt" << endl;
		}

	int score = 0;
	int count = 0;
	double total = 0;
	int highestScore = 0;
	int lowestScore = 100;

	while (infile >> score)
	{
		total = total + score;
		count++;
		if (score > highestScore)
			{
				highestScore = score;
			}
		if (score < lowestScore)
			{
				lowestScore = score;
			}
	}

	if (score == 0)
	{
		ofstream outfile("report.txt"); // the file where the report will be placed
		outfile << "Error: No scores were found." << endl;
		return 0;
	}
	else
	{
		double average = (double)total / count;

		ofstream outfile("report.txt"); // the file where the report will be placed
		outfile << "Scores read: " << count << endl;
		outfile << "Total: " << total << endl;
		outfile << fixed << setprecision(2);
		outfile << "Average: " << average << endl;
		outfile << "Highest Score: " << highestScore << endl;
		outfile << "Lowest Score: " << lowestScore << endl;
	}
	return 0;
}

/* Reflection: The reason why we use while (infile >> score) is because it will keep on going
					there is nothing left for infile to import into score, meaning that once it stops
					reading each line, the while loop will end and we will have the exact count for the
					program to give the desired output. If we had an int instead of double for our total
					the students who got potential partial credit would be rounded down and mess up our
					calculations. Since the average needs to be a decimal as well one of the variables has
					to be a double so the computer doesn't do integer math, which is also why I casted a double
					just in case it didn't work at first. The reason why we check if the file is opened already
					is so that we know that the program is running and is running correctly, if we didn't it would
					be sitting there in a failed state which is something that we don't want.
*/
