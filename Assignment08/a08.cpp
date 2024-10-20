/******************************************************************************
# Author:           Kyle Noyes
# Assignment:       Assignment08 (CS161A)
# Date:             August 25, 2024
# Description:      This program will allow you to enter all your assignemnt
#					scores, your midterm and final scores, and get a final
#					calcualtion of your class grade on a 4.0 scale.
# Input:            Int numAssignments
#					Int userInt
#					Double userDouble
# Output:			Double gradeAverage
#					Double finalGradeLetter
# Sources:          Assignment 8 specifications
#******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

const int ASSIGNMENT_WEIGHT = 60;
const int EXAM_WEIGHT = 20;

// function prototypes
void welcome();
void errorCode(int errNum);
void consoleClear();
int readInt(string prompt);
double readScore(string prompt);
double assignAverage(int numAssigns);
double calcFinalScore(double assignAvg, double midterm, double final);
char calcLetterGrade(double finalScore);


int main() {
	int numAssignments = 0;
	double assignmentAvg = 0.0;
	double midtermScore = 0.0;
	double finalScore = 0.0;
	double gradeAverage = 0.0;
	string scorePrompt = "";
	char finalGradeLetter;
	int i = 0;

	cout << fixed << setprecision(1);

	// Call welcome text
	welcome();

	// Get number of assignments
	do {
		numAssignments = readInt("Enter the number of assignments (0 to 10): ");
		if ((numAssignments < 0) || (numAssignments > 10)) {
			errorCode(0);
		}
	} while ((numAssignments < 0) || (numAssignments > 10));

	// Get scores of the assignments
	assignmentAvg = assignAverage(numAssignments);
	cout << endl;

	// Get midterm score
	do {
		midtermScore = readScore("Enter your midterm exam score: ");

		// If not allowed, throw error
		if ((midtermScore < 0) || (midtermScore > 4)) {
			errorCode(0);
		}
	} while ((midtermScore < 0) || (midtermScore > 4));

	// Get final score
	do {
		finalScore = readScore("Enter your final exam score: ");

		// If not allowed, throw error
		if ((finalScore < 0) || (finalScore > 4)) {
			errorCode(0);
		}
	} while ((finalScore < 0) || (finalScore > 4));
	cout << endl;

	// Get total score average accross all tests / assignments
	gradeAverage = calcFinalScore(assignmentAvg, midtermScore, finalScore);

	// Get final grade
	finalGradeLetter = calcLetterGrade(gradeAverage);

	cout << "Your Final Numeric score is " << gradeAverage << endl;
	cout << "Your Final Grade is " << finalGradeLetter << endl;
	cout << endl;

	cout << "Thank you for using my Grade Calculator!" << endl;

	return 0;
}


void welcome() {
	cout << "Welcome to my Final Grade Calculator!" << endl;
	cout << "Please enter the following information and I will calculate your " << endl;
	cout << "Final Numerical Grade and Letter Grade for you!" << endl;
	cout << "The number of assignments must be between 0 and 10." << endl;
	cout << "All scores entered must be between 0 and 4." << endl;
	cout << endl;
}


void errorCode(int errNum) {
	if (errNum == 0) {
		cout << "Illegal Value! Please try again!!";
	}
	else {
		cout << "Unknown error! Please alert the developer";
	}
	cout << endl;
}

void consoleClear() {
	cin.clear();
	cin.ignore(100, '\n');
}


int readInt(string prompt) {
	int userInt = 0;

	cout << prompt;
	cin >> userInt;

	consoleClear();
	return userInt;
}


double readScore(string prompt) {
	double userDouble = 0;

	cout << prompt;
	cin >> userDouble;

	consoleClear();
	return userDouble;
}


double assignAverage(int numAssigns) {
	string scorePrompt = "";
	double newScore = 0.0;
	double totalScore = 0.0;
	double calcAverage = 0.0;
	int i = 0;
	//	For loop ensures we are validating each assignment input
	for (i = 0; i < numAssigns; ++i) {
		do {
			scorePrompt = "Enter score " + to_string(i + 1) + ": ";
			newScore = readScore(scorePrompt);

			// If not allowed, throw error
			if ((newScore < 0) || (newScore > 4)) {
				errorCode(0);
			}
			// Else add to total score
			else {
				totalScore = totalScore + newScore;
			}
		} while ((newScore < 0) || (newScore > 4));
	}

	// Calc final average then return result
	calcAverage = totalScore / numAssigns;
	return calcAverage;
}


double calcFinalScore(double assignAvg, double midterm, double final) {
	double assignAvgBase100 = 0.0;
	double midtermBase100 = 0.0;
	double finalBase100 = 0.0;
	double finalGrade = 0.0;


	// Converting the scores to a base 100 system
	assignAvgBase100 = (assignAvg / 4.0) * ASSIGNMENT_WEIGHT;
	midtermBase100 = (midterm / 4.0) * EXAM_WEIGHT;
	finalBase100 = (final / 4.0) * EXAM_WEIGHT;

	// Calculate grade average in base 100
	finalGrade = (assignAvgBase100 + midtermBase100 + finalBase100) / 100;
	// Convert grade back to base 4
	finalGrade = finalGrade * 4;

	return finalGrade;
}


char calcLetterGrade(double finalScore) {
	char letterGrade;

	if (finalScore >= 3.3) {
		letterGrade = 'A';
	}
	else if ((finalScore < 3.3) && (finalScore >= 2.8)) {
		letterGrade = 'B';
	}
	else if ((finalScore < 2.8) && (finalScore >= 2.0)) {
		letterGrade = 'C';
	}
	else if ((finalScore < 2.0) && (finalScore >= 1.2)) {
		letterGrade = 'D';
	}
	else {
		letterGrade = 'F';
	}

	return letterGrade;
}