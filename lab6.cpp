/*
	Programming I
	Lab 6
	October 24th, 2014
	Daniel Perez

	This program will input, for each ABC employee who has worked at BANKS that week, 
	the ABC employee number and for each of the five workdays, the number of hours worked.
	At the end, it will display a summary report.  The summary report will show the total number of
	ABC employees who have worked for BANKS that week and for each ABC employee who has worked
	that week, the employee number and the total number of hours worked. 
*/

#include <iostream>
using namespace std;

void main()
{
	const int MAX_EMPLOYEES = 10;
	
	int	      employeeID_Numbers[MAX_EMPLOYEES] = { 1283, 1535, 2217, 2831, 3523, 4218, 4385, 6428, 7286, 7523 };
	int       hoursWorked [MAX_EMPLOYEES] = { 0 };
	int       count;
	char      askHours;
	int       employeeID;
	int       day;
	int       hours;
	int       totalEmployeesPerWeek = 0;


	cout << "ABC EMPLOYEES WORKSHEET" << endl;
	cout << endl << endl;

	while (true)
	{
		do
		{
			cout << "Employee hours to enter(Y/N): ";
			cin  >> askHours;
			askHours = toupper(askHours);
		} 
		while (askHours != 'Y' && askHours != 'N');

		if (askHours == 'N')
			break;

		cout << endl;

		do
		{
			cout << "Employee number: ";
			cin  >> employeeID;
			
			for (count = 0; count < MAX_EMPLOYEES; count++)
			{
				if (employeeID == employeeID_Numbers[count])
					break;
			}

		} while (count == MAX_EMPLOYEES);

		for (day = 0; day < 5; day++)
		{
			do
			{
				cout << "Hours worked day " << day + 1 << " (0-16): ";
				cin  >> hours;
			}
			while (hours < 0 || hours > 16);
		
			hoursWorked[count] += hours;
		}
		
		cout << endl;

		totalEmployeesPerWeek++;
	}

	system("cls");

	cout << "ABC EMPLOYEES WEEKLY SUMMARY REPORT" << endl;
	cout << endl;
	cout << "Total # of employees who have worked for BANKS this week: " << totalEmployeesPerWeek << endl;
	cout << endl;

	if (totalEmployeesPerWeek > 0)
	{
		for (count = 0; count < MAX_EMPLOYEES; count++)
		{
			if (hoursWorked[count] > 0)
			{
				cout << "Employee number " << employeeID_Numbers[count] << " has worked " << hoursWorked[count] << " hour(s)" << endl;
			}
		}
		
		cout << endl;

	}
}