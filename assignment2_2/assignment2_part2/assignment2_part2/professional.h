#ifndef _PROFESSIONAL_H_
#define _PROFESSIONAL_H_
#include "employees.h"

/** Professional_Employees is a derived class from base class Employees */

class Professional_Employees : public virtual Employees {

protected:
	//Data field 
	float hrWorked;
	float annualSalary;

public:
	//Functions
	/** Construct an Employee object
	@param name The employeeName
	@param ID The employeeID
	@param salary The weeklylySalary
	^param vacation The vacationDay
	@param health The healthContribution
	*/

	Professional_Employees() : hrWorked(0), annualSalary(0), Employees("A", "A") {}
	Professional_Employees(float HW, float AS, const std::string& name, const std::string ID) : hrWorked(HW), annualSalary(AS), Employees(name, ID) {}

	//Getters 
	float get_annual_salary()
	{
		return annualSalary;
	}


	float get_hours_worked()
	{
		return hrWorked;
	}

	virtual float CalculHealthCotribution() const;
	virtual float CalculWeeklySalary() const;
	virtual float CalculVacation() const;
	void read_employees_data();
	std::string to_string() const;
};

#endif 
