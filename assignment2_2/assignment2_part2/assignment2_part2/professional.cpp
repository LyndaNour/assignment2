/** Implementation of the Professional_Employees class */

#include "professional.h"
#include<iostream>
#include<sstream>

using std::ostringstream;
using std::string;
using std::cin;
using std::cout;

// calcul weekly salary 
/** 
@return return the weekly salary */
float Professional_Employees::CalculWeeklySalary()  const
{
	int const TOTAL_WEEKS_AYEAR = 52;
	return ( annualSalary / TOTAL_WEEKS_AYEAR); // weekly salary
}

// calcul paid vacation
/**@return vacation received per week */
float Professional_Employees::CalculVacation() const
{
	// vacation annual rate 
	float annualRate = 0.125; // each 240 days worked a year, the employee receives 30 days vacation 

	return ( hrWorked* annualRate); 

}

// compute the health contribution 
float Professional_Employees::CalculHealthCotribution() const
{
	int healthContribution = 10; //$ per weekly paycheck
	return healthContribution;
}


// Read user  input 
void Professional_Employees::read_employees_data()
{
	cout << "Enter the employee name: ";
	cin >> employeeName;
	cout << "Enter the employee ID: ";
	cin >> employeeID;
	cout << "Enter the annual salary: ";
	cin >> annualSalary;
	cout << "ENter the total hours worked within a week: ";
	cin >> hrWorked;

}

string Professional_Employees::to_string() const
{
	ostringstream result;
	result << " Professiona employee annual salary is " << annualSalary <<"$";
	return result.str();

}

