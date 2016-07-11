//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Faculty.cpp
// Description: Faculty class was provided in the CSE220-Project4-Recursion.pdf
//              Subclass of Personnel
//              --Inherits from Personnel Class
//              --Inherits from Employee Class
//              Additional Information: research
//******************************************************************************

#include "Faculty.h"

Faculty::Faculty(char* name, char* birthday, char* address, char* phone, char* email, char* department, float salary, char* rank, char* research) : Employee(name, birthday, address, phone, email, department, salary, rank)
{
	this->research = research;
}

Faculty::~Faculty()
{
	delete this->research;
}

void Faculty::setResearch(char* research)
{
	this->research = research;
}

char* Faculty::getResearch()
{
	return research;
}

void Faculty::display()
{
	Employee::display();
	cout << "\tResearch:\t" << research << endl;
}
