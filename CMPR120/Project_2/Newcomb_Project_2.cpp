/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_2.cpp
   Date: September 11, 2022
   School: Santa Ana College (SAC) 
   Description: Stock/Comission Price */

#include <iostream>
using namespace std;

int main()
{
	// Define & Initialize Variables
	double shares = double();
	double price = double();
	double commissionPercent = double();
	double commissionPrice = double();
	double stockPrice = double();
	double totalPrice = double();

	// Request Input and Store User Entries
	cout << "Stock and Commission Price" << endl;
	cout << "==========================" << endl;
	cout << "How many shares did you purchase?" << endl;
	cin >> shares;
	cout << "How much did each share cost?" << endl;
	cin >> price;
	cout << "What percentage does your stock brocker charge? - enter decimal representation" << endl;
	cin >> commissionPercent;

	// Process Input - Calculations
	stockPrice = shares * price;
	commissionPrice = shares * price * commissionPercent;
	totalPrice = shares * price * (1 + commissionPercent);

	
	// Output - Header
	cout << endl;
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_2.cpp" << endl;
	cout << "Date: September 11, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Output - Program
	cout << endl;
	cout << "The price for the stocks is: $" << stockPrice << endl;
	cout << "The price for the commission is: $" << commissionPrice << endl;
	cout << "The total price is: $" << totalPrice << endl;


	return 0;
}