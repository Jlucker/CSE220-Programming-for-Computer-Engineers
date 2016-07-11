//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Employee.h
//******************************************************************************
#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <iostream>
#include "Personnel.h"

using namespace std;

class Employee : public Personnel
{
public:
	Employee(char* name, char* birthday, char* address, char* phone, char *email, char* department, float salary, char* rank);
	~Employee();
	virtual char* getDepartment();
	virtual void setDepartment(char* department);
	virtual float getSalary();
	virtual void setSalary(float salary);
	virtual char* getRank();
	virtual void setRank(char* rank);
	virtual void display();
private:
	char* department;
	float salary;
	char* rank;
};

typedef Employee* EmployeePointer;

#endif	/* EMPLOYEE_H */