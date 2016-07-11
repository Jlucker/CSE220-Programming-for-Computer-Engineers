/* 
 * File:   Book.h
 * 
 */

#ifndef BOOK_H
#define	BOOK_H
#include "Product.h"

class Book : public Product
{
public:
	Book(int id, string title, float price, int amountAvailable, int amountPurchased);
	virtual ~Book();

	enum Type
	{
		GENERIC,
		FICTION,
		MAGAZINE,
		TEXTBOOK
	};
	
	virtual string getTitle();
	virtual void setTitle(string title);
	virtual Book::Type getType();
	virtual void setType(Book::Type type);
	virtual void display();
	virtual string serialize();
	Book::Type type;

private:
	string title;	
};

typedef Book* BookPointer;
#endif	/* BOOKNODE_H */

