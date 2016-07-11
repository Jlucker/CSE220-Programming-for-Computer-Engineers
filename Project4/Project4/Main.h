//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Main.h
//******************************************************************************

#ifndef MAIN_H
#define	MAIN_H

#include "Student.h"


void showMainMenu();
bool processMainMenu();
void showAddMenu();
bool processAddMenu();
void showBookRentalMenu();
bool processBookRentalMenu();
void showPersonnel();
void removePersonnel();

void addAGenericPersonnel();
void addEmployee();
void addFaculty();
void addStudent();

void addBookRental();
void clearBookRentals();
void findABook();
void showBookRentals();
StudentPointer findStudent(char* name);

#endif	/* MAIN_H */

