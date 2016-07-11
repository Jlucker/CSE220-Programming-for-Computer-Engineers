/* 
 * File:   Textbook.cpp
 * 
 */

#include "Textbook.h"

/**
 * Textbook constructor
 * @param id
 * @param title
 * @param price
 * @param amountAvailable
 * @param amountPurchased
 * @param author
 * @param edition
 * @param isbn
 */
Textbook::Textbook(int id, string title, float price, int amountAvailable, int amountPurchased, string author, int edition, string isbn) : Book(id, title, price, amountAvailable, amountPurchased)
{
	this->author = author;
	this->edition = edition;
	this->isbn = isbn;
}

/**
 * Textbook De-constructor
 */
Textbook::~Textbook()
{
}

/**
 * Accessor function that gets the author
 * @return author
 */
string Textbook::getAuthor()
{
	return author;
}

/**
 * Mutator function that sets the author
 * @param author
 */
void Textbook::setAuthor(string author)
{
	this->author = author;
}

/**
 * Accessor function that gets the edition
 * @return edition
 */
int Textbook::getEdition()
{
	return edition;
}

/**
 * Mutator function that sets the edition
 * @param edition
 */
void Textbook::setEdition(int edition)
{
	this->edition = edition;
}

/**
 * Accessor function that gets the ISBN
 * @return isbn
 */
string Textbook::getISBN()
{
	return isbn;
}

/**
 * Mutator function that sets the ISBN
 * @param isbn
 */
void Textbook::setISBN(string isbn)
{
	this->isbn = isbn;
}

/**
 *  Function that displays the product information
 */
void Textbook::display()
{
	Book::display();
	cout << "\tAuthor: " << author << endl;
	cout << "\tEdition: " << edition << endl;
	cout << "\tISBN: " << isbn << endl;
}

/**
 * Function that converts the product's information into a string that can be 
 * printed out into a .txt file. 
 * @return temp
 */
string Textbook::serialize()
{
	char* temp = new char[1024];
	sprintf(temp, "%d, %.2f, %d, %d, Textbook, %s, %s, %d, %s", getId(), getPrice(), getAmountAvailable(), getAmountPurchased(), getTitle().c_str(), getAuthor().c_str(), getEdition(), getISBN().c_str());
	return string(temp);
};