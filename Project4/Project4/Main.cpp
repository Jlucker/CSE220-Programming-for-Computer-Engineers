//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Main.cpp
// Description: This program essentially creates a database of personnel and
//              stores the information in a linked list.  The user can create
//              entries for generic personnel, employees, faculty, and students.
//              The user can also enter information that is unique to each of 
//              entries using sub-menus.
//******************************************************************************

#include <cstdlib>
#include <vector>
#include <stdbool.h>
#include <cstring>
#include <iostream>

#include "Main.h"
#include "Employee.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

vector<PersonnelPointer>* allPersonnel;
vector<StudentPointer>* allStudents;

/** int main()
  * Instantiates new vector (allPersonnel)
  * Instantiates new vector (allStudents)
  * Initiates menu functionality   
  * @return EXIT_SUCCESS
  */
int main()
{
	allPersonnel = new vector<PersonnelPointer>();
	allStudents = new vector<StudentPointer>();
	bool shouldContinue;
	do
	{
		showMainMenu();
		shouldContinue = processMainMenu();
	}
	while (shouldContinue);
	cout << endl << "Goodbye." << endl;
	cin.get();
	return EXIT_SUCCESS;
}

/* Displays the options for the top level menu */
void showMainMenu()
{
	cout << "Main Menu:" << endl;
	cout << "\ta: Add a new personnel." << endl;
	cout << "\tm: Manage book rentals." << endl;
	cout << "\ts: Show all personnel." << endl;
	cout << "\tr: Remove personnel." << endl;
	cout << "\tq: Quit." << endl;
	cout << "Please enter your choice. : ";
}

/**
  * Provides functionality for the main menu
  * switch (selectedOption) selects functions based on user input
  * @return shouldContinue
  */
bool processMainMenu()
{
	bool shouldContinue = true;
	bool stillInSubMenu;
	char selectedOption;
	cin >> selectedOption;
	selectedOption = tolower(selectedOption);
	switch (selectedOption)
	{
		case 'a':
			do
			{
				showAddMenu();
				stillInSubMenu = processAddMenu();
			}
			while (stillInSubMenu);
			break;
		case 'm':
			do
			{
				showBookRentalMenu();
				stillInSubMenu = processBookRentalMenu();
			}
			while (stillInSubMenu);
			break;
		case 's':
			showPersonnel();
			break;
		case 'r':
			removePersonnel();
			break;
		case 'q':
			shouldContinue = false;
			break;
		default:
			cout << endl << "Invalid menu selection." << endl;
			showMainMenu();
	}
	return shouldContinue;
}
/* Displays the options for the insert menu */
void showAddMenu()
{
	cout << "Add Personnel" << endl;
	cout << "\tp: Add generic personnel." << endl;
	cout << "\te: Add an employee." << endl;
	cout << "\tf: Add a faculty member." << endl;
	cout << "\ts: Add a student." << endl;
	cout << "\tb: Back to the Main Menu." << endl;
	cout << "Please enter your choice. : ";
}

/**
  * Provides functionality for the insert menu
  * switch (selectedOption) selects functions based on user input
  * @return stillInSubMenu 
  */
bool processAddMenu()
{
	bool stillInSubMenu = true;
	char selectedOption;
	cin >> selectedOption;
	selectedOption = tolower(selectedOption);
	switch (selectedOption)
	{
		case 'p':
			addAGenericPersonnel();
			break;
		case 'e':
			addEmployee();
			break;
		case 'f':
			addFaculty();
			break;
		case 's':
			addStudent();
			break;
		case 'b':
			stillInSubMenu = false;
			break;
		default:
			cout << endl << "Invalid menu selection." << endl;
			showAddMenu();
	}
	return stillInSubMenu;
}
/* Displays the options for the book sub-menu */
void showBookRentalMenu()
{
	cout << "Manage Book Rentals:" << endl;
	cout << "\ta: Add a book rental for a student." << endl;
	cout << "\tc: Clear all book rentals for a student." << endl;
	cout << "\tf: Find a book." << endl;
	cout << "\ts: Display all books rented by a student." << endl;
	cout << "\tb: Back to the Main Menu." << endl;
	cout << "Please enter your choice. : ";
}

/**
  * Provides functionality for the book sub-menu
  * switch (selectedOption) selects functions based on user input
  * @return stillInSubMenu 
  */
