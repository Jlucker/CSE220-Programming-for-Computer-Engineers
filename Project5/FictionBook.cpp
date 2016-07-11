/* 
 * File:   Fiction.cpp
 * 
 */

#include "FictionBook.h"

/**
 * FictionBook Constructor
 * @param id
 * @param title
 * @param price
 * @param amountAvailable
 * @param amountPurchased
 * @param author
 */
FictionBook::FictionBook(int id, string title, float price, int amountAvailable, int amountPurchased, string author) : Book(id, title, price, amountAvailable, amountPurchased)
{
	this->author = author;
	this->type = FICTION;
}

/**
 * FictionBook de-constructor
 */
FictionBook::~FictionBook()
{
}
/**
 * Accessor function for the author
 * @return 
 */
string FictionBook::getAuthor()
{
	return author;
}

/**
 * Mutator function that sets author
 * @param author
 */
void FictionBook::setAuthor(string author)
{
	this->author = author;
}

/**
 * Function that displays the author of the book
 */
void FictionBook::display()
{
	Book::display();
	cout << "\tAuthor: " << author << endl;
}

/**
 * Function that converts the product's information into a string that can be 
 * printed out into a .txt file. 
 * @return 
 */
string FictionBook::serialize()
{
	char* temp = new char[1024];
	sprintf(temp, "%d, %.2f, %d, %d, FictionBook, %s, %s", getId(), getPrice(), getAmountAvailable(), getAmountPurchased(), getTitle().c_str(), getAuthor().c_str());
	return string(temp);
};