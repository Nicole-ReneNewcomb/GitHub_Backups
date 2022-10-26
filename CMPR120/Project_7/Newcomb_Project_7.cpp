/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_7.cpp
   Date: October 23, 2022
   School: Santa Ana College (SAC)
   Description: displays farenheit and celsius
   temperatures using function to convert. */

#include <iostream>
#include <iomanip>
using namespace std;

// declare function
double celsius(double fahrenheitTemp);

int main()
{
	// Define & Initialize Variables
	double fahrenheitTemp = double();
	double celsiusTemp = double();

	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_7.cpp" << endl;
	cout << "Date: October 23, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Program Description
	cout << endl;
	cout << endl;
	cout << "This program displays a list of temperatures in farenheit and celsius." << endl;
	cout << "======================================================================" << endl;
	cout << endl;

	// Table Header
	cout << fixed << setprecision(0) << setw(15) <<
		"Fahrenheit" << setprecision(2) << setw(15) << "Celsius" << endl;
	cout << "------------------------------------------" << endl;

	// Call celsius function in loop that prints output
	for (int i = 0; i <= 20; i++)
	{
		fahrenheitTemp = (double)i;
		celsiusTemp = celsius(fahrenheitTemp);
		cout << fixed << setprecision(0) << setw(10) << fahrenheitTemp << 
			" \370" << setprecision(2) << setw(17) << celsiusTemp << " \370" << endl;
	}

	return 0;
}

double celsius(double fahrenheitTemp)
{
	double celsiusTemp = ((double)fahrenheitTemp - 32) * 5 / 9;
	return celsiusTemp;
}