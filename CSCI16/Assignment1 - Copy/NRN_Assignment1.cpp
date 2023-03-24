/* Nicole-Rene Newcomb's code for Assignment 1, problems 8-11.
   Problem 8: 16-bit binary integer string to integer value.
   Problem 9: Integer value to hexadecimal string.
   Problem 10: Addition of two hexadecimal strings.
   Problem 11: Subtraction of two unsigned binary integers. */

#include <iostream>
using namespace std;

// Declare Functions
int problem8(string);
string problem9(long long);
string problem10(string, string);
string problem11(string, string);

int main()
{
	// Define Variables
	int problemNumber = int();
	string binary16String = string();
	int binaryToInteger = int();
	long long integer = int();
	string integerToHex = string();
	string hexString1 = string();
	string hexString2 = string();
	string hexAddition = string();
	string binaryString1 = string();
	string binaryString2 = string();
	string binarySubtraction = string();
	

	// Create Program Loop to Select Various Solutions
	do
	{
		// Initialize Variable
		problemNumber = 1;

		// Select Problem Number
		cout << "Please enter problem number (8-11) for solution or 0 to exit." << endl;
		cin >> problemNumber;

		// Over Integer Value Error
		if (problemNumber > INT_MAX)
		{
			cout << "Wowza! That number too large! Enter 0 to Exit or numbers 8-11 to select a problem solution." << endl;
			break;
		}

		// Exit Program Option
		else if (problemNumber == 0)
		{
			break;
		}

		// Problem 8 Solution
		else if (problemNumber == 8)
		{
			// Request User Input & Store Value
			cout << "Please enter a 16-bit binary integer" << endl;
			cin >> binary16String;

			// Convert String to Integer
			binaryToInteger = problem8(binary16String);

			// Output Integer to Display
			cout << "Here is the integer conversion: " << binaryToInteger << endl;
		}

		// Problem 9 Solution
		else if (problemNumber == 9)
		{
			// Request User Input & Store Value
			cout << "Please enter an integer value to convert to hex." << endl;
			cin >> integer;

			// Convert Integer to Hex String
			integerToHex = problem9(integer);

			// Output Hex String to Display
			cout << "Here is the Hex conversion: " << integerToHex << endl;
		}

		// Problem 10 Solution
		else if (problemNumber == 10)
		{
			// Request User Input & Store Values
			cout << "Please enter the first of two hex numbers to add together." << endl;
			cin >> hexString1;
			cout << "Please enter the second of two hex numbers to add together." << endl;
			cin >> hexString2;

			// Call Function to Add Two Hex Numbers
			hexAddition = problem10(hexString1, hexString2);

			// Output Result of Hex Addition to Display
			cout << "Here is the hexadecimal addition result: " << hexAddition << endl;
		}

		// Problem 11 Solution
		else if (problemNumber == 11)
		{
			// Request User Input & Store Values
			cout << "Please enter the first 8-digit binary number to subtract the second from." << endl;
			cin >> binaryString1;
			cout << "Please enter the second 8-digit binary number to be subtracted from the first" << endl;
			cin >> binaryString2;

			// Call Function to Add Two Hex Numbers
			binarySubtraction = problem11(binaryString1, binaryString2);

			// Output Result of Hex Addition to Display
			cout << "Here is the binary subtraction result: " << binarySubtraction << endl;
		}
		
		// Invalid Number Entries
		else if (problemNumber > 11 || problemNumber < 0)
		{
			cout << "Please enter either 0 to exit or a problem number between 8 and 11." << endl;
		}

		else if (problemNumber > 0 && problemNumber < 8)
		{
			cout << "Please enter either 0 to exit or a problem number between 8 and 11." << endl;
		}

		// Error Error Error
		else 
		{
			cout << "Something has gone horribly wrong! Error, Error... Woe is upon us!" << endl;
		}
		
	} 
	while (problemNumber != 0);

}

int problem8(string binary16String)
{
	// Define Variables
	int binaryToInteger = 0;
	int powerOfDigit = 15;

	// Loop Through String Digits
	for (int i = 0; i < 16; i++)
	{
		// Process - Calculations
		int digit = binary16String[i] - 48;
		int digitIntValue = digit * pow(2, powerOfDigit--);
		binaryToInteger += digitIntValue;
	}

	return binaryToInteger;
	
}

