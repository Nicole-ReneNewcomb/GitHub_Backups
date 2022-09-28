/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_3.cpp
   Date: September 18, 2022
   School: Santa Ana College (SAC)
   Description: Monthly Payment Calculator */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// Define & Initialize Variables
	double payment = double();
	double annualRate = double(); // most users probably know their annual rate and not monthly
	double rate = double(); // monthly interest rate - annual / 12
	double n = double(); // number of payments
	double l = double(); // amount of loan
	double totalLoanCost = double(); // total cost of loan payback, including interest
	double totalLoanInterest = double(); // total loan interest paid over course of loan


	// Request Input and Store User Entries
	cout << "Loan Monthly Payment Calculator" << endl;
	cout << "===============================" << endl;
	cout << "What is the total loan balance? Enter without $ or commas, please." << endl;
	cin >> l;
	// didn't want to ask user to do the math from annual to monthly
	cout << "What is the annual interest rate? Enter w/o the percent sign, please. (E.g. 5, 7.5, or 10.25)" << endl;
	cin >> annualRate;
	cout << "How many payments will be made until the loan is paid off?" << endl;
	cin >> n;


	// Process Input - Calculations
	rate = annualRate / 12; // convert from annual rate user input to monthly
	payment = l * ((rate / 100 * pow((1 + rate / 100), n)) / (pow((1 + rate / 100), n) - 1));
	totalLoanCost = n * payment;
	totalLoanInterest = n * payment - l;


	// Output - Header
	cout << endl;
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_3.cpp" << endl;
	cout << "Date: September 18, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;


	// Output - Program
	cout << endl;
	cout << setw(25) << left << "Loan Amount:" << setw(1) << "$" << setw(10) << right << fixed << setprecision(2) << l << endl;
	// changing to defaultfloat so displays decimals when needed: 1% for 12% annually or 1.25% for 15% annually
	cout << setw(25) << left << "Monthly Interest Rate:" << setw(10) << right << defaultfloat << setprecision(5) << rate << "%" << endl;
	cout << setw(25) << left << "Number of Payments:" << setw(11) << right << n << endl;
	cout << setw(25) << left << "Monthly Payment:" << setw(1) << "$" << setw(10) << right << fixed << setprecision(2) << payment << endl;
	cout << setw(25) << left << "Amount Paid Back:" << setw(1) << "$" << setw(10) << right << totalLoanCost << endl;
	cout << setw(25) << left << "Interest Paid:" << setw(1) << "$" << setw(10) << right << totalLoanInterest << endl;

	system("pause");
	return 0;
}