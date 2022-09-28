#include <iostream> // library allowing bult-in functions for input/output
using namespace std; // allows removal of std::

int main() // main function - where run always starts
{
	int age; // declaration - declaring age as integer variable
	double rate; // declaring rate as double (decimal) variable
	double gross;
	double hours;

	cout << "Hello World" << endl;
	cout << "===========" << endl;

	//INPUTS
	cout << "Please enter your age: ";
	cin >> age; // cin stores user input into variable
	cout << "Please enter your rate per hour: ";
	cin >> rate;
	cout << "Please enter number of hours worked: ";
	cin >> hours;

	//PROCESSING
	gross = rate * hours;

	//OUTPUTS
	cout << "Weekly Gross Income: " << gross;

}