string problem9(long long integer)
{
	// Define Variables
	string integerToHex = string();
	int remainder[50] = {};
	char hexDigit[50] = {};
	int count = 0;

	// Loop to Divide Integer by 16 Repeatedly
	do
	{
		// Process - Calculations
		if (integer >= 16)
		{
			remainder[count] = integer % 16;
			integer = integer / 16;
		}

		else
		{
			remainder[count] = integer;
			integer = 0;
		}

		// Increment Count
		count++;

	} while (integer > 0);

	// Max Count Value
	int maxCount = count;
	count--;

	while (count >= 0)
	{
		// Convert Remainder to Hex Digits
		if (remainder[count] == 0)
		{
			hexDigit[count] = '0';
		}

		else if (remainder[count] == 1)
		{
			hexDigit[count] = '1';
		}

		else if (remainder[count] == 2)
		{
			hexDigit[count] = '2';
		}

		else if (remainder[count] == 3)
		{
			hexDigit[count] = '3';
		}

		else if (remainder[count] == 4)
		{
			hexDigit[count] = '4';
		}

		else if (remainder[count] == 5)
		{
			hexDigit[count] = '5';
		}

		else if (remainder[count] == 6)
		{
			hexDigit[count] = '6';
		}

		else if (remainder[count] == 7)
		{
			hexDigit[count] = '7';
		}

		else if (remainder[count] == 8)
		{
			hexDigit[count] = '8';
		}

		else if (remainder[count] == 9)
		{
			hexDigit[count] = '9';
		}

		else if (remainder[count] == 10)
		{
			hexDigit[count] = 'A';
		}

		else if (remainder[count] == 11)
		{
			hexDigit[count] = 'B';
		}

		else if (remainder[count] == 12)
		{
			hexDigit[count] = 'C';
		}

		else if (remainder[count] == 13)
		{
			hexDigit[count] = 'D';
		}

		else if (remainder[count] == 14)
		{
			hexDigit[count] = 'E';
		}

		else if (remainder[count] == 15)
		{
			hexDigit[count] = 'F';
		}

		else
		{
			cout << "Error: Math Has Failed. Abandon All Hope!" << endl;
		}

		// Append Characters to String
		integerToHex += hexDigit[count];

		// Decrement Count
		count--;
	}

	return integerToHex;

}

