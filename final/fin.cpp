/*
Copy the below section and paste in your Design Document
I understand that acts of academic dishonesty may be penalized to the full extent
allowed by the Portland Community College Student Conduct Code, including receiving
a failing grade for this exam. I recognize that I am responsible for understanding
the provisions of the PCC Student Conduct Code as they relate to this Course
Challenge Exam.
*/

/******************************************************************************
# Author:           Kyle Noyes
# Assignment:       Final (CS161A)
# Date:             Sep 4th, 2024
# Description:      This program will calculate your total miles cycled
#					and tell you if you have met your target goal or not
# Input:			Int milesTarget
#					Int milesDay
# Output:			Int milesTotal
#					Int goalDif
# Sources:          Final specifications
#******************************************************************************/


#include <stdio.h>
#include <iostream>
using namespace std;


// init functions
void inputPrompt(int msgCode);
void errorHandle(int errCode);
int calcTotal(int milesDay, int milesTotal, int runState);
void getInput(int& goal);
void validateInput(int& userInput, int& runState, bool allowNeg);
void consoleClear();


// main program handler
int main() {
	int milesTarget = 0;
	int milesDay = 0;
	int milesTotal = 0;
	int goalDif = 0;
	int runState = 0;

	cout << "Welcome to my Miles Tracker program." << endl;
	cout << endl;

	inputPrompt(0);
	do {
		getInput(milesTarget);
		validateInput(milesTarget, runState, true);
		if (runState == 1) {
			consoleClear();
			errorHandle(0);
		}
	} while (runState != 0);

	if (milesTarget <= 0) {
		cout << endl;
		cout << "No miles were tracked this week." << endl;
		cout << endl;
	}
	else {
		milesTotal = calcTotal(milesDay, milesTotal, runState);
		cout << endl;

		goalDif = milesTarget - milesTotal;

		cout << "You rode " << milesTotal << " miles this week." << endl;

		if (goalDif > 0) {
			cout << "Uh oh! You missed your goal by " << goalDif << " miles!" << endl;
		}
		else if (goalDif < 0) {
			cout << "Great job! You exceeded your goal by " << (milesTotal - milesTarget) << " miles!" << endl;
		}
		else {
			cout << "Good job! You met your goal!" << endl;
		}
		cout << endl;
	}

	cout << "Keep riding!" << endl;


	return 0;
}


// message prompt retainer for easy edits
void inputPrompt(int msgCode) {
	switch (msgCode) {
		case(0):
			cout << "How many miles do you want to ride this week? ";
			break;
		case(1):
			cout << "How many miles did you ride on Sunday? ";
			break;
		case(2):
			cout << "How many miles did you ride on Monday? ";
			break;
		case(3):
			cout << "How many miles did you ride on Tuesday? ";
			break;
		case(4):
			cout << "How many miles did you ride on Wednesday? ";
			break;
		case(5):
			cout << "How many miles did you ride on Thursday? ";
			break;
		case(6):
			cout << "How many miles did you ride on Friday? ";
			break;
		case(7):
			cout << "How many miles did you ride on Saturday? ";
			break;
		default:
			cout << "Error when calling function inputPrompt with " << msgCode << endl;
	}
}


// error state handling and messaging
void errorHandle(int errCode) {
	switch (errCode) {
		case(0):
			cout << "Miles must be 0 or greater!" << endl;;
			break;
		default:
			cout << "Error when calling function errorHandle with " << errCode << endl;
	}
}


// total calculation
int calcTotal(int milesDay, int milesTotal, int runState) {
	int i = 0;
	for (i = 0; i < 7; ++i) {
		do {
			inputPrompt(i + 1);
			getInput(milesDay);
			validateInput(milesDay, runState, false);
			if (runState == 1) {
				consoleClear();
				errorHandle(0);
			}
			else {
				milesTotal = milesTotal + milesDay;
			}
		} while (runState != 0);
	}
	return milesTotal;
}


// prompt for user input
void getInput(int& goal) {
	cin >> goal;
}


// validate user input. Also takes a flag that allows neg numbers or not
void validateInput(int &userInput, int &runState, bool allowNeg) {
	if (allowNeg == false) {
		if (userInput < 0) {
			runState = 1;
		}
		else {
			runState = 0;
		}
	}
	else {
		runState = 0;
	}
}


// clear console just in case
void consoleClear() {
	cin.clear();
	cin.ignore(100, '\n');
}