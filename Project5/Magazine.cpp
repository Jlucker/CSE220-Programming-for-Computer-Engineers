/* 
 * File:   Magazine.cpp
 * 
 */

#include "Magazine.h"

/**
 * Magazine Constructor
 * @param id
 * @param title
 * @param price
 * @param amountAvailable
 * @param amountPurchased
 * @param issueNumber
 */ 
Magazine::Magazine(int id, string title, float price, int amountAvailable, int amountPurchased, int issueNumber) : Book(id, title, price, amountAvailable, amountPurchased)
{
	this->issueNumber = issueNumber;
	this->type = MAGAZINE;
}

/**
 * Magazine de-constructor
 */
Magazine::~Magazine()
{
}

/**
 * Accessor function for the issue number
 * @return issueNumber
 */
int Magazine::getIssueNumber()
{
	return issueNumber;
}

/**
 * Mutator function that sets the issue number
 * @param issueNumber
 */
void Magazine::setIssueNumber(int issueNumber)
{
	this->issueNumber = issueNumber;
}

/**
 * Displays the product's information.
 */
void Magazine::display()
{
	Book::display();
	cout << "\tIssue: " << issueNumber << endl;
}

/**
 * Function that converts the product's information into a string that can be 
 * printed out into a .txt file. 
 * @return temp
 */
string Magazine::serialize()
{
	char* temp = new char[1024];
	sprintf(temp, "%d, %.2f, %d, %d, Magazine, %s, %d", getId(), getPrice(), getAmountAvailable(), getAmountPurchased(), getTitle().c_str(), getIssueNumber());
	return string(temp);
};