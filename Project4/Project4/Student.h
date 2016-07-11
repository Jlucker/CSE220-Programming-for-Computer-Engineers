//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        personnel.h
//******************************************************************************

#ifndef STUDENT_H
#define	STUDENT_H

#include <iostream>
#include <cstring>
#include "Personnel.h"

using namespace std;

enum StudentLevel_
{
	FRESHMAN,
	SOPHOMORE,
	JUNIOR,
	SENIOR
};

typedef enum StudentLevel_ StudentLevel;

struct Book_
{
	char* title;
	char* url;
	struct Book_* leftChild;
	struct Book_* rightChild;
};

typedef struct Book_ Book;
typedef struct Book_* BookPointer;

class Student : public Personnel
{
public:
	Student(char* name, char* birthday, char* address, char* phone, char* email, StudentLevel level);
	~Student();

	BookPointer getRentedBooks();
	void setRentedBooks(BookPointer books);
	StudentLevel getLevel();
	void setLevel(StudentLevel level);
	void display();
	void displayBooks();
	BookPointer searchForBookRental(char* title);
	void addBookRental(BookPointer newBook);
	void clearBookRentals();
private:
	BookPointer rentedBooks;
	StudentLevel level;

	void displayBooks(BookPointer book);
	BookPointer searchForBookRental(BookPointer book, char* title);
	void addBookRental(BookPointer book, BookPointer newBook);
	void clearBookRentals(BookPointer book);
};

typedef Student* StudentPointer;

#endif	/* STUDENT_H */

