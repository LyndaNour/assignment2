#ifndef _EMPLOYEES_H_
#define _EMPLOYEES_H_
#include<string>

/**Class to represent employees */
class Employees {

protected:
	//Data fields 
	std::string employeeName;
	std:: string employeeID;

public:
	//Functions
	/** Construct an Employee object
	@param name The employeeName
	@param ID The employeeID
	*/

	Employees(const std::string& name, const std::string ID) :employeeName(name), employeeID(ID) {}


	virtual float CalculWeeklySalary() const=0; // calculate weekly salary
	virtual float CalculVacation() const=0; // calculate paid vacation
	virtual float CalculHealthCotribution() const=0; // calculate health contribution
	virtual void read_employees_data() = 0; // read user input 
	virtual std::string to_string() const = 0; // store the data 

};






#endif
