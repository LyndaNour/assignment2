/** Implementation of the nonProfessional_Employees class */

#include "nonprofessional.h"
#include<iostream>
#include<sstream>

using std::ostringstream;
using std::string;
using std::cin;
using std::cout;

/** Calculate the weekly salary
@return return the weekly salary
*/
float nonProfessional_Employees::CalculWeeklySalary()  const
{
	return (hrWorked * hourlyRate); // weekly salary
}

// calcul pto hours 

float nonProfessional_Employees::CalculVacation() const
{
	float ptoRate= 0.05 ;// for each 40 hours work, the employee receives 2 hours PTO 

	return( ptoRate * hrWorked);  // PTO recieved per week 

}

float nonProfessional_Employees::CalculHealthCotribution() const
{
	int healthContribution= 20; // $ per weekly pay check 

	return (healthContribution);

}



// Read user  input 
void nonProfessional_Employees::read_employees_data()
{
	cout << "Enter the employee name: ";
	cin >> employeeName;
	cout << "Enter the employee ID: ";
	cin >> employeeID;
	cout << "ENter the total hours worked within a week: ";
	cin >> hrWorked;
	cout << "Enter the hourly rate: ";
	cin >> hourlyRate;
	cout << "\n";
}

string nonProfessional_Employees::to_string() const
{
	ostringstream result;
	result << " nonProfessiona employee hourly rate is: " << hourlyRate << ", total hours worked is: " << hrWorked;
	return result.str();

}

