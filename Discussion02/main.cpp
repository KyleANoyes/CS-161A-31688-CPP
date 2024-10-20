#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	/* variable initialization */
	int empID;
	int numHours;
	double wageHour;
	double rateWithold;
	double payGross;
	double payNet;
	double deductionFICA;
	double deductionFederal;
	double deductionTotal;
	const double FICADEDUCT = 7.65;

	/* Force two decimal output */
	cout << fixed << setprecision(2);

	/* Instrucions and user input block */
	cout << "Welcome to my Weekly Payroll program!!" << endl;

	/* Data input block */
	cout << "Enter your employee ID number (numbers only): ";
	cin >> empID;
	cout << "Enter number of hours worked (whole numbers): ";
	cin >> numHours;
	cout << "Enter the hourly rate: ";
	cin >> wageHour;
	cout << "Enter the federal withholding rate: ";
	cin >> rateWithold;
	cout << endl;

	/* Data calculation block */
	payGross = numHours * wageHour;
	deductionFICA = payGross * (FICADEDUCT / 100);
	deductionFederal = payGross * (rateWithold / 100);
	deductionTotal = deductionFICA + deductionFederal;
	payNet = payGross - deductionTotal;

	/* User output block */
	cout << "Your Payroll Summary:" << endl;
	cout << "Total Gross Pay: $" << payGross << endl;
	cout << "FICA deductions: $" << deductionFICA << endl;
	cout << "Federal Tax Withholding: $" << deductionFederal << endl;
	cout << "Total deductions: $" << deductionTotal << endl;
	cout << "Net Pay: $" << payNet << endl;
	cout << endl;

	/* Program end / successful run message */
	cout << "Thank you for using my Weekly Payroll program!!" << endl;

	return 0;
}