/** Program to compute the weekly salary, the paid vacation and health contribution for professional employees and nonprofessional employees */

#include "nonprofessional.h"
#include "professional.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// create get_employeeType object and returns a pointer 
Employees* get_employeeType()
{
	unsigned int fig_type;
	cout << "Enter 1 for professional employee \nEnter 2 for non_professional employee: ";
	cin >> fig_type;

	if (fig_type == 1)
	{
		return new Professional_Employees();
	}
	else if (fig_type == 2)
	{
		return new nonProfessional_Employees();
	}
	else
	{
		return NULL;
	}

}

void display_result(float salary, float vacation, float hContribution)
{
	cout << "The salary is: $" << salary <<" per week "
		<< "\nThe paid vacation is " << vacation <<" hours per week"
		<< "\nThe health contribution is $" << hContribution <<" per weekly paycheck"
		<< endl;
}

int main()
{
	Employees* my_employee;
	float salary;
	float vacation;
	float healthContribution;

	my_employee = get_employeeType();
	my_employee->read_employees_data();
	salary = my_employee->CalculWeeklySalary();
	vacation = my_employee->CalculVacation();
	healthContribution = my_employee->CalculHealthCotribution();
	display_result(salary, vacation, healthContribution);
	delete my_employee;
	return 0;



}