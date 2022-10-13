/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_5.cpp
   Date: October 8, 2022
   School: Santa Ana College (SAC)
   Description: calculates travel distance by hour */

#include <iostream>
using namespace std;

int main()
{
	// Define & Initialize Variables
	int speed = int();
	int hours = int();
	int distance = 0;

	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_5.cpp" << endl;
	cout << "Date: October 8, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Program Description
	cout << endl;
	cout << endl;
	cout << "This program calculates travel distance by hour based on speed and time." << endl;
	cout << "========================================================================" << endl;

	// Request User Input and Store Values
	cout << endl;
	cout << endl;
	cout << "What is the speed of the vehicle in mph?" << endl;
	cin >> speed;
	while (speed < 0)          // Input Validation Loop
	{
		cout << endl;
		cout << "Please enter a mph speed that is not less than zero." << endl;
		cin >> speed;
	}
	cout << endl;
	cout << "How many hours has it traveled?" << endl;
	cin >> hours;
	while (hours < 1)          // Input Validation Loop
	{
		cout << endl;
		cout << "Please enter a minimum of 1 hour for travel time." << endl;
		cin >> hours;
	}


	// Process Input - Calculations Inside Loop & Output
	cout << endl;
	cout << endl;
	cout << "  Hour    " << "Distance Traveled" << endl;
	cout << "---------------------------------" << endl;
	for (int i = 1; i <= hours; i++)
	{
		distance += speed;
		cout << "   " << i << "\t\t" << distance << endl;
	}

	return 0;
}