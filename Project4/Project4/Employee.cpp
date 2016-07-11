//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Employee.cpp
// Description: Employee class was provided in the CSE220-Project4-Recursion.pdf
//              Subclass of Personnel - Inherits from Personnel Class
//              Additional Information: department, salary, rank.
//******************************************************************************

#include "Employee.h"

Employee::Employee(char* name, char* birthday, char* address, char* phone, char *email, char* department, float salary, char* rank) : Personnel(name, birthday, address, phone, email)
{
	this->department = department;
	this->salary = salary;
	this->rank = rank;
}

Employee::~Employee()
{
	delete this->department;
	delete this->rank;
}

char* Employee::getDepartment()
{
	return department;
}

void Employee::setDepartment(char* department)
{
	this->department = department;
}

float Employee::getSalary()
{
	return salary;
}

void Employee::setSalary(float salary)
{
	this->salary = salary;
}

char* Employee::getRank()
{
	return rank;
}

void Employee::setRank(char* rank)
{
	this->rank = rank;
}

void Employee::display()
{
	Personnel::display();
	cout << "\tDepartment:\t" << department << endl;
	cout << "\tSalary:\t" << salary << endl;
	cout << "\tRank:\t" << rank << endl;
}