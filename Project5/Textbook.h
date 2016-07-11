/* 
 * File:   Textbook.h
 * 
 */

#ifndef TEXTBOOK_H
#define	TEXTBOOK_H

#include "Book.h"

using namespace std;

class Textbook : public Book
{
public:
	Textbook(int id, string title, float price, int amountAvailable, int amountPurchased, string author, int edition, string isbn);
	~Textbook();
	
	virtual string getAuthor();
	virtual void setAuthor(string author);
	virtual int getEdition();
	virtual void setEdition(int edition);
	virtual string getISBN();
	virtual void setISBN(string isbn);
	virtual void display();
	virtual string serialize();
private:
	string author;
	int edition;
	string isbn;
};

typedef Textbook* TextbookPointer;
#endif	/* TEXTBOOK_H */

