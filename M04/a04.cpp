/******************************************************************************
# Author:           Kyle Noyes
# Assignment:       Assignment04 (CS161A)
# Date:             July 18, 2024
# Description:      This program will calculate the cost of the riding the ferry
#					in Washington State
# Input:            Int numAdults
#					Int numSeniors
#					Int numYouths
#					Int numBikes
#					String usingFerry
# Output:			Double fareTotal
#					Double 100 - fareTotal
#					String errorMessage
# Sources:          Assignment 4 specifications
#******************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

/* Globals */
double VEHICLE_168 = 57.90;
double FARE_ADULT = 14.95;
double FARE_SENIOR = 7.40;
double FARE_YOUTH = 5.55;
double FARE_BIKE = 4.00;

int main() {
	/* Declarations */
	int numAdults = 0;
	int numSeniors = 0;
	int numYouths = 0;
	int numBikes = 0;
	string usingFerry = " ";
	double fareTotal = 0.0;
	int errorState = 0;

	/* Force two decimal output */
	cout << fixed << setprecision(2);

	/* Instrucions and user input */
	cout << "Welcome to the Washington State Ferries Fare Calculator!" << endl;
	cout << endl;

	cout << "Fare Description                                           Ticket $" << endl;
	cout << "--------------------------------------                     --------" << endl;
	cout << "Vehicle Under 14' (less than 168\") & Driver                 $57.90" << endl;
	cout << "Adult (age 19 - 64)                                         $14.95" << endl;
	cout << "Senior (age 65 & over) / Disability                         $7.40" << endl;
	cout << "Youth (age 6 - 18)                                          $5.55" << endl;
	cout << "Bicycle Surcharge (included with Vehicle)                   $4.00" << endl;
	cout << endl;
	
	/* Get user ferry state & validate ferry state */
	cout << "Are you riding a vehicle on the Ferry (Y/N): ";
	cin >> usingFerry;

	if ((usingFerry == "n") || (usingFerry == "N") || (usingFerry == "y") || (usingFerry == "Y")) {
		if ((usingFerry == "y") || (usingFerry == "Y")) {
			fareTotal = VEHICLE_168;
		}
	}
	else {
		errorState = 1;
		cout << endl;
	}

	/* Get & validate passenger information */
	if (errorState != 1) {
		cout << "How many adults? ";
		cin >> numAdults;
		cout << endl;
		if (numAdults < 0) {
			errorState = 1;
		}
	}
	if (errorState != 1) {
		cout << "How many seniors? ";
		cin >> numSeniors;
		cout << endl;
		if (numSeniors < 0) {
			errorState = 1;
		}
	}
	if (errorState != 1) {
		cout << "How many youths? ";
		cin >> numYouths;
		cout << endl;
		if (numYouths < 0) {
			errorState = 1;
		}
	}
	if (errorState != 1) {
		if ((usingFerry == "n") || (usingFerry == "N")) {
			cout << "How many bikes? ";
			cin >> numBikes;
			cout << endl;
			if (numBikes < 0) {
				errorState = 1;
			}
		}
	}

	/* Check error state. If != 1, check num people. If numPeople < 21, proceed to calc */
	if (errorState == 1) {
		cout << "Error!! Invalid answer!! Please try again later!!!" << endl;
	}
	else if ((numAdults + numSeniors + numYouths) > 20) {
		cout << "Uh oh!! Too many people in your group. Split into 2 groups and try again!" << endl;
	}
	/* Saving fare calc for this point to minimize resource usage */
	else {
		fareTotal = fareTotal + (numAdults * FARE_ADULT);
		fareTotal = fareTotal + (numSeniors * FARE_SENIOR);
		fareTotal = fareTotal + (numYouths * FARE_YOUTH);
		fareTotal = fareTotal + (numBikes * FARE_BIKE);


		cout << "Your total charge is $" << fareTotal << endl;
		cout << endl;

		if (fareTotal >= 100) {
			cout << "You have spent $100 or more. You have received a free adult ticket\nfor your next trip" << endl;
		}
		else {
			cout << "If you spend $";
			cout << 100 - fareTotal;
			cout << " more, you are eligible for a free adult ticket for the next trip." << endl;
		}
	}
	cout << endl;

	/* Program end & successful run message */
	cout << "Thank you for using Washington State Ferries Fare Calculator!" << endl;

	return 0;
}