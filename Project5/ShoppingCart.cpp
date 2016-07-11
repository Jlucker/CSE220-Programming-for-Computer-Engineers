/* 
 * File:   ShoppingCart.cpp
 * 
 * Created on December 13, 2013, 5:05 PM
 */

#include "ShoppingCart.h"

float ShoppingCart::SALES_TAX = 0.09f;

/**
 * Shopping cart constructor
 */
ShoppingCart::ShoppingCart()
{
	this->products = new vector<ProductPointer>();
}

/**
 * Shopping cart de-constructor
 */
ShoppingCart::~ShoppingCart()
{
	delete this->products;
}

/**
 * Function that adds a product to the shopping cart
 * @param product
 */
void ShoppingCart::add(ProductPointer product)
{
	products->push_back(product);
}

/**
 * Function that removes a product from the shopping cart
 * @param product
 */
void ShoppingCart::remove(ProductPointer product)
{
	for (unsigned int index = 0; index < products->size(); index++)
	{
		if (product->getId() == products->at(index)->getId())
		{
			products->erase(products->begin() + index);
			break;
		}
	}
}

/**
 * Function that removes all products from the shopping cart
 */
void ShoppingCart::removeAll()
{
	products->clear();
}

/**
 * Function that calculates the sub total for the purchase
 * @return subTotal
 */
float ShoppingCart::subTotal()
{
	float subTotal = 0.00f;
	for (unsigned int index = 0; index < products->size(); index++)
		subTotal += products->at(index)->getPrice();
	return subTotal;
}

/**
 * Function that calculates the sales tax for the purchase
 * @return subTotal*sales tax
 */
float ShoppingCart::salesTax()
{
	return subTotal() * SALES_TAX;
}

/**
 * Function that calculates the grand total for the purchase
 * @return 
 */
float ShoppingCart::grandTotal()
{
	return subTotal() + salesTax();
}

/**
 * Function that searches the shopping cart by id number
 * @param id
 * @return productFound
 */
ProductPointer ShoppingCart::findById(int id)
{
	ProductPointer productFound = (ProductPointer) NULL;
	for (unsigned int index = 0; index < products->size(); index++)
	{
		if (id == products->at(index)->getId())
		{
			productFound = products->at(index);
			break;
		}
	}
	return productFound;
}

/**
 * Function that performs the checkout operation
 */
void ShoppingCart::checkout()
{
	ProductPointer product;
	char purchaseDecision;
	
	if (products->size() == 0)
	{
		cout << "There are no products in your shopping cart, please add items to checkout." << endl;
	}
	else
	{
		do
		{
			float grandTotal = this->grandTotal();
			display();
			char* temp = new char[10];
			sprintf(temp, "%.2f", grandTotal);
			cout << endl << "Your total, including tax, is: $" << temp << endl << endl
						 << "You can:" << endl
						 << "\tc: Complete your purchase." << endl
						 << "\tr: Return to the Manage Your Shopping Cart Menu." << endl
						 << endl << "Please enter your choice. : ";
			cin >> purchaseDecision;

			purchaseDecision = tolower(purchaseDecision);
			if(purchaseDecision == 'c')
			{
				for(unsigned int index = 0; index < products->size(); index++)
				{
					product = products->at(index);
					product->setAmountPurchased(product->getAmountPurchased() + 1);
					product->setAmountAvailable(product->getAmountAvailable() - 1);
				}
				removeAll();
				cout << "Thank you for your purchase!" << endl;
			}
			else if(purchaseDecision == 'r')
			{
				break;
			}
			else
			{
				cout << "Invalid choice." << endl;
				purchaseDecision = 'i';
			}
		}
		while (purchaseDecision == 'i');
	}
}

/**
 * Function that displays the cart 
 */
void ShoppingCart::display()
{
	cout << endl << "Your Shopping Cart:" << endl
		 << "-------------------" << endl;
	if (products->size() == 0)
	{
		cout << "There are no products in your shopping cart." << endl;
	}
	else
	{
		for (unsigned int index = 0; index < products->size(); index++)
			products->at(index)->display();
	}
};
