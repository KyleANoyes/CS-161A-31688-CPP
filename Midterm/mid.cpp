/******************************************************************************
# Author:           (programmer's name)
# Assignment:       (fill in with Assignment 1, etc.)
# Date:             (fill in)
# Description:      This program will calculate the fare a passenger must pay
#					when given the passengers name, number of carry on bags,
#					and number of checked bags.
# Input:            passengerName as Str
#					passengerAge as Int
#					numBagsCarryOn as Int
#					numBagsChecked as Int
# Output:           fareTotal as Int - total calculated fare
# Sources:          My own knowledge of C++ learned thus far :)

# I understand that acts of academic dishonesty may be penalized to the full 
#	extent allowed by the Portland Community College Student Conduct Code, 
#	including receiving a failing grade for this exam. I recognize that I am 
#	responsible for understanding the provisions of the PCC Student Conduct 
#	Code as they relate to this Course Challenge Exam.
#
#	Kyle Noyes
#*****************************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Globals containing pricing constants
int FARE_ADULT = 300;
int FARE_ELDER = 290;
int FARE_CARRY_ON = 10;
int FARE_CHECKED_BAG_FIRST = 25;
int FARE_CHECKED_BAG_SECOND = 50;

int main() {
	// Declarations
	string passengerName = "";
	int passengerAge = 0;
	int numBagsCarryOn = 0;
	int numBagsChecked = 0;
	int checkedBagProcessing = 0;
	int runState = 0;
	int fareTotal = 0;

	// Welcome message & instructions
	cout << "Welcome to the Complex Airfare Calculator!" << endl;
	cout << endl;

	// init user
	cout << "Please enter your name: ";
	getline(cin, passengerName);
	cout << "Hello " << passengerName << "!" << endl;

	// Get & check pax age
	cout << "Please enter age of the passenger: ";
	cin >> passengerAge;
	if (passengerAge < 0 || passengerAge > 100) {
		runState = 1;
		cout << endl;
		cout << "Age " << passengerAge << " is invalid! ";
		cout << "Sorry you cannot fly ComplexAir!";
	}

	// Get & check carry on bags
	if (runState != 1) {
		cout << "How many carry-on bags do you have (0 or 1)? ";
		cin >> numBagsCarryOn;
		if (numBagsCarryOn > 1) {
			runState = 1;
			cout << endl;
			cout << "You have too many carry-on bags! ";
			cout << "Sorry you cannot fly ComplexAir!";
		}
		else if (numBagsCarryOn < 0) {
			runState = 1;
			cout << endl;
			cout << "Number of carry-on bags is invalid! ";
			cout << "Sorry you cannot fly ComplexAir!";
		}
	}

	// Get & check checked bags
	if (runState != 1) {
		cout << "How many checked bags do you have? ";
		cin >> numBagsChecked;
		checkedBagProcessing = numBagsChecked;
		if (numBagsChecked > 5) {
			runState = 1;
			cout << endl;
			cout << "Too many checked bags (5 max)! ";
			cout << "Sorry you cannot fly ComplexAir!";
		}
		else if (numBagsChecked < 0) {
			runState = 1;
			cout << endl;
			cout << "Number of checked bags is invalid! ";
			cout << "Sorry you cannot fly ComplexAir!";
		}
	}

	// Process final fare
	if (runState != 1) {
		// Base ticket age bracket
		if ((passengerAge > 2) && (passengerAge < 60)) {
			fareTotal = fareTotal + FARE_ADULT;
		}
		else if (passengerAge >= 60) {
			fareTotal = fareTotal + FARE_ELDER;
		}

		// Carry on price
		fareTotal = fareTotal + (numBagsCarryOn * FARE_CARRY_ON);

		// Checked bags
		//     There's a bit of spaghetti in here but it's contained
		if (numBagsChecked > 1) {
			checkedBagProcessing = checkedBagProcessing - 1;
			fareTotal = fareTotal + FARE_CHECKED_BAG_FIRST;
			checkedBagProcessing = checkedBagProcessing - 1;
			fareTotal = fareTotal + (checkedBagProcessing * FARE_CHECKED_BAG_SECOND);
		}

		// Final fare output
		cout << endl;
		cout << "Your airfare is: $" << fareTotal << endl;
		cout << "Thank you for flying ComplexAir!";
	}
	cout << endl;

	return 0;
}