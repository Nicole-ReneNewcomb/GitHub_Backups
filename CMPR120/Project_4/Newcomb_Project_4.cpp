/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_4.cpp
   Date: October 2, 2022
   School: Santa Ana College (SAC)
   Description: Quadratic Formula Solver */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// Define & Initialize Variables
	int userinputA = int();
	int userinputB = int();
	int userinputC = int();
	int discriminant = int();
	double result1 = double();
	double result2 = double();
	double imaginaryResult = double();

	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_4.cpp" << endl;
	cout << "Date: October 2, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Explains Program, Requests Input, and Stores User Entries
	cout << endl;
	cout << "This Quadratic Equation Solver will solve equations in the form of: " << endl;
	cout << "A*x^2 + B*x + C = 0, where A, B, and C are integers, and A is not equal to zero. \n" << endl;
	cout << "Please enter the values of A, B, and C on one line seperated by a single space:" << endl;
	cin >> userinputA >> userinputB >> userinputC;


	// Process Input - Calculations
	discriminant = pow(userinputB, 2) - 4 * userinputA * userinputC;
	result1 = (-userinputB + sqrt(discriminant)) / (2 * (double)userinputA);
	result2 = (-userinputB - sqrt(discriminant)) / (2 * (double)userinputA);





	// Output - Program
	if (userinputA == 0)
	{
		cout << "Dividing by 0 equals infinity, so please do not enter a value of 0 for A!" << endl;
	}
	else
	{
		if (discriminant == 0)
		{
			cout << "The one real solution is: " << endl;
			cout << fixed << setprecision(4) << scientific << "x = " << result1 << endl;
		}
		else if (discriminant > 0)
		{
			cout << "The two real solutions are:" << endl;
			cout << "x = " << fixed << setprecision(4) << scientific << setw(11) << right << result1 << " and " << endl;
			cout << "x = " << fixed << setprecision(4) << scientific << setw(11) << right << result2 << endl;
		}
		else if (discriminant < 0)
		{
			result1 = -(userinputB) / (2 * (double)userinputA);
			result2 = -(userinputB) / (2 * (double)userinputA);
			imaginaryResult = sqrt(-discriminant) / (2 * (double)userinputA);
			cout << "The two imaginary solutions are: " << endl;
			cout << "x = " << fixed << setprecision(4) << scientific << setw(11) << right << result1 << " + (" << imaginaryResult << ")*I and" << endl;
			cout << "x = " << fixed << setprecision(4) << scientific << setw(11) << right << result1 << " - (" << imaginaryResult << ")*I" << endl;
		}
		else
		{
			cout << "Error: something has gone wrong. Please try again." << endl;
		}
	}

	return 0;
}