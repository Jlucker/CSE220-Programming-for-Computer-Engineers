//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Faculty.h
//******************************************************************************

#ifndef FACULTY_H
#define	FACULTY_H

#include <iostream>
#include "Employee.h"

using namespace std;

class Faculty : public Employee
{
public:
	Faculty(char* name, char* birthday, char* address, char* phone, char* email, char* department, float salary, char* rank, char* research);
	virtual ~Faculty();
	virtual void setResearch(char* research);
	virtual char* getResearch();
	virtual void display();
private:
	char* research;
};

typedef Faculty* FacultyPointer;

#endif	/* FACULTY_H */

