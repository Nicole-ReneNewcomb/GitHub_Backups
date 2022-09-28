/* Nicole-Rene Newcomb's code for CSCI-2 Week 2:
   Recursion Assignment. Create recursive function
   that computes n * n/3 * n/9 * n/27 * n/81...
   where n is positive integer, n/x is integer
   division, and the quotient is multiple of 3 
   from previous quotient. Repeats as long as
   n/x > 0. */

#include <iostream>
using namespace std;

// Function Declaration
int recursive(unsigned int n);

int main()
{
	// Define & Initialize Variable
	unsigned int n = unsigned int();
	int finalValue = int();

	// Request User Input & Assign Value
	cout << "Please enter a positive integer." << endl;
	cin >> n;

	// Call Recursive Function
	finalValue = recursive(n);

	// Output - Print Result
	cout << "After recursion, the number is: " << finalValue << endl;

	return 0;
}

int recursive(unsigned int n)
{
	if (n <= 3)
	{
		return n;
	}

	return n * recursive(n / 3);
}