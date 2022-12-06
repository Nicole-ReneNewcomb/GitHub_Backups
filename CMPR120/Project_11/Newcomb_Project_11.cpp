/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_11.cpp
   Date: November 25, 2022
   School: Santa Ana College (SAC)
   Description: Charge Account Validation
   checks user-input against known
   checking accounts from input file */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// declare functions
void headerOutput();
int getLines();
int* arrayCreation(const int NUMBERACCOUNTS);  // trying my hand at pointers
bool arraySearch(int accountNumbers[], const int NUMBERACCOUNTS);
void printResults(bool found);

int main()
{
	// declare variables (call functions as needed)
	const int NUMBERACCOUNTS = getLines();
	int* arrayPointer = arrayCreation(NUMBERACCOUNTS);

	// call to headerOutput function for header and program description
	headerOutput();

	// request user input and determine if matching account found
	bool matchFound = arraySearch(arrayPointer, NUMBERACCOUNTS);

	// call to output results with printResults function
	printResults(matchFound);

	// delete dynamic array created in arrayCreation function
	delete arrayPointer;

	return 0;
}

void headerOutput()
{
	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_11.cpp" << endl;
	cout << "Date: November 25, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Program Description
	cout << endl;
	cout << endl;
	cout << "This program checks entered number against existing checking accounts." << endl;
	cout << "======================================================================" << endl;
	cout << endl;
}

int getLines()
{
	string tempString = string();
	int counter = 0;

	// open input file and find number of lines
	ifstream inputFile("Project_11_Input_File.txt");

	// loop to count number of lines (number of checking account entries)
	while (getLine(inputFile, tempString))
	{
		counter++;
	}

	cout << tempString << endl;

	return counter;
}

int* arrayCreation(const int NUMBERACCOUNTS)
{
	int counter = 0;

	// open input file
	ifstream inputFile("Project_11_Input_File.txt");
	
	// create array of appropriate capacity
	int *accountNumbers = new int[NUMBERACCOUNTS];

	// loop to add checking account numbers into array using pointer
	while (counter < NUMBERACCOUNTS && inputFile >> *(accountNumbers + counter))
	{
		counter++;
	}

	  for (int i = 0; i < NUMBERACCOUNTS; i++)     // checking array created properly
		{
			cout << *(accountNumbers+ i) << endl;
		}  

	return accountNumbers;
}

bool arraySearch(int accountNumbers[], const int NUMBERACCOUNTS)
{
	bool matchFound = false;
	int userAccount = int();
	int matchIndex = -1;
	int arrayIndex = 0;

	cout << "Please enter your account number (ex. 1005231): " << endl;
	cout << endl;
	cin >> userAccount;
	cout << endl;

	while (arrayIndex < NUMBERACCOUNTS && !matchFound)
	{
		if (accountNumbers[arrayIndex] == userAccount)
		{
			matchFound = true;
			matchIndex = arrayIndex;
		}

		arrayIndex++;
	}

	return matchFound;
}

void printResults(bool found)
{
	if (found == false)
	{
		cout << "Sorry, that number is invalid." << endl;
	}

	else if (found == true)
	{
		cout << "Matching account found. That number is valid." << endl;
	}

	else
	{
		cout << "Error: unexpected error in printResults." << endl;
	}

	return;
}