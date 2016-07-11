/* 
 * File:   Product.cpp
 * 
 * Created on December 13, 2013, 5:02 PM
 */

#include "Product.h"

/**
 * Product constructor
 * @param id
 * @param price
 * @param amountAvailable
 * @param amountPurchased
 */
Product::Product(int id, float price, int amountAvailable, int amountPurchased)
{
	this->id = id;
	this->price = price;
	this->amountAvailable = amountAvailable;
	this->amountPurchased = amountPurchased;
}

/**
 * Product de-constructor
 */
Product::~Product()
{
}

/**
 * Accessor function for the ID
 * @return id
 */
int Product::getId()
{
        return id;
}

/**
 * Mutator function
 * @param id
 */	
void Product::setId(int id)
{
	this->id = id;
}

/**
 * Accessor function for the price
 * @return price
 */	
float Product::getPrice()
{
	return price;
}

/**
 * Mutator function for the price
 * @param price
 */
void Product::setPrice(float price)
{
	this->price = price;
}

/**
 * Accessor function for amount available
 * @return amountAvailable
 */
int Product::getAmountAvailable()
{
	return amountAvailable;
}

/**
 * Mutator method for amountAvailable
 * @param amountAvailable
 */
void Product::setAmountAvailable(int amountAvailable)
{
	this->amountAvailable = amountAvailable;
}

/**
 * Accessor function for amount purchased
 * @return amountPurchased
 */
int Product::getAmountPurchased()
{
	return amountPurchased;
}

/**
 * Mutator function for amountPurchased
 * @param amountPurchased
 */
void Product::setAmountPurchased(int amountPurchased)
{
	this->amountPurchased = amountPurchased;
};
	

