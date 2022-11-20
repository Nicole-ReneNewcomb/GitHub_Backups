/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_9.cpp
   Date: November 13, 2022
   School: Santa Ana College (SAC)
   Description: Lo Shu Magic Square */

#include <iostream>
#include <iomanip>
using namespace std;

// declare functions/constants
const int SQUARESIZE = 3;
void headerOutput();
bool checkSums(int [][SQUARESIZE]);
void displayMagicResults(bool, bool);

int main()
{
	// Define & Initialize Variables
	int square[SQUARESIZE][SQUARESIZE] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
	int test[SQUARESIZE][SQUARESIZE] = {{3, 7, 9}, {4, 6, 1}, {8, 2, 5}};
	bool squareIsMagic = bool();
	bool testIsMagic = bool();

	// call to headerOutput function for header and program description
	headerOutput();

	// Call checkSums function to check if columns/rows/diagonals = 15
	squareIsMagic = checkSums(square);
	testIsMagic = checkSums(test);

	// output whether two-dimensional arrays are Lo Shu Magic Squares
	displayMagicResults(squareIsMagic, testIsMagic);

	return 0;
}

void headerOutput()
{
	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_9.cpp" << endl;
	cout << "Date: November 13, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Program Description
	cout << endl;
	cout << endl;
	cout << "This program determines if a two-dimensional aray is a Lo Shu Magic Square." << endl;
	cout << "===========================================================================" << endl;
	cout << endl;
}

bool checkSums(int square[][SQUARESIZE])
{
	int rowTotal[SQUARESIZE] = { 0 };
	int columnTotal[SQUARESIZE] = { 0 };
	int diagonal1Total = int();
	int diagonal2Total = int();

	// calculates sums in rows
	for (int i = 0; i < SQUARESIZE; i++)
	{
		for (int j = 0; j < SQUARESIZE; j++)
		{
			rowTotal[i] += square[i][j];
		}
	}
	
	// checks values in rows
	for (int i = 0; i < SQUARESIZE; i++)
	{
		if (rowTotal[i] != 15)
		{
			return false;
		}
	}

	// calculates sums in columns
	for (int i = 0; i < SQUARESIZE; i++)
	{
		for (int j = 0; j < SQUARESIZE; j++)
		{
			columnTotal[i] += square[j][i];
			
		}
	}

	// checks values in columns
	for (int i = 0; i < SQUARESIZE; i++)
	{
		if (columnTotal[i] != 15)
		{
			return false;
		}
	}

	// calculates sums in diagonals
	diagonal1Total = square[0][0] + square[1][1] + square[2][2];
	diagonal2Total = square[0][2] + square[1][1] + square[2][0];

	// checks values in diagonals
	if (diagonal1Total != 15 || diagonal2Total != 15)
	{
		return false;
	}

	return true;
}

void displayMagicResults(bool squareIsMagic, bool testIsMagic)
{
	if (squareIsMagic)
	{
		cout << "Cool! The square is a Magic Square!" << endl;
		cout << endl;
	}

	else
	{
		cout << "The square is sadly not a Magic Square..." << endl;
		cout << endl;
	}

	if (testIsMagic)
	{
		cout << "Cool! The test is a Magic Square!" << endl;
	}

	else
	{
		cout << "The test is sadly not a Magic Square..." << endl;
	}
	
	return;
}