/* 
 * File:   Product.h
 *
 * Created on December 13, 2013, 5:02 PM
 */

#ifndef PRODUCT_H
#define	PRODUCT_H
#include <string>
#include <iomanip>
#include <iostream>
#include <cstdio>

using namespace std;

class Product
{
public:
	Product(int id, float price, int amountAvailable, int amountPurchased);
	virtual ~Product();
	
	virtual int getId();
	virtual void setId(int id);
	virtual float getPrice();
	virtual void setPrice(float price);
	virtual int getAmountAvailable();
	virtual void setAmountAvailable(int amountAvailable);
	virtual int getAmountPurchased();
	virtual void setAmountPurchased(int amountPurchased);
	virtual void display() = 0;
	virtual string serialize() = 0;
	
private:
	int id;
	float price;
	int amountAvailable;
	int amountPurchased;
};

typedef Product* ProductPointer;

#endif	/* PRODUCT_H */