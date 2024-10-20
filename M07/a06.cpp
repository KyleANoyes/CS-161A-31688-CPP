/******************************************************************************
# Author:           Kyle Noyes
# Assignment:       Assignment06 (CS161A)
# Date:             August 5, 2024
# Description:      This program will calculate the total cost of a pizza order
#					when given the number of people, average slices eaten, and
#					the cost of each pizza
# Input:            Int numPeople
#					Double numSlicesEaten
#					Double unitCost
#					String newOrder
# Output:			Int numPizza
#					Double pizzaTotalCost
#					Double orderTax
#					Double deliverycost
#					Double orderTotal
# Sources:          Assignment 4 specifications
#******************************************************************************/

#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int PIZZA_SERVINGS = 8;

int main() {
	char newOrder = 'y';
	int numPeople = 0;
	double numSlicesEaten = 0.0;
	double numSlicesReq = 0.0;
	double unitCost = 0.0;
	int numPizza = 0;
	double deliveryCost = 0.0;
	double pizzaTotalCost = 0.0;
	double orderTax = 0.0;
	double orderTotal = 0.0;

	cout << fixed << setprecision(2);

	cout << "Welcome to my Pizza Party Statistics program!" << endl;
	cout << endl;

	do {
		// Prompt for user input
		cout << "Enter the number of people, average number of slices per person, and" << endl;
		cout << "the cost of a pizza separated by a space: ";
		cin >> numPeople;
		cin >> numSlicesEaten;
		cin >> unitCost;
		cout << endl;

		// Calculate order invoice
		numSlicesReq = numPeople * numSlicesEaten;
		numPizza = ceil(numSlicesReq / PIZZA_SERVINGS);
		pizzaTotalCost = unitCost * numPizza;
		orderTax = pizzaTotalCost * 0.07;
		deliveryCost = (pizzaTotalCost + orderTax) * 0.20;
		orderTotal = pizzaTotalCost + orderTax + deliveryCost;

		// Output current order
		cout << "Number of pizzas: " << numPizza << endl;
		cout << "Cost of pizzas:  $" << pizzaTotalCost << endl;
		cout << "Tax:             $" << orderTax << endl;
		cout << "Delivery:        $" << deliveryCost << endl;
		cout << "Total Cost:      $" << orderTotal << endl;
		cout << endl;

		// Prompt for new run
		cout << "Do you want to enter more (y/n): ";
		cin >> newOrder;
		newOrder = tolower(newOrder);
		cout << endl;
	} while (newOrder == 'y');

	cout << "Thank you for using my program!" << endl;

	return 0;
}