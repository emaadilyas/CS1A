/* =========================================================

	Programmer:     Ilyas Emaad
	Course:         CS 1A - Intro to computer science 1
	Assignment:     E1 - Introduction to TMUX
	Date Written:   2026-07-10
	Date Due:       2026-07-12
	Instructor:     Dr. Jeffery Barnett

	Purpose:        Act as an introduction to TMUX and show
						 what it can do.

============================================================ */

#include <iostream>
using namespace std;

int main () {

	// clear the terminal screen using ANSI excape sequence
	cout << "\033[2J\033[1;1H";

	cout << "Hello TMUX" << endl;

	return 0;
}
