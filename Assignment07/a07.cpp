/******************************************************************************
# Author:           Kyle Noyes
# Assignment:       Assignment07 (CS161A)
# Date:             August 16, 2024
# Description:      This program will allow you to transact coins for coffee or
#					tea. Simply enter the coins into the input, make your
#					beverage selection, and then this program will display any
#					remaining balance or amount due issues.
# Input:            String userInput
#					Int quantity
#					Int userCoin
# Output:			Double amountDue
#					Double balance
# Sources:          Assignment 4 specifications
#******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double COFFEE_TEA_PRICE = 0.25;

int main() {
	double balance = 0.0;
	double amountDue = 0.0;
	int userCoin = -1;
	string userInput = "";
	int quantity = -1;
	int runState = 2;
	string debug = "";
	// runState states: 0 = end, 1 = repeat coin add, 2 = run all statements
	// Force two decimal output
	cout << fixed << setprecision(2);

	cout << "Welcome to my Coffee/Tea Vending Machine!" << endl;
	cout << endl;

	// There is an unholy amount of Spaghetti here, but it's my spaghetti :)
	while (runState != 0) {
		//	This block adds coins until balance is 0
		do {
			cout << "Enter coins - 5, 10, or 25 only: ";
			cin >> userCoin;
			// Alter to catch fail when entering "F"
			if ((cin) && (userCoin == 0) || (userCoin == 5) || (userCoin == 10) || (userCoin == 25)) {
				balance = balance + (userCoin * 0.01);
			}
			else {
				cout << "Invalid Option! Please choose a valid option!" << endl;
				// Clear the terminal
				cin.clear();
				cin.ignore(100, '\n');
				userCoin = -1;
			}
		} while (userCoin != 0);
		cout << endl;

		// Display balance
		cout << "Your balance is $" << balance << endl;
		cout << endl;

		// Get selection
		cout << "Please pick an option ($0.25 each):" << endl;
		cout << "	C/c: Coffee" << endl;
		cout << "	T/t: Tea" << endl;
		cout << "	Q/q: Quit" << endl;

		// Validate selection
		while ((userInput != "c") && (userInput != "t") && (userInput != "q")) {
			if (userInput != "q") {
				cin >> userInput;
				userInput = tolower(userInput[0]);
				// If invalid, alert user
				if ((userInput != "c") && (userInput != "t") && (userInput != "q")) {
					cout << "Invalid Option! Please choose a valid option!" << endl;
				}
			}
		}

		// Get quantity and caluclate amount due once validated
		while ((quantity < 1) && (userInput != "q")) {
			cout << "How many would you like?" << endl;
			cin >> quantity;
			if (quantity < 1) {
				cout << "Invalid Option!" << endl;
				// Clear the terminal
				cin.clear();
				cin.ignore(100, '\n');
			}
			else {
				amountDue = quantity * COFFEE_TEA_PRICE;
			}
		}

		// Calcualte amount due
		// This is messy.... but it works. Not proud of it, it could be far better
		if ((amountDue > balance) && (userInput != "q")) {
			cout << endl;
			cout << "Your total is $" << amountDue << endl;
			cout << "Your balance is $" << balance << endl;
			cout << "Not enough change!! Please add more coins." << endl;
			cout << endl;
			// flip runState to 1 so we just trigger coin add loop. Reset vars
			runState = 1;
			quantity = 0;
			userCoin = -1;
			userInput = "";
		}
		else if ((userInput == "q") ){
			runState = 0;
			cout << endl;
			cout << "Your total is $0.00" << endl;
			cout << "Your balance is $" << balance << endl;
		}
		else {
			balance = balance - amountDue;
			runState = 0;
			cout << endl;
			cout << "Your total is $" << amountDue << endl;
			cout << "Your balance is $" << balance << endl;
		}

		if (runState == 0) {
			cout << endl;
			cout << "Thank you for using my Vending Machine Program!" << endl;
		}
	}

	return 0;
}