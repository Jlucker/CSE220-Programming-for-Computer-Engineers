/* 
 * File:   Fiction.h
 * 
 */

#ifndef FICTION_BOOK_H
#define	FICTION_BOOK_H

#include "Book.h"

using namespace std;

class FictionBook : public Book
{
public:
	FictionBook(int id, string title, float price, int amountAvailable, int amountPurchased, string author);
	~FictionBook();
	
	virtual string getAuthor();
	virtual void setAuthor(string author);
	virtual void display();
	virtual string serialize();
private:
	string author;
};

typedef FictionBook* FictionBookPointer;

#endif	/* FICTION_BOOK_H */