bool processBookRentalMenu()
{
	bool stillInSubMenu = true;
	char selectedOption;
	cin >> selectedOption;
	selectedOption = tolower(selectedOption);
	switch (selectedOption)
	{
		case 'a':
			addBookRental();
			break;
		case 'c':
			clearBookRentals();
			break;
		case 'f':
			findABook();
			break;
		case 's':
			showBookRentals();
			break;
		case 'b':
			stillInSubMenu = false;
			break;
		default:
			cout << endl << "Invalid menu selection." << endl;
			showAddMenu();
	}
	return stillInSubMenu;
}
/* Displays all of the personnel */
void showPersonnel()
{
	if (allPersonnel->size() > 0)
	{
		for (unsigned int index = 0; index < allPersonnel->size(); index++)
			allPersonnel->at(index)->display();
	}
	else
	{
		cout << "No personnel have been added yet." << endl;
	}
}

/* Removes a specified personnel */
void removePersonnel()
{
	bool foundPersonnel = false;
	int personnelId;
	showPersonnel();
	cout << "Please enter the id of the personnel you would like to remove: ";
	cin >> personnelId;
	for (unsigned int index = 0; index < allPersonnel->size(); index++)
	{
		if (allPersonnel->at(index)->getId() == personnelId)
		{
			allPersonnel->erase(allPersonnel->begin() + index);
			foundPersonnel = true;
			break;
		}
	}
	for (unsigned int index = 0; index < allStudents->size(); index++)
	{
		if (allStudents->at(index)->getId() == personnelId)
		{
			allStudents->erase(allStudents->begin() + index);
			break;
		}
	}
	if (!foundPersonnel)
		cout << "Person with ID " << personnelId << " does not exist." << endl;
}

/* Inserts a generic personnel into the linked list */
void addAGenericPersonnel()
{
	char* name = new char[50];
	char* birthday = new char[11];
	char* address = new char[75];
	char* phone = new char[25];
	char* email = new char[75];
	cin.ignore();
	cout << "Please enter a name: ";
	cin.getline(name, 50);
	cout << "Please enter a birthday: ";
	cin.getline(birthday, 11);
	cout << "Please enter an address: ";
	cin.getline(address, 75);
	cout << "Please enter a phone number: ";
	cin.getline(phone, 25);
	cout << "Please enter an email address: ";
	cin.getline(email, 75);
	PersonnelPointer personnel = new Personnel(name, birthday, address, phone, email);
	allPersonnel->push_back(personnel);
}

/* Inserts an employee into the linked list */
void addEmployee()
{
	char* name = new char[50];
	char* birthday = new char[11];
	char* address = new char[75];
	char* phone = new char[25];
	char* email = new char[75];
	char* department = new char[75];
	float salary;
	char* rank = new char[75];
	cin.ignore();
	cout << "Please enter a name: ";
	cin.getline(name, 50);
	cout << "Please enter a birthday: ";
	cin.getline(birthday, 11);
	cout << "Please enter an address: ";
	cin.getline(address, 75);
	cout << "Please enter a phone number: ";
	cin.getline(phone, 25);
	cout << "Please enter an email address: ";
	cin.getline(email, 75);
	cout << "Please enter a department: ";
	cin.getline(department, 75);
	cout << "Please enter a salary: ";
	cin >> salary;
	cout << "Please enter a rank: ";
	cin.getline(rank, 75);
	EmployeePointer employee = new Employee(name, birthday, address, phone, email, department, salary, rank);
	allPersonnel->push_back(employee);
}

/* Inserts a faculty member into the linked list */
void addFaculty()
{
	char* name = new char[50];
	char* birthday = new char[11];
	char* address = new char[75];
	char* phone = new char[25];
	char* email = new char[75];
	char* department = new char[75];
	float salary;
	char* rank = new char[75];
	char* research = new char[75];
	cin.ignore();
	cout << "Please enter a name: ";
	cin.getline(name, 50);
	cout << "Please enter a birthday: ";
	cin.getline(birthday, 11);
	cout << "Please enter an address: ";
	cin.getline(address, 75);
	cout << "Please enter a phone number: ";
	cin.getline(phone, 25);
	cout << "Please enter an email address: ";
	cin.getline(email, 75);
	cout << "Please enter a department: ";
	cin.getline(department, 75);
	cout << "Please enter a salary: ";
	cin >> salary;
	cout << "Please enter a rank: ";
	cin.getline(rank, 75);
	cout << "Please enter research: ";
	cin.getline(research, 75);
	FacultyPointer faculty = new Faculty(name, birthday, address, phone, email, department, salary, rank, research);
	allPersonnel->push_back(faculty);
}

