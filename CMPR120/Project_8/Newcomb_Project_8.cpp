/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_8.cpp
   Date: October 30, 2022
   School: Santa Ana College (SAC)
   Description: Paper, Rock, Scissors Game */

#include <iostream>
#include <iomanip>
using namespace std;

// declare functions
void headerOutput();
int randomNumber();
string computerChoice();
string userChoice();
void displayWinner(string computerItem, string userItem);

int main()
{
	// Define & Initialize Variables
	string computerItem = string();
	string userItem = string();

	// call to headerOutput function for header and program description
	headerOutput();

	// Call computerChoice function to get randomized selection
	computerItem = computerChoice();

	// call userChoice function to request user input
	userItem = userChoice();

	// determine and output winner via the displayWinner function
	displayWinner(computerItem, userItem);

	return 0;
}

void headerOutput()
{
	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_8.cpp" << endl;
	cout << "Date: October 30, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Program Description
	cout << endl;
	cout << endl;
	cout << "This program lets you play paper, rock, scissors against the computer." << endl;
	cout << "======================================================================" << endl;
	cout << endl;
}

string computerChoice()
{
	string computerItem = string();

	// call to randomNumber function
	int computerNumber = randomNumber();

	if (computerNumber == 1)
	{
		computerItem = "rock";
		return computerItem;
	}
	else if (computerNumber == 2)
	{
		computerItem = "paper";
		return computerItem;
	}
	else if (computerNumber == 3)
	{
		computerItem = "scissors";
		return computerItem;
	}
	else
	{
		cout << "Error: Number should be 1-3, but it's: " << computerNumber << endl;
		return "error";
	}
}

int randomNumber()
{
	// use system time as seed
	unsigned seed = time(0);

	// seed and use random number generator function
	srand(seed);
	int computerNumber = rand() % 3 + 1;

	return computerNumber;
}

string userChoice()
{
	string userItem = string();

	// request user input
	cout << "Enter paper, rock, or scissors to play against the computer:" << endl;
	cin >> userItem;

	while (!(userItem == "paper" || userItem == "rock" || userItem == "scissors"))
	{
		cout << "Please enter one word only, either paper, rock, or scissors:" << endl;
		cin >> userItem;
	}

	return userItem;
}

void displayWinner(string computerItem, string userItem)
{
	// output Computer's choice
	cout << "The computer's selection was: " << computerItem << endl;
	cout << endl;

	// determine winner
	if (!(computerItem == "rock" || computerItem == "paper" || computerItem == "scissors"))
	{
		cout << "Error: Computer's selection invalid. Please try again." << endl;
	}
	else if (!(userItem == "rock" || userItem == "paper" || userItem == "scissors"))
	{
		cout << "Error: Your selection is invalid. Please try again." << endl;
	}
	else if (computerItem == "rock" && userItem == "rock" || computerItem == "paper" 
		&& userItem == "paper" || computerItem == "scissors" && userItem == "scissors")
	{
		cout << "The game resulted in a tie. Please play again." << endl;
	}
	else if (computerItem == "rock" && userItem == "scissors")
	{
		cout << "Rock smashes scissors. The computer wins." << endl;
	}
	else if (computerItem == "scissors" && userItem == "rock")
	{
		cout << "Rock smashes scissors. You win!" << endl;
	}
	else if (computerItem == "paper" && userItem == "rock")
	{
		cout << "Paper wraps rock. The computer wins." << endl;
	}
	else if (computerItem == "rock" && userItem == "paper")
	{
		cout << "Paper wraps rock. You win!" << endl;
	}
	else if (computerItem == "scissors" && userItem == "paper")
	{
		cout << "Scissors cut paper. The computer wins." << endl;
	}
	else if (computerItem == "paper" && userItem == "scissors")
	{
		cout << "Scissors cut paper. You win!" << endl;
	}
	else
	{
		cout << "Error: Unable to determine winner. Please try again." << endl;
	}

	return;
}