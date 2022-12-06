/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_12.cpp
   Date: December 4, 2022
   School: Santa Ana College (SAC)
   Description: Secret Code Decryption
   Program tries different keys to find
   a decrypted message that makes sense. */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// declare functions
void headerOutput();
int getChars();
char* arrayCreation(const int NUMBERCHARACTERS);
void arrayDecoder(char accountNumbers[], const int NUMBERCHARACTERS);

int main()
{
	// declare variables (call functions as needed)
	const int NUMBERCHARACTERS = getChars();
	char* arrayPointer = arrayCreation(NUMBERCHARACTERS);

	// call to headerOutput function for header and program description
	headerOutput();

	// call decoder function (which calls the printResults function)
	arrayDecoder(arrayPointer, NUMBERCHARACTERS);

	// delete dynamic array created in arrayCreation function
	delete arrayPointer;

	return 0;
}

void headerOutput()
{
	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_12.cpp" << endl;
	cout << "Date: December 4, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Program Description
	cout << endl;
	cout << endl;
	cout << "This program shows decrypted message output using different key values." << endl;
	cout << "=======================================================================" << endl;
	cout << endl;
}

int getChars()
{
	string tempString = string();
	int length = int();

	// open input file and find number of lines
	ifstream inputFile("secretcode.txt");

	// create String from inputFile code
	getline(inputFile, tempString);

	// get string length
	length = static_cast<int>(tempString.length());

	return length;
}

char* arrayCreation(const int NUMBERCHARACTERS)
{
	int counter = 0;

	// open input file
	ifstream inputFile("secretcode.txt");

	// create char array of appropriate capacity
	char* secretCode = new char[NUMBERCHARACTERS+1];

	// loop to add chars into array using pointer
	while (counter < NUMBERCHARACTERS && inputFile >> *(secretCode + counter))
	{
		counter++;
	}

	// add null terminator
	*(secretCode + NUMBERCHARACTERS) = 0;

	return secretCode;
}

void arrayDecoder(char secretCode[], const int NUMBERCHARACTERS)
{
	char* decodedMessage = new char[NUMBERCHARACTERS + 1];
	int charNumber = int();
	int charDecodedNumber = int();
	int arrayIndex = int();

	for (int key = 1; key <= 100; key++)
	{
		// reset arrayIndex to 0 at start of each key value loop
		arrayIndex = 0;

		while (arrayIndex < strlen(secretCode))
		{
			charNumber = secretCode[arrayIndex];
			charNumber -= key;
			
			if (charNumber < 32)
			{
				charDecodedNumber = charNumber + 127 - 32;
				*(decodedMessage + arrayIndex) = charDecodedNumber;
			}
			else
			{
				charDecodedNumber = charNumber;
				*(decodedMessage + arrayIndex) = charDecodedNumber;
			}

			arrayIndex++;
		}

		*(decodedMessage + NUMBERCHARACTERS) = 0;

		cout << "If key is " << key << ", this is the message: ";

		// loop to output message
		for (int j = 0; j < strlen(decodedMessage); j++)
		{
			cout << *(decodedMessage + j);
		}

		cout << endl;
	}

	return;
}