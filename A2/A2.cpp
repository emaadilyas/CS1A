/* ----------------------------------------------------------------------------------------------
Ilyas, Emaad
CS 1A - Introduction to Computer Science 1
Assignment: A2 Favorite Number

Date Written: 2026/06/15
Date Due: 2026/06/21

Purpose:				 The program should ask the user for input on a number
						then the program will write back inputted number along with a created response

Input: A whole integer from the keyboard (1-100)	
Output: Thre lines of text to console includiding the number that the user inputted
------------------------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

int main() {
	int favoriteNumber;

	cout << "Enter your favorite number between 1 and 100: ";
	cin >> favoriteNumber;

	cout << "Amazing!! Thats my favorite number too!" << endl;
	cout << "No really!!, " << favoriteNumber << " is my favorite number!!"  << endl;

	return 0;
}
	
