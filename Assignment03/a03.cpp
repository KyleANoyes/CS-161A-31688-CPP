/******************************************************************************
# Author:           Kyle Noyes
# Assignment:       Assignment03 (CS161A)
# Date:             July 12, 2024
# Description:      This program will take the number of oreos that the user
					has eaten and calculate the servings total + total calorires
# Input:            Double numOreos
# Output:           Double numOreos
					Double numServings
					Double numCalories
# Sources:          Assignment 3 specifications
#******************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

double SERVING_SIZE = 5.0;
double SERVING_CAL = 160.0;

int main() {
	/* Declarations */
	double numOreos = 0.0;
	double numServings = 0.0;
	double numCalories = 0.0;


	/* Force one decimal output */
	cout << fixed << setprecision(1);


	/* Instrucions and user input */
	cout << "Welcome to the Oreo Calculator!" << endl;
	cout << endl;

	cout << "Enter the number of Oreos eaten: ";
	cin >> numOreos;
	cout << endl;


	/* Calculation block */
	numServings = numOreos / SERVING_SIZE;
	numCalories = numServings * SERVING_CAL;


	/* User output block */
	cout << numOreos << " Oreos equals " << numServings << " servings!" << endl;
	cout << "You consumed " << numCalories << " calories." << endl;
	cout << endl;


	/* Program end & successful run message */
	cout << "Keep eating Oreos!" << endl;


	return 0;
}