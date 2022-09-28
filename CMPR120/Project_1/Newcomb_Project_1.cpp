/* Nicole-Rene Newcomb
   Newcomb_Project_1.cpp
   September 3, 2022
   Santa Ana College (SAC) */

#include <iostream>
using namespace std;

int main()
{
	// Declare Variables
	int employeeID;
	double hoursWorked;
	double hourlyRate;
	double grossSalary;

	// Request Input and Store User Entries
	cout << "Employee Salary Records" << endl;
	cout << "=======================" << endl;
	cout << "What is the Employee ID Number?" << endl;
	cin >> employeeID;
	cout << "How many hours did this employee work?" << endl;
	cin >> hoursWorked;
	cout << "What is the employee's pay rate per hour?" << endl;
	cin >> hourlyRate;

	// Process Input - Calculate grossSalary
	grossSalary = hoursWorked * hourlyRate;

	// Output
	cout << "Nicole-Rene Newcomb" << endl;
	cout << "Newcomb_Project_1.cpp" << endl;
	cout << "September 3, 2022" << endl;
	cout << "Santa Ana College (SAC)" << endl;
	cout << "=============================================" << endl;
	cout << "Employee ID: " << employeeID << endl;
	cout << "Hours Worked: " << hoursWorked << endl;
	cout << "Rate per Hour: " << hourlyRate << endl;
	cout << "Gross Salary: $" << grossSalary << " / week" << endl;
	cout << "=============================================" << endl;

	return 0;
}