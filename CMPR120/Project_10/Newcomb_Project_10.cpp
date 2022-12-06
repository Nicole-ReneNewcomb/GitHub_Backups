/* Author: Nicole-Rene Newcomb
   Program: Newcomb_Project_10.cpp
   Date: November 20, 2022
   School: Santa Ana College (SAC)
   Description: student final grade
   calculator calculates average of
   student test scores from input. */

#include <iostream>
#include <iomanip>
using namespace std;

// declare functions
void headerOutput();
void gradeCalc(int students, int tests, string names[],
	char grades[], double scores1[], double scores2[],
	double scores3[], double scores4[], double scores5[]);
void printResults(string names[], double studentAverage[], char grades[], int students);

int main()
{
	// Define & Initialize Variables
	int students = 5;
	int tests = 4;
	string studentNames[5] = { "" };
	char studentLetterGrades[5] = { "" };
	double student1Scores[4] = { 0.0 };        // I considered trying a 2D array for
	double student2Scores[4] = { 0.0 };        // student grades but decided against
	double student3Scores[4] = { 0.0 };        // it since the instructions request
	double student4Scores[4] = { 0.0 };        // five arrays of four doubles.
	double student5Scores[4] = { 0.0 };

	// call to headerOutput function for header and program description
	headerOutput();

	// requests student score input & prints grade ouput
	gradeCalc(students, tests, studentNames, studentLetterGrades,
		student1Scores, student2Scores, student3Scores, student4Scores,
		student5Scores);

	return 0;
}

void headerOutput()
{
	// Program Header
	cout << endl;
	cout << "Author: Nicole-Rene Newcomb" << endl;
	cout << "Program: Newcomb_Project_10.cpp" << endl;
	cout << "Date: November 20, 2022" << endl;
	cout << "School: Santa Ana College (SAC)" << endl;
	cout << "===================================" << endl;

	// Program Description
	cout << endl;
	cout << endl;
	cout << "This program calculates students' grades based on test grade input." << endl;
	cout << "===================================================================" << endl;
	cout << endl;
}

void gradeCalc(int students, int tests, string names[], char grades[], 
	double scores1[], double scores2[], double scores3[], double scores4[], 
	double scores5[])
{
	// declare variables
	double studentTotal[5] = { 0.0 };
	double studentAverage[5] = { 0.0 };

	// request input & store student name entries
	for (int i = 0; i < students; i++)
	{
		cout << "Please enter student " << i + 1 << "'s name: " << endl;
		cout << endl;
		cin >> names[i];
	}

	// request & store test scores for student 1
	for (int j = 0; j < tests; j++)
	{
		cout << "Please enter " << names[0] << "'s score for test " << j + 1 << ": " << endl;
		cout << endl;
		cin >> scores1[j];

		// input validation to prevent score entries > 100 or < 0
		while (scores1[j] < 0 || scores1[j] > 100)
		{
			cout << "Please enter a score for test " << j + 1 << " that is between 0 and 100: " << endl;
			cout << endl;
			cin >> scores1[j];
		}
	}

	// request & store test scores for student 2
	for (int j = 0; j < tests; j++)
	{
		cout << "Please enter " << names[1] << "'s score for test " << j + 1 << ": " << endl;
		cout << endl;
		cin >> scores2[j];

		// input validation to prevent score entries > 100 or < 0
		while (scores2[j] < 0 || scores2[j] > 100)
		{
			cout << "Please enter a score for test " << j + 1 << " that is between 0 and 100: " << endl;
			cout << endl;
			cin >> scores2[j];
		}
	}

	// request & store test scores for student 3
	for (int j = 0; j < tests; j++)
	{
		cout << "Please enter " << names[2] << "'s score for test " << j + 1 << ": " << endl;
		cout << endl;
		cin >> scores3[j];

		// input validation to prevent score entries > 100 or < 0
		while (scores3[j] < 0 || scores3[j] > 100)
		{
			cout << "Please enter a score for test " << j + 1 << " that is between 0 and 100: " << endl;
			cout << endl;
			cin >> scores3[j];
		}
	}

	// request & store test scores for student 4
	for (int j = 0; j < tests; j++)
	{
		cout << "Please enter " << names[3] << "'s score for test " << j + 1 << ": " << endl;
		cout << endl;
		cin >> scores4[j];

		// input validation to prevent score entries > 100 or < 0
		while (scores4[j] < 0 || scores4[j] > 100)
		{
			cout << "Please enter a score for test " << j + 1 << " that is between 0 and 100: " << endl;
			cout << endl;
			cin >> scores4[j];
		}
	}

	// request & store test scores for student 5
	for (int j = 0; j < tests; j++)
	{
		cout << "Please enter " << names[4] << "'s score for test " << j + 1 << ": " << endl;
		cout << endl;
		cin >> scores5[j];

		// input validation to prevent score entries > 100 or < 0
		while (scores5[j] < 0 || scores5[j] > 100)
		{
			cout << "Please enter a score for test " << j + 1 << " that is between 0 and 100: " << endl;
			cout << endl;
			cin >> scores5[j];
		}
	}

	// calculations - sum student grades
	for (int j = 0; j < tests; j++)
	{
		studentTotal[0] += scores1[j];
	}

	for (int j = 0; j < tests; j++)
	{
		studentTotal[1] += scores2[j];
	}

	for (int j = 0; j < tests; j++)
	{
		studentTotal[2] += scores3[j];
	}
	
	for (int j = 0; j < tests; j++)
	{
		studentTotal[3] += scores4[j];
	}

	for (int j = 0; j < tests; j++)
	{
		studentTotal[4] += scores5[j];
	}
	
	// calculations - average student grades
	for (int i = 0; i < students; i++)
	{
		studentAverage[i] = studentTotal[i] / tests;
	}

	// assign letter grade
	for (int i = 0; i < students; i++)
	{
		if (studentAverage[i] >= 90)
		{
			grades[i] = 'A';
		}

		else if (studentAverage[i] >= 80 && studentAverage[i] < 90)
		{
			grades[i] = 'B';
		}

		else if (studentAverage[i] >= 70 && studentAverage[i] < 80)
		{
			grades[i] = 'C';
		}

		else if (studentAverage[i] >= 60 && studentAverage[i] < 70)
		{
			grades[i] = 'D';
		}

		else if (studentAverage[i] >= 0 && studentAverage[i] < 60)
		{
			grades[i] = 'F';
		}

		else
		{
			cout << "Error: Invalid Letter Grade" << endl;
		}
	}

	printResults(names, studentAverage, grades, students);
	
	return;
}

void printResults(string names[], double studentAverage[], char grades[], int students)
{
	// grade output header
	cout << endl;
	cout << endl;
	cout << setw(25) << left << "Student Name" << setw(20) << "Average Score" << setw(20) <<
		"Letter Grade" << left << endl;
	cout << "==========================================================" << endl;
	
	// loop to output student grades
	for (int i = 0; i < students; i++)
	{
		cout << setw(25) << left << names[i] << setw(8) << right << fixed << 
			setprecision(1) << studentAverage[i] << setw(19) << right << 
			grades[i] << endl;
		cout << "----------------------------------------------------------" << endl;
	}

	return;
}