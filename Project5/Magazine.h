/* 
 * File:   Magazine.h
 * 
 */

#ifndef MAGAZINE_H
#define	MAGAZINE_H

#include "Book.h"

using namespace std;

class Magazine : public Book
{
public:
	Magazine(int id, string title, float price, int amountAvailable, int amountPurchased, int issueNumber);
	~Magazine();
	
	virtual int getIssueNumber();
	virtual void setIssueNumber(int issueNumber);
	virtual void display();
	virtual string serialize();
private:
	int issueNumber;
};

typedef Magazine* MagazinePointer;
#endif	/* MAGAZINE_H */