string problem10(string hexString1, string hexString2)
{
	// Define Variables
	string hexAddition = string();
	int length1 = hexString1.length();
	int length2 = hexString2.length();
	int counter1 = length1 - 1;
	int counter2 = length2 - 1;
	int hexDigit1 = int();
	int hexDigit2 = int();
	int twoDigitSum = int();
	char hexSum[1200] = {0};
	int sumCounter = 0;
	int carryValue = int();


	// Loop to Convert Hex Strings to Digits for Calculations
	while (counter1 >= 0 || counter2 >= 0)
	{
		//Where Both Strings Contain Addable Values
		if (counter1 >= 0 && counter2 >= 0)
		{
			// Converting hexString1 to hexDigit1
			if (hexString1[counter1] == '0')
			{
				hexDigit1 = 0;
			}

			else if (hexString1[counter1] == '1')
			{
				hexDigit1 = 1;
			}

			else if (hexString1[counter1] == '2')
			{
				hexDigit1 = 2;
			}

			else if (hexString1[counter1] == '3')
			{
				hexDigit1 = 3;
			}

			else if (hexString1[counter1] == '4')
			{
				hexDigit1 = 4;
			}

			else if (hexString1[counter1] == '5')
			{
				hexDigit1 = 5;
			}

			else if (hexString1[counter1] == '6')
			{
				hexDigit1 = 6;
			}

			else if (hexString1[counter1] == '7')
			{
				hexDigit1 = 7;
			}

			else if (hexString1[counter1] == '8')
			{
				hexDigit1 = 8;
			}

			else if (hexString1[counter1] == '9')
			{
				hexDigit1 = 9;
			}

			else if (hexString1[counter1] == 'A')
			{
				hexDigit1 = 10;
			}

			else if (hexString1[counter1] == 'B')
			{
				hexDigit1 = 11;
			}

			else if (hexString1[counter1] == 'C')
			{
				hexDigit1 = 12;
			}

			else if (hexString1[counter1] == 'D')
			{
				hexDigit1 = 13;
			}

			else if (hexString1[counter1] == 'E')
			{
				hexDigit1 = 14;
			}

			else if (hexString1[counter1] == 'F')
			{
				hexDigit1 = 15;
			}

			else if (hexString1[counter1] == 'a')
			{
				hexDigit1 = 10;
			}

			else if (hexString1[counter1] == 'b')
			{
				hexDigit1 = 11;
			}

			else if (hexString1[counter1] == 'c')
			{
				hexDigit1 = 12;
			}

			else if (hexString1[counter1] == 'd')
			{
				hexDigit1 = 13;
			}

			else if (hexString1[counter1] == 'e')
			{
				hexDigit1 = 14;
			}

			else if (hexString1[counter1] == 'f')
			{
				hexDigit1 = 15;
			}

			else
			{
				cout << "ERROR: Counters >= 0 hexString1 Conversion to Digits Failing." << endl;
			}


			// Converting hexString2 to hexDigit2
			if (hexString2[counter2] == '0')
			{
				hexDigit2 = 0;
			}

			else if (hexString2[counter2] == '1')
			{
				hexDigit2 = 1;
			}

			else if (hexString2[counter2] == '2')
			{
				hexDigit2 = 2;
			}

			else if (hexString2[counter2] == '3')
			{
				hexDigit2 = 3;
			}

			else if (hexString2[counter2] == '4')
			{
				hexDigit2 = 4;
			}

			else if (hexString2[counter2] == '5')
			{
				hexDigit2 = 5;
			}

			else if (hexString2[counter2] == '6')
			{
				hexDigit2 = 6;
			}

			else if (hexString2[counter2] == '7')
			{
				hexDigit2 = 7;
			}

			else if (hexString2[counter2] == '8')
			{
				hexDigit2 = 8;
			}

			else if (hexString2[counter2] == '9')
			{
				hexDigit2 = 9;
			}

			else if (hexString2[counter2] == 'A')
			{
				hexDigit2 = 10;
			}

			else if (hexString2[counter2] == 'B')
			{
				hexDigit2 = 11;
			}

			else if (hexString2[counter2] == 'C')
			{
				hexDigit2 = 12;
			}

			else if (hexString2[counter2] == 'D')
			{
				hexDigit2 = 13;
			}

			else if (hexString2[counter2] == 'E')
			{
				hexDigit2 = 14;
			}

			else if (hexString2[counter2] == 'F')
			{
				hexDigit2 = 15;
			}

			else if (hexString2[counter2] == 'a')
			{
				hexDigit2 = 10;
			}

			else if (hexString2[counter2] == 'b')
			{
				hexDigit2 = 11;
			}

			else if (hexString2[counter2] == 'c')
			{
				hexDigit2 = 12;
			}

			else if (hexString2[counter2] == 'd')
			{
				hexDigit2 = 13;
			}

			else if (hexString2[counter2] == 'e')
			{
				hexDigit2 = 14;
			}

			else if (hexString2[counter2] == 'f')
			{
				hexDigit2 = 15;
			}

			else
			{
				cout << "ERROR: Counters >= 0 hexString2 Conversion to Digits Failing." << endl;
			}


			twoDigitSum = hexDigit1 + hexDigit2;


			// When hexSum < 9 without Carry Value
			if (twoDigitSum < 9)
			{
				hexSum[sumCounter] = twoDigitSum + carryValue + '0';
				sumCounter++;
				carryValue = 0;
			}

			// When hexSum < 10 with Carry Value
			else if (twoDigitSum >= 16 && twoDigitSum < 25)
			{
				hexSum[sumCounter] = twoDigitSum + carryValue - 16 + '0';
				carryValue = 1;
				sumCounter++;
			}

			// When hexSum > 8 or < 16
			else if (twoDigitSum < 16 && twoDigitSum > 8)
			{

				if (twoDigitSum == 9 && carryValue == 1)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 0;
				}

				else if (twoDigitSum == 9 && carryValue == 0)
				{
					hexSum[sumCounter] = '9';
					carryValue = 0;
				}

				else if (twoDigitSum == 10 && carryValue == 1)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 0;
				}

				else if (twoDigitSum == 10 && carryValue == 0)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 0;
				}

				else if (twoDigitSum == 11 && carryValue == 1)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 0;
				}

				else if (twoDigitSum == 11 && carryValue == 0)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 0;
				}

				else if (twoDigitSum == 12 && carryValue == 1)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 0;
				}

				else if (twoDigitSum == 12 && carryValue == 0)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 0;
				}

				else if (twoDigitSum == 13 && carryValue == 1)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 0;
				}

				else if (twoDigitSum == 13 && carryValue == 0)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 0;
				}

				else if (twoDigitSum == 14 && carryValue == 1)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 0;
				}

				else if (twoDigitSum == 14 && carryValue == 0)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 0;
				}

				else if (twoDigitSum == 15 && carryValue == 1)
				{
					hexSum[sumCounter] = '0';
					carryValue = 1;
				}

				else if (twoDigitSum == 15 && carryValue == 0)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 0;
				}

				sumCounter++;
			}

			// When hexSum > 24 or < 32
			else if (twoDigitSum < 32 && twoDigitSum > 24)
			{
				twoDigitSum = twoDigitSum - 16;

				if (twoDigitSum == 9 && carryValue == 1)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 1;
				}

				else if (twoDigitSum == 9 && carryValue == 0)
				{
					hexSum[sumCounter] = '9';
					carryValue = 1;
				}

				else if (twoDigitSum == 10 && carryValue == 1)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 1;
				}

				else if (twoDigitSum == 10 && carryValue == 0)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 1;
				}

				else if (twoDigitSum == 11 && carryValue == 1)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 1;
				}

				else if (twoDigitSum == 11 && carryValue == 0)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 1;
				}

				else if (twoDigitSum == 12 && carryValue == 1)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 1;
				}

				else if (twoDigitSum == 12 && carryValue == 0)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 1;
				}

				else if (twoDigitSum == 13 && carryValue == 1)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 1;
				}

				else if (twoDigitSum == 13 && carryValue == 0)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 1;
				}

				else if (twoDigitSum == 14 && carryValue == 1)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 1;
				}

				else if (twoDigitSum == 14 && carryValue == 0)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 1;
				}

				else if (twoDigitSum == 15 && carryValue == 1)
				{
					hexSum[sumCounter] = '0';
					carryValue = 2;
				}

				else if (twoDigitSum == 15 && carryValue == 0)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 1;
				}


				sumCounter++;
			}

			counter1--;
			counter2--;

		}

		//Where hexString1 Ends (If Shorter Than hexString2)
		else if (counter1 < 0 && counter2 >= 0)
		{
			// Setting hexDigit1 to Zero
				hexDigit1 = 0;
		
			// Converting hexString2 to hexDigit2
			if (hexString2[counter2] == '0')
			{
				hexDigit2 = 0;
			}

			else if (hexString2[counter2] == '1')
			{
				hexDigit2 = 1;
			}

			else if (hexString2[counter2] == '2')
			{
				hexDigit2 = 2;
			}

			else if (hexString2[counter2] == '3')
			{
				hexDigit2 = 3;
			}

			else if (hexString2[counter2] == '4')
			{
				hexDigit2 = 4;
			}

			else if (hexString2[counter2] == '5')
			{
				hexDigit2 = 5;
			}

			else if (hexString2[counter2] == '6')
			{
				hexDigit2 = 6;
			}

			else if (hexString2[counter2] == '7')
			{
				hexDigit2 = 7;
			}

			else if (hexString2[counter2] == '8')
			{
				hexDigit2 = 8;
			}

			else if (hexString2[counter2] == '9')
			{
				hexDigit2 = 9;
			}

			else if (hexString2[counter2] == 'A')
			{
				hexDigit2 = 10;
			}

			else if (hexString2[counter2] == 'B')
			{
				hexDigit2 = 11;
			}

			else if (hexString2[counter2] == 'C')
			{
				hexDigit2 = 12;
			}

			else if (hexString2[counter2] == 'D')
			{
				hexDigit2 = 13;
			}

			else if (hexString2[counter2] == 'E')
			{
				hexDigit2 = 14;
			}

			else if (hexString2[counter2] == 'F')
			{
				hexDigit2 = 15;
			}

			else if (hexString2[counter2] == 'a')
			{
				hexDigit2 = 10;
			}

			else if (hexString2[counter2] == 'b')
			{
				hexDigit2 = 11;
			}

			else if (hexString2[counter2] == 'c')
			{
				hexDigit2 = 12;
			}

			else if (hexString2[counter2] == 'd')
			{
				hexDigit2 = 13;
			}

			else if (hexString2[counter2] == 'e')
			{
				hexDigit2 = 14;
			}

			else if (hexString2[counter2] == 'f')
			{
				hexDigit2 = 15;
			}

			else
			{
				cout << "ERROR: hexString1 < hexString2 Conversion to Digits Failing." << endl;
			}


			twoDigitSum = hexDigit1 + hexDigit2;


			// When hexSum < 9 without Carry Value
			if (twoDigitSum < 9)
			{
				hexSum[sumCounter] = twoDigitSum + carryValue + '0';
				sumCounter++;
				carryValue = 0;
			}

			// When hexSum < 10 with Carry Value
			else if (twoDigitSum >= 16 && twoDigitSum < 25)
			{
				hexSum[sumCounter] = twoDigitSum + carryValue - 16 + '0';
				carryValue = 1;
				sumCounter++;
			}

			// When hexSum > 8 or < 16
			else if (twoDigitSum < 16 && twoDigitSum > 8)
			{

				if (twoDigitSum == 9 && carryValue == 1)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 0;
				}

				else if (twoDigitSum == 9 && carryValue == 0)
				{
					hexSum[sumCounter] = '9';
					carryValue = 0;
				}

				else if (twoDigitSum == 10 && carryValue == 1)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 0;
				}

				else if (twoDigitSum == 10 && carryValue == 0)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 0;
				}

				else if (twoDigitSum == 11 && carryValue == 1)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 0;
				}

				else if (twoDigitSum == 11 && carryValue == 0)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 0;
				}

				else if (twoDigitSum == 12 && carryValue == 1)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 0;
				}

				else if (twoDigitSum == 12 && carryValue == 0)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 0;
				}

				else if (twoDigitSum == 13 && carryValue == 1)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 0;
				}

				else if (twoDigitSum == 13 && carryValue == 0)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 0;
				}

				else if (twoDigitSum == 14 && carryValue == 1)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 0;
				}

				else if (twoDigitSum == 14 && carryValue == 0)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 0;
				}

				else if (twoDigitSum == 15 && carryValue == 1)
				{
					hexSum[sumCounter] = '0';
					carryValue = 1;
				}

				else if (twoDigitSum == 15 && carryValue == 0)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 0;
				}

				sumCounter++;
			}

			// When hexSum > 24 or < 32
			else if (twoDigitSum < 32 && twoDigitSum > 24)
			{
				twoDigitSum = twoDigitSum - 16;

				if (twoDigitSum == 9 && carryValue == 1)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 1;
				}

				else if (twoDigitSum == 9 && carryValue == 0)
				{
					hexSum[sumCounter] = '9';
					carryValue = 1;
				}

				else if (twoDigitSum == 10 && carryValue == 1)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 1;
				}

				else if (twoDigitSum == 10 && carryValue == 0)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 1;
				}

				else if (twoDigitSum == 11 && carryValue == 1)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 1;
				}

				else if (twoDigitSum == 11 && carryValue == 0)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 1;
				}

				else if (twoDigitSum == 12 && carryValue == 1)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 1;
				}

				else if (twoDigitSum == 12 && carryValue == 0)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 1;
				}

				else if (twoDigitSum == 13 && carryValue == 1)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 1;
				}

				else if (twoDigitSum == 13 && carryValue == 0)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 1;
				}

				else if (twoDigitSum == 14 && carryValue == 1)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 1;
				}

				else if (twoDigitSum == 14 && carryValue == 0)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 1;
				}

				else if (twoDigitSum == 15 && carryValue == 1)
				{
					hexSum[sumCounter] = '0';
					carryValue = 2;
				}

				else if (twoDigitSum == 15 && carryValue == 0)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 1;
				}


				sumCounter++;
			}

			counter1--;
			counter2--;

		}

		//hexString2 Ends (If Shorter Than hexString1)
		else if (counter1 >= 0 && counter2 < 0)
		{
			// Setting hexDigit2 to Zero
			hexDigit2 = 0;

			// Converting hexString1 to hexDigit1
			if (hexString1[counter1] == '0')
			{
				hexDigit1 = 0;
			}

			else if (hexString1[counter1] == '1')
			{
				hexDigit1 = 1;
			}

			else if (hexString1[counter1] == '2')
			{
				hexDigit1 = 2;
			}

			else if (hexString1[counter1] == '3')
			{
				hexDigit1 = 3;
			}

			else if (hexString1[counter1] == '4')
			{
				hexDigit1 = 4;
			}

			else if (hexString1[counter1] == '5')
			{
				hexDigit1 = 5;
			}

			else if (hexString1[counter1] == '6')
			{
				hexDigit1 = 6;
			}

			else if (hexString1[counter1] == '7')
			{
				hexDigit1 = 7;
			}

			else if (hexString1[counter1] == '8')
			{
				hexDigit1 = 8;
			}

			else if (hexString1[counter1] == '9')
			{
				hexDigit1 = 9;
			}

			else if (hexString1[counter1] == 'A')
			{
				hexDigit1 = 10;
			}

			else if (hexString1[counter1] == 'B')
			{
				hexDigit1 = 11;
			}

			else if (hexString1[counter1] == 'C')
			{
				hexDigit1 = 12;
			}

			else if (hexString1[counter1] == 'D')
			{
				hexDigit1 = 13;
			}

			else if (hexString1[counter1] == 'E')
			{
				hexDigit1 = 14;
			}

			else if (hexString1[counter1] == 'F')
			{
				hexDigit1 = 15;
			}

			else if (hexString1[counter1] == 'a')
			{
				hexDigit1 = 10;
			}

			else if (hexString1[counter1] == 'b')
			{
				hexDigit1 = 11;
			}

			else if (hexString1[counter1] == 'c')
			{
				hexDigit1 = 12;
			}

			else if (hexString1[counter1] == 'd')
			{
				hexDigit1 = 13;
			}

			else if (hexString1[counter1] == 'e')
			{
				hexDigit1 = 14;
			}

			else if (hexString1[counter1] == 'f')
			{
				hexDigit1 = 15;
			}

			else
			{
				cout << "ERROR: hexString1 > hexString2 Conversion to Digits Failing." << endl;
			}


			twoDigitSum = hexDigit1 + hexDigit2;


			// When hexSum < 9 without Carry Value
			if (twoDigitSum < 9)
			{
				hexSum[sumCounter] = twoDigitSum + carryValue + '0';
				sumCounter++;
				carryValue = 0;
			}

			// When hexSum < 10 with Carry Value
			else if (twoDigitSum >= 16 && twoDigitSum < 25)
			{
				hexSum[sumCounter] = twoDigitSum + carryValue - 16 + '0';
				carryValue = 1;
				sumCounter++;
			}

			// When hexSum > 8 or < 16
			else if (twoDigitSum < 16 && twoDigitSum > 8)
			{

				if (twoDigitSum == 9 && carryValue == 1)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 0;
				}

				else if (twoDigitSum == 9 && carryValue == 0)
				{
					hexSum[sumCounter] = '9';
					carryValue = 0;
				}

				else if (twoDigitSum == 10 && carryValue == 1)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 0;
				}

				else if (twoDigitSum == 10 && carryValue == 0)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 0;
				}

				else if (twoDigitSum == 11 && carryValue == 1)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 0;
				}

				else if (twoDigitSum == 11 && carryValue == 0)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 0;
				}

				else if (twoDigitSum == 12 && carryValue == 1)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 0;
				}

				else if (twoDigitSum == 12 && carryValue == 0)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 0;
				}

				else if (twoDigitSum == 13 && carryValue == 1)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 0;
				}

				else if (twoDigitSum == 13 && carryValue == 0)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 0;
				}

				else if (twoDigitSum == 14 && carryValue == 1)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 0;
				}

				else if (twoDigitSum == 14 && carryValue == 0)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 0;
				}

				else if (twoDigitSum == 15 && carryValue == 1)
				{
					hexSum[sumCounter] = '0';
					carryValue = 1;
				}

				else if (twoDigitSum == 15 && carryValue == 0)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 0;
				}

				sumCounter++;
			}

			// When hexSum > 24 or < 32
			else if (twoDigitSum < 32 && twoDigitSum > 24)
			{
				twoDigitSum = twoDigitSum - 16;

				if (twoDigitSum == 9 && carryValue == 1)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 1;
				}

				else if (twoDigitSum == 9 && carryValue == 0)
				{
					hexSum[sumCounter] = '9';
					carryValue = 1;
				}

				else if (twoDigitSum == 10 && carryValue == 1)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 1;
				}

				else if (twoDigitSum == 10 && carryValue == 0)
				{
					hexSum[sumCounter] = 'A';
					carryValue = 1;
				}

				else if (twoDigitSum == 11 && carryValue == 1)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 1;
				}

				else if (twoDigitSum == 11 && carryValue == 0)
				{
					hexSum[sumCounter] = 'B';
					carryValue = 1;
				}

				else if (twoDigitSum == 12 && carryValue == 1)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 1;
				}

				else if (twoDigitSum == 12 && carryValue == 0)
				{
					hexSum[sumCounter] = 'C';
					carryValue = 1;
				}

				else if (twoDigitSum == 13 && carryValue == 1)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 1;
				}

				else if (twoDigitSum == 13 && carryValue == 0)
				{
					hexSum[sumCounter] = 'D';
					carryValue = 1;
				}

				else if (twoDigitSum == 14 && carryValue == 1)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 1;
				}

				else if (twoDigitSum == 14 && carryValue == 0)
				{
					hexSum[sumCounter] = 'E';
					carryValue = 1;
				}

				else if (twoDigitSum == 15 && carryValue == 1)
				{
					hexSum[sumCounter] = '0';
					carryValue = 2;
				}

				else if (twoDigitSum == 15 && carryValue == 0)
				{
					hexSum[sumCounter] = 'F';
					carryValue = 1;
				}

				
				sumCounter++;
			}

			else
			{
				cout << "ERROR: Counters > 0 twoDigitSum error." << endl;
			}

			counter1--;
			counter2--;

		}

	}


	for (int i = sumCounter; i >= 0; i--)
	{
		hexAddition += hexSum[i];
	}

	
	return hexAddition;
}

