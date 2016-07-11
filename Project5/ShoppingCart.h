/* 
 * File:   ShoppingCart.h
 *
 * Created on December 13, 2013, 5:05 PM
 */

#ifndef SHOPPINGCART_H
#define	SHOPPINGCART_H
#include <vector>
#include "Product.h"

using namespace std;

class ShoppingCart
{
public:
	static float SALES_TAX;

	ShoppingCart();
	virtual ~ShoppingCart();
	
	virtual void add(ProductPointer product);
	virtual void remove(ProductPointer product);
	virtual void removeAll();
	virtual float subTotal();
	virtual float salesTax();
	virtual float grandTotal();
	virtual ProductPointer findById(int id);
	virtual void checkout();
	virtual void display();
private:
	vector<ProductPointer>* products;
};

typedef ShoppingCart* ShoppingCartPointer;
#endif	/* SHOPPINGCART_H */

