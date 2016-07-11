/* 
 * File:   Book.cpp
 *
 */

#include "Book.h"

/**
 * Book Constructor
 * @param id
 * @param title
 * @param price
 * @param amountAvailable
 * @param amountPurchased
 */
Book::Book(int id, string title, float price, int amountAvailable, int amountPurchased) : Product(id, price, amountAvailable, amountPurchased)
{
	this->title = title;
	this->type = GENERIC;
}

/**
 * Book de-constructor
 */
Book::~Book()
{
}

/**
 * Accessor function for product's title
 * @return title
 */
string Book::getTitle()
{
	return title;
}

/**
 * Mutator function for product's title
 * @param title
 */
void Book::setTitle(string title)
{
	this->title = title;
}

/**
 * Accessor function for product's type
 * @return type
 */
Book::Type Book::getType()
{
	return type;
}

/**
 * Mutator function for product's type
 * @param type
 */
void Book::setType(Book::Type type)
{
	this->type = GENERIC;
}

/**
 * Function that displays product's information
 */
void Book::display()
{
	string typeAsString;
	switch(type)
	{
		case GENERIC:
			typeAsString = "Generic Book";
			break;
		case FICTION:
			typeAsString = "Fiction Book";
			break;
		case MAGAZINE:
			typeAsString = "Magazine";
			break;
		case TEXTBOOK:
			typeAsString = "Textbook";
			break;
		default:
			typeAsString = "Unknown";
	}
	
	cout << endl << "\tProduct Information:" << endl
			<< "\t--------------------" << endl
			<< "\tID: " << getId() << endl
			<< "\tTitle: " << title << endl
			<< "\tProduct Type: " << typeAsString << endl
			<< "\tPrice: $" << getPrice() << endl
			<< "\tAmount Available: " << getAmountAvailable() << endl
			<< "\tAmount Purchased: " << getAmountPurchased() << endl;
}

/**
 * Function that converts the product's information into a string that can be 
 * printed out into a .txt file. 
 * @return temp
 */
string Book::serialize()
{
	char* temp = new char[1024];
	sprintf(temp, "%d, %.2f, %d, %d, Book, %s", getId(), getPrice(), getAmountAvailable(), getAmountPurchased(), getTitle().c_str());
	return string(temp);
};