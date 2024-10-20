// NOTE: This template is to be used for partner practice ONLY! You must
// use the required Algorithmic Design Document for all Assignments.
/******************************************************************************
# Author:           Kyle Noyes & Owen Storms
# Lab:              Discussion #09
# Date:             August 28, 2024
# Description:      This program will help grandparents calculate their finances
#                   as they beign to retire. This program will allow them to
#                   enter their expenses, income, and see a breakdown of their
#                   financial outlook. 
# Input:            double incomeSSI
                    double incomePension
                    double incomeRetirement
                    double expenseFood
                    double expenseInsurance
                    double expenseEntertainment
# Output:           double totalIncome
                    double totalExpense
# Sources:          Discussion 9 specs, zybooks
#******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void getIncome(double& income1, double& income2, double& income3);
void getExpenses(double& expense1, double& expense2, double& expense3);
void printIncomeValues(double income1, double income2, double income3);
void printExpenseValues(double expense1, double expense2, double expense3);
void printToScrn(string prompt);
void printToScrn(string prompt, double numberOutput);
double getDouble(string prompt = "Please input a number");
void validatePositive(double& input);
void br(int input);
void br();

int main() {

    //variables
    //income
    double incomeSSI = 0.0;
    double incomePension = 0.0;
    double incomeRetirement = 0.0;
    //expenses
    double expenseFood = 0.0;
    double expenseInsurance = 0.0;
    double expenseEntertainment = 0.0;

    cout << fixed << setprecision(2);
    
    br(1);
    printToScrn("Welcome to your income / expense calculator!");
    br(2);

    getIncome(incomeSSI, incomePension, incomeRetirement);
    br(1);
    getExpenses(expenseFood, expenseInsurance, expenseEntertainment);

    br(2);
    
    printIncomeValues(incomeSSI, incomePension, incomeRetirement);
    br(1);
    printExpenseValues(expenseFood, expenseInsurance, expenseEntertainment);

    br(1);


    

}

//gets income
void getIncome(double& income1, double& income2, double& income3) {

    income1 = getDouble("Please input your social security income this month.");

    income2 = getDouble("Please input your pension fund income this month.");
    
    income3 = getDouble("Please input your retirement income this month.");

}

//gets expenses
void getExpenses(double& expense1, double& expense2, double& expense3) {
    expense1 = getDouble("Please input your monthly rent/mortgage");

    expense2 = getDouble("Please input your average medical cost per month");

    expense3 = getDouble("Please input combined misc. cost per month");
}

//prints total income
void printIncomeValues(double income1, double income2, double income3){
    double totalIncome = income1 + income2 + income3;
    printToScrn("Here is your total income", totalIncome);
}

//prints total expenses
void printExpenseValues(double expense1, double expense2, double expense3){
    double totalExpense = expense1 + expense2 + expense3;
    printToScrn("Here are your total expenses", totalExpense);
}

//prints to screen using only prompt
void printToScrn(string prompt){
    cout << prompt << endl;
}

// print to screen using prompt and number
void printToScrn(string prompt, double numberOutput){
    cout << prompt << ": " << numberOutput << endl;
}


// get iuser input for double
double getDouble(string prompt) {
    double input = 0.0;
    cout << prompt << endl;
    cout << ">>";
    cin >> input;
    validatePositive(input);
    return input;
}


// validate num is > 0
void validatePositive(double& input){
    while(input < 0){
        input = getDouble("Please enter a positive number.");
    }
}


// multi line break
void br(int input){
    for(int i = 0; i < input; i++){
        cout << endl;
    }
}

// Single line break
void br(){
    cout << endl;
}