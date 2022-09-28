/* Nicole-Rene's code for CMPR120 Introduction */

#include <iostream>
using namespace std;

int main()
{
	// variables
	double gross;
	double taxes;
	double net;

	// request user input
	cout << "Please enter your monthly gross income: ";
	cin >> gross;

	// variable calculations
	taxes = gross * 0.20;
	net = gross - taxes;

	// output
	cout << "Income Calculator" << endl;
	cout << "*****************" << endl;
	cout << "Your gross income is: " << gross << endl;
	cout << "Taxes due: " << taxes << endl;
	cout << "Your total pay after taxes will be: " << net << endl;
	cin.ignore();
	cin.get();
	return 0;
}