/* Inserts a student into the linked list */
void addStudent()
{
	char* name = new char[50];
	char* birthday = new char[11];
	char* address = new char[75];
	char* phone = new char[25];
	char* email = new char[75];
	BookPointer rentedBooks = NULL;
	int levelAsInt;
	StudentLevel level;
	void displayBooks(BookPointer book);
	cin.ignore();
	cout << "Please enter a name: ";
	cin.getline(name, 50);
	cout << "Please enter a birthday: ";
	cin.getline(birthday, 11);
	cout << "Please enter an address: ";
	cin.getline(address, 75);
	cout << "Please enter a phone number: ";
	cin.getline(phone, 25);
	cout << "Please enter an email address: ";
	cin.getline(email, 75);
	cout << "\tFreshman  = 1" << endl;
	cout << "\tSophomore = 2" << endl;
	cout << "\tJunior    = 3" << endl;
	cout << "\tSenior    = 4" << endl;
	cout << endl << "Please enter the number corresponding to the student's level.: " << endl;
	cin >> levelAsInt;
	switch (levelAsInt)
	{
		case 1:
			level = FRESHMAN;
			break;
		case 2:
			level = SOPHOMORE;
			break;
		case 3:
			level = JUNIOR;
			break;
		case 4:
			level = SENIOR;
			break;
		default:
			cout << "Invalid student level." << endl;
			cout << "Student not added." << endl;
			return;
	}
	StudentPointer student = new Student(name, birthday, address, phone, email, level);
	allPersonnel->push_back(student);
	allStudents->push_back(student);
}

/* Inserts a book into the book tree for a specified student */
void addBookRental()
{
	char* studentsName = new char[50];
	char* booksTitle = new char[100];
	char* booksUrl = new char[100];
	cout << "Please enter the name of the student that rented the book.: ";
        cin.ignore();
	cin.getline(studentsName, 50);
	cout << "Please enter the name of the book.: ";
	cin.getline(booksTitle, 100);
	cout << "Please enter the URL of the book.: ";
	cin.getline(booksUrl, 100);
	BookPointer book = (BookPointer) calloc(1, sizeof (struct Book_));
	book->title = booksTitle;
	book->url = booksUrl;
	StudentPointer student = findStudent(studentsName);
	if (student == NULL)
	{
		cout << "Student Not Found" << endl;
		return;
	}
	else
	{
		student->addBookRental(book);
	}
	cout << "Book Rental Added" << endl;
}
/* Deletes all of the book entries for a specified student */
void clearBookRentals()
{
	char* studentsName = new char[50];
	cout << "Please enter the name of the student.: ";
        cin.ignore();
	cin.getline(studentsName, 50);
	StudentPointer student = findStudent(studentsName);
	if (student == NULL)
	{
		cout << "Student Not Found" << endl;
		return;
	}
	else
	{
		student->clearBookRentals();
		cout << "Book Rentals cleared for " << studentsName << endl;
	}
}

/* Searches for a specific book entry for a specified student */
void findABook()
{
	char* studentsName = new char[50];
	char* booksTitle = new char[100];
	cout << "Please enter the name of the student that rented the book.: ";
        cin.ignore();
	cin.getline(studentsName, 50);

	StudentPointer student = findStudent(studentsName);
	if (student == NULL)
	{
		cout << "Student Not Found" << endl;
		return;
	}
	else
	{
		cout << "Please enter the name of the book.: ";
		cin.getline(booksTitle, 100);
		BookPointer book = student->searchForBookRental(booksTitle);
		if(book == NULL)
		{
			cout << "That book was not rented by " << student->getName() << "." << endl;
		}
		else
		{
			cout << "Book:" << endl;
			cout << "\tTitle: " << book->title << endl;
			cout << "\tURL: " << book->url << endl;
		}
	}
}
/* Displays book entries for a specified student */
void showBookRentals()
{
	char* studentsName = new char[50];
	cout << "Please enter the name of the student.: ";
        cin.ignore();
	cin.getline(studentsName, 50);
	StudentPointer student = findStudent(studentsName);
	if (student == NULL)
	{
		cout << "Student Not Found" << endl;
		return;
	}
	else
	{
		student->displayBooks();
	}
}

/**
  * Search function for personnel (Student)
  * @param name
  * @return student
  */
StudentPointer findStudent(char* name)
{
	StudentPointer student = NULL;
	for (unsigned int index = 0; index < allStudents->size(); index++)
	{
		if (strcmp(allStudents->at(index)->getName(), name) == 0)
		{
			student = allStudents->at(index);
			break;
		}
	}
	return student;
}