/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_6.cpp
   Date: October 16, 2022
   School: Santa Ana College (SAC)
   Description: displays star bar chart of sales by store */

#include <iostream>
using namespace std;

int main()
{
	// Define & Initialize Variables
	int salesStore1 = int();
	int salesStore2 = int();
	int salesStore3 = int();
	int salesStore4 = int();
	int salesStore5 = int();
	int starsStore1 = int();
	int starsStore2 = int();
	int starsStore3 = int();
	int starsStore4 = int();
	int starsStore5 = int();

	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_6.cpp" << endl;
	cout << "Date: October 16, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Program Description
	cout << endl;
	cout << endl;
	cout << "This program displays star bar chart of sales by store." << endl;
	cout << "=======================================================" << endl;

	// Request User Input and Store Values
	cout << endl;
	cout << endl;
	cout << "Enter today's sales for store 1: ";
	cin >> salesStore1;
	
	while (salesStore1 < 0)          // Input Validation Loop
	{
		cout << endl;
		cout << "Please enter a positive integer for today's store 1 sales: ";
		cin >> salesStore1;
	}

	cout << "Enter today's sales for store 2: ";
	cin >> salesStore2;

	while (salesStore2 < 0)          // Input Validation Loop
	{
		cout << endl;
		cout << "Please enter a positive integer for today's store 2 sales: ";
		cin >> salesStore2;
	}

	cout << "Enter today's sales for store 3: ";
	cin >> salesStore3;

	while (salesStore3 < 0)          // Input Validation Loop
	{
		cout << endl;
		cout << "Please enter a positive integer for today's store 3 sales: ";
		cin >> salesStore3;
	}
	
	cout << "Enter today's sales for store 4: ";
	cin >> salesStore4;

	while (salesStore4 < 0)          // Input Validation Loop
	{
		cout << endl;
		cout << "Please enter a positive integer for today's store 4 sales: ";
		cin >> salesStore4;
	}

	cout << "Enter today's sales for store 5: ";
	cin >> salesStore5;

	while (salesStore5 < 0)          // Input Validation Loop
	{
		cout << endl;
		cout << "Please enter a positive integer for today's store 5 sales: ";
		cin >> salesStore5;
	}
	cout << endl;

	// Process Input - Calculations
	starsStore1 = salesStore1 / 100;   // as truncated integer, reflects each full $100 in sales
	starsStore2 = salesStore2 / 100;
	starsStore3 = salesStore3 / 100;
	starsStore4 = salesStore4 / 100;
	starsStore5 = salesStore5 / 100;


	// Output Results - Star Bar Chart Format
	cout << "SALES BAR CHART" << endl;
	cout << "(Each * = $100)" << endl;
	cout << "Store 1: " + string(starsStore1, '*') << endl;   // displaying star bar chart using repeating char via string function
	cout << "Store 2: " + string(starsStore2, '*') << endl;
	cout << "Store 3: " + string(starsStore3, '*') << endl;
	cout << "Store 4: " + string(starsStore4, '*') << endl;
	cout << "Store 5: ";
	for (int i = 0; i < starsStore5; i++)                     // displaying stars for Store 5 using loop
	{
		cout << "*";
	}
	cout << endl;


	return 0;
}