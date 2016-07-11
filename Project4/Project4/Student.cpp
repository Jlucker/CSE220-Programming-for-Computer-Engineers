//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Student.cpp
// Description:  Subclass of Personnel-Inherits from Personnel Class
//               Additional Information: BookTree
//               The student class is used to create node of type student.  It
//               contains unique information StudentLevel which is the current 
//               grade level of the student.  The student class also contains 
//               binary tree that maintains a record of the books that the 
//               has rented.
//******************************************************************************

#include "Student.h"

/*Student Constructor*/
Student::Student(char* name, char* birthday, char* address, char* phone, char* email, StudentLevel level)
: Personnel(name, birthday, address, phone, email)
{
	this->rentedBooks = NULL;
	this->level = level;
}

Student::~Student()
{
}

/**
  * Function that gets the student's rented books 
  * @return rentedBooks 
  */
BookPointer Student::getRentedBooks()
{
	return rentedBooks;
}

/**
  * Mutator method that can modify the books that a student has 
  * @param rentedBooks
  */
void Student::setRentedBooks(BookPointer rentedBooks)
{
	this->rentedBooks = rentedBooks;
}

/**
  * Function that gets the student's StudentLevel
  * @return rentedBooks 
  */
StudentLevel Student::getLevel()
{
	return level;
}

/**
  * Mutator method that can modify StudentLevel of the student
  * @param level
  */
void Student::setLevel(StudentLevel level)
{
	this->level = level;
}

/* Displays the students current StudentLevel and the books that the student has
   borrowed*/
void Student::display()
{
	Personnel::display();
	cout << "\tLevel:\t";
	switch (level)
	{
		case FRESHMAN:
			cout << "Freshman" << endl;
			break;
		case SOPHOMORE:
			cout << "Sophomore" << endl;
			break;
		case JUNIOR:
			cout << "Junior" << endl;
			break;
		case SENIOR:
			cout << "Senior" << endl;
			break;
	}
	cout << "\tBooks Borrowed:" << endl;
	displayBooks(rentedBooks);

}

/* Displays title and URL of books that the student has rented by calling the 
   the displayBooks method with parameter (rentedBooks) */
void Student::displayBooks()
{
	displayBooks(rentedBooks);
}

/**
  * displayBooks iterates through the binary tree and displays all of the books
  * that a student has.  
  * @param book
  */
void Student::displayBooks(BookPointer book)
{
	if (book != NULL)
	{
		cout
				<< "\t\tBorrowed Book" << endl
				<< "\t\t\tTitle: " << book->title << endl
				<< "\t\t\tURL: " << book->url << endl;
		if (book->leftChild != NULL)
			displayBooks(book->leftChild);
		if (book->rightChild != NULL)
			displayBooks(book->rightChild);
	}
	else
	{
		cout << "\t\tNo books borrowed." << endl;
	}
}

/**
  * Implements the searchForBookRental(book, title) function by using rentedBooks
  * which is all the books that a student has rented and title which is taken
  * as input from the user in main.cpp
  * @param title
  * @return searchForBookRental(rentedBooks, title)
  */
BookPointer Student::searchForBookRental(char* title)
{
	return searchForBookRental(rentedBooks, title);
}

/**
  * Searches the binary tree for the specified book
  * @param book
  * @param title
  * @return searchForBookRental(book->leftChild, title)
  * @return searchForBookRental(book->rightChild, title)
  */
BookPointer Student::searchForBookRental(BookPointer book, char* title)
{
	if (strcmp(title, book->title) == 0)
	{
		return book;
	}
	else if (title[0] <= book->title[0])
	{
		if (book->leftChild != NULL)
			return searchForBookRental(book->leftChild, title);
		else
			return NULL;
	}
	else
	{
		if (book->rightChild != NULL)
			return searchForBookRental(book->rightChild, title);
		else
			return NULL;
	}
}

/* addBookRental adds the specified book to the binary tree using 
   addBookRental(BookPointer book, BookPointer newBook) */
void Student::addBookRental(BookPointer newBook)
{
	if (rentedBooks == NULL)
		rentedBooks = newBook;
	else
		addBookRental(rentedBooks, newBook);
}

/**
  * addBookRental first searches to see if the book exists in the binary tree
  * and then if not it adds the specified book to the binary tree
  * @param book
  * @param newBook
  */
void Student::addBookRental(BookPointer book, BookPointer newBook)
{
	if (newBook->title[0] <= book->title[0])
	{
		if (book->leftChild != NULL)
			addBookRental(book->leftChild, newBook);
		else
			book->leftChild = newBook;
	}
	else
	{
		if (book->rightChild != NULL)
			addBookRental(book->rightChild, newBook);
		else
			book->rightChild = newBook;
	}
}
/* uses clearBookRentals(BookPointer book) to delete all of a students book rentals */
void Student::clearBookRentals()
{
	clearBookRentals(rentedBooks);
	this->rentedBooks = NULL;
}

/**
  * clearBookRentals iterates through the binary tree and deletes all of the book
  * rentals for a student.  
  * @param book
  */
void Student::clearBookRentals(BookPointer book)
{
	if (book != NULL)
	{
		if (book->leftChild != NULL)
			clearBookRentals(book->leftChild);
		if (book->rightChild != NULL)
			clearBookRentals(book->rightChild);
		delete book;
	}
}