string problem11(string binaryString1, string binaryString2)
{
	// Define Variables
	char digitSubtraction[8];
	int carryValue = 0;
	string binarySubtraction = string();
	
	for (int i = 7; i >= 0; i--)
	{
		if (binaryString1[i] == '1' && carryValue == 0)
		{
			if (binaryString2[i] == '1')
			{
				digitSubtraction[i] = '0';
				carryValue = 0;
			}

			else if (binaryString2[i] == '0')
			{
				digitSubtraction[i] = '1';
				carryValue = 0;
			}

		}

		else if (binaryString1[i] == '0' && carryValue == 0)
		{
			if (binaryString2[i] == '0')
			{
				digitSubtraction[i] = '0';
				carryValue = 0;
			}

			else if (binaryString2[i] == '1')
			{
				digitSubtraction[i] = '1';
				carryValue = -1;
			}
		}

		else if (binaryString1[i] == '1' && carryValue == -1)
		{
			if (binaryString2[i] == '1')
			{
				digitSubtraction[i] = '1';
				carryValue = -1;
			}

			else if (binaryString2[i] == '0')
			{
				digitSubtraction[i] = '0';
				carryValue = 0;
			}

		}

		else if (binaryString1[i] == '0' && carryValue == -1)
		{
			if (binaryString2[i] == '0')
			{
				digitSubtraction[i] = '1';
				carryValue = -1;
			}

			else if (binaryString2[i] == '1')
			{
				digitSubtraction[i] = '0';
				carryValue = -1;
			}
		}

		
	}


	for (int i = 0; i < 8; i++)
	{
		binarySubtraction += digitSubtraction[i];
	}


	return binarySubtraction;
}