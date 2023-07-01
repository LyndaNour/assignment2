#ifndef _NONPROFESSIONAL_H_
#define _NONPROFESSIONAL_H_
#include "employees.h"

/** Derived class nonProfessional_Employees from the base class Employees */
class nonProfessional_Employees : public virtual Employees {

protected:
	//Data fielfs
	float hrWorked;
	float hourlyRate;


public:
	//Functions
	/** Construct an Employee object
	@param name The employeeName
	@param ID The employeeID
	@param HW The total hour worked a week 
	^param HR The hourly rate 
	*/

	nonProfessional_Employees():hrWorked(0), hourlyRate(0), Employees("A", "A") {}
	nonProfessional_Employees( float HW, float HR, const std::string& name, const std::string ID) : hrWorked(HW), hourlyRate(HR), Employees(name, ID) {}

	//Getters 
	//@return hrWorked 
	float get_hours_worked()
	{
		return hrWorked;
	}

	// return hourly rate 
	float get_hourlyRate()
	{
		return hourlyRate;
	}

	virtual float CalculHealthCotribution() const;
	virtual float CalculWeeklySalary() const;
	virtual float CalculVacation() const ;
	void read_employees_data();
	std::string to_string() const;
};



#endif

