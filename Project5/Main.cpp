/* 
 * File:   main.cpp
 * 
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdbool.h>
#include <fstream>

#include "Main.h"
#include "Catalog.h"
#include "ShoppingCart.h"
#include "Product.h"
#include "Book.h"
#include "FictionBook.h"

using namespace std;

CatalogPointer catalog;
ShoppingCartPointer shoppingCart;

/**
 * Displays options and calls the available functions
 * @return EXIT_SUCCESS - shows if the program exited 
 */
int main()
{
	catalog = new Catalog();
	catalog->loadBooks("Books.txt");
	shoppingCart = new ShoppingCart();

	bool shouldContinue;
	
	do
	{
		showMainMenu();
		shouldContinue = processMainMenu();
	}
	while (shouldContinue);
	catalog->saveBooks("Books.txt");
	cout << endl << "Thank you for shopping with us." << endl;
	cin.get();

	return EXIT_SUCCESS;
}

/**
 * Prints the main menu
 */
void showMainMenu()
{
	cout << "--------------------------------" << endl
			<< "Welcome to Bookstore - Main Menu" << endl
			<< "--------------------------------" << endl
			<< "You can:" << endl << endl
			<< "\tb: Browse our catalog." << endl
			<< "\tm: Manage the catalog." << endl
			<< "\tv: Manage your shopping cart." << endl
			<< "\tq: Quit." << endl << endl
			<< "Please enter your choice. : ";
}

/**
 * Captures the user's input from the main menu and processes their choice.
 * @return shouldContinue - flag for if the user would like to quit
 */
bool processMainMenu()
{
	bool shouldContinue = true;
	bool stillInSubMenu;
	char selectedOption;
	
	cin >> selectedOption;
	selectedOption = tolower(selectedOption);
	
	switch (selectedOption)
	{
		case 'b':
			do
			{
				showBrowseCatalogMenu();
				stillInSubMenu = processBrowseCatalogMenu();
			}
			while (stillInSubMenu);
			break;
		case 'm':
			do
			{
				showManageCatalogMenu();
				stillInSubMenu = processManageCatalogMenu();
			}
			while (stillInSubMenu);
			break;
		case 'v':
			do
			{
				showShoppingCartMenu();
				stillInSubMenu = processShoppingCartMenu();
			}
			while (stillInSubMenu);
			break;
		case 'q':
			shouldContinue = false;
			break;
		default:
			cout << endl << "Invalid menu selection." << endl;
			showMainMenu();
	}
	
	return shouldContinue;
}

/**
 * Prints the browse catalog menu
 */
void showBrowseCatalogMenu()
{
	cout << endl << "-------------------" << endl
			<< "Browse Catalog Menu" << endl
			<< "-------------------" << endl
			<< "You can:" << endl << endl
			<< "\ta: View all of our catalog's products." << endl
			<< "\tp: View our most popular titles." << endl
			<< "\tr: Return to the main menu." << endl << endl
			<< "Please enter your choice. : ";
}

/**
 * Captures the user's input from the browse catalog menu and processes their 
 * choice.
 * @return should continue - flag for if the user wants to go back to the main menu
 */
bool processBrowseCatalogMenu()
{
	bool shouldContinue = true;
	char selectedOption;
	
	cin >> selectedOption;
	selectedOption = tolower(selectedOption);
	
	switch (selectedOption)
	{
		case 'a':
			viewAllCatalogProducts();
			break;
		case 'p':
			viewMostPopularProducts();
			break;
		case 'r':
			cout << endl;
			shouldContinue = false;
			break;
		default:
			cout << endl << "Invalid menu selection." << endl;
			showBrowseCatalogMenu();
	}
	
	return shouldContinue;
}

/**
 * Prints the manage catalog menu.
 */
void showManageCatalogMenu()
{
	cout << endl << "-------------------" << endl
			<< "Manage Catalog Menu" << endl
			<< "-------------------" << endl
			<< "You can:" << endl << endl
			<< "\tg: Add a generic book to the catalog." << endl
			<< "\tf: Add a fiction book to the catalog." << endl
			<< "\tm: Add a magazine to the catalog." << endl
			<< "\tt: Add a textbook to the catalog." << endl
			<< "\ti: Remove a product from the catalog." << endl
			<< "\tr: Return to the main menu." << endl << endl
			<< "Please enter your choice. : ";
}

/**
 * Captures the user's input from the manage catalog menu and processes their 
 * choice.
 * @return shouldContinue - flag for if the user wants to go back to the main menu
 */
bool processManageCatalogMenu()
{
	bool shouldContinue = true;
	char selectedOption;
	int idToSearchFor;
	
	cin >> selectedOption;
	selectedOption = tolower(selectedOption);
	
	switch (selectedOption)
	{
		case 'g':
			addGenericBookToCatalog();
			break;
		case 'f':
			addFictionBookToCatalog();
			break;
		case 'm':
			addMagazineToCatalog();
			break;
		case 't':
			addTextbookToCatalog();
			break;
		case 'i':
			viewAllCatalogProducts();
			cout << endl << "Please enter the ID number of the item you would like to remove: ";
			cin >> idToSearchFor;
			removeProductFromCatalog(idToSearchFor);
			break;
		case 'r':
			cout << endl;
			shouldContinue = false;
			break;
		default:
			cout << endl << "Invalid menu selection." << endl;
			showManageCatalogMenu();
	}
	
	return shouldContinue;
}

/**
 * Prints the shopping cart menu.
 */
void showShoppingCartMenu()
{
	cout << endl << "------------------------------" << endl
			<< "Manage Your Shopping Cart Menu" << endl
			<<  "------------------------------" << endl
			<< "You can:" << endl << endl
			<< "\ta: Add an item to your cart." << endl
			<< "\tx: Remove an item from your cart." << endl
			<< "\tv: View your cart." << endl
			<< "\te: Empty your cart." << endl
			<< "\tc: Checkout." << endl
			<< "\tr: Return to the main menu." << endl << endl
			<< "Please enter your choice. : ";
}

/**
 * Captures the user's input from the shopping cart menu and processes their 
 * choice.
 * @return shouldContinue - flag for if the user wants to go back to the main menu
 */
bool processShoppingCartMenu()
{
	bool shouldContinue = true;
	char selectedOption;
	int idToSearchFor;
	
	cin >> selectedOption;
	selectedOption = tolower(selectedOption);
	
	switch (selectedOption)
	{
		case 'a':
			viewAllCatalogProducts();
			cout << endl << "Please enter the ID number of the item you would like to add: ";
			cin >> idToSearchFor;
			addProductToCart(idToSearchFor);
			break;
		case 'x':
			shoppingCart->display();
			cout << endl << "Please enter the ID number of the item you would like to remove: ";
			cin >> idToSearchFor;
			removeProductFromCart(idToSearchFor);
			break;
		case 'v':
			viewCart();
			break;	
		case 'e':
			emptyCart();
			break;
		case 'c':
			checkout();
			break;
		case 'r':
			cout << endl;
			shouldContinue = false;
			break;
		default:
			cout << endl << "Invalid menu selection." << endl;
			showMainMenu();
	}
	return shouldContinue;
}

/**
 * Displays all catalog items
 */
void viewAllCatalogProducts()
{
	catalog->display();
}

/**
 * Displays the three most popular books from the catalog
 */
void viewMostPopularProducts()
{
	vector<ProductPointer>* popularProducts = catalog->mostPopularProducts(3);
	cout << endl << "Three Most Popular Products:" << endl
		 << "----------------------------" << endl;
	for(unsigned int index = 0; index < popularProducts->size(); index++)
		popularProducts->at(index)->display();
} 

/**
 * Adds a generic book to the catalog 
 */
void addGenericBookToCatalog()
{
	int id = 0;
	char* title = new char[75];
	float price;
	int amountAvailable;
	int amountPurchased = 0;
	
	cout << endl << "Adding a Generic Book:" << endl
		 <<	"----------------------" << endl;
	cin.ignore();
	cout << "Please enter the title: ";
	cin.getline(title, 75);
	cout << "Please enter the price: $";
	cin >> price;
	cout << "Please enter the amount of " << title << " to be added to the catalog: ";
	cin >> amountAvailable;
	BookPointer book = new Book(id, string(title), price, amountAvailable, amountPurchased);
	catalog->add(book);
	cout << endl << "The generic book " << title << " was added successfully!"<< endl;
}

/**
 * Adds a fiction book to the catalog
 */
void addFictionBookToCatalog()
{
	int id = 0;
	char* title = new char[75];
	float price;
	int amountAvailable;
	int amountPurchased = 0;
	char* author = new char[75];
	
	cout << endl << "Adding a Fiction Book:" << endl
		 <<	"----------------------" << endl;
	cin.ignore();
	cout << "Please enter the title: ";
	cin.getline(title, 75);
	cout << "Please enter the price: $";
	cin >> price;
	cout << "Please enter the amount of " << title << " to be added to the catalog: ";
	cin >> amountAvailable;
	cin.ignore();
	cout << "Please enter the author of " << title << " : ";
	cin.getline(author, 75);
	FictionBookPointer fictionBook = new FictionBook(id, string(title), price, amountAvailable, amountPurchased, string(author));
	catalog->add(fictionBook);
	cout << endl << "The fiction book " << title << " was added successfully!"<< endl;
}

/**
 * Adds a magazine to the catalog 
 */
void addMagazineToCatalog()
{
	int id = 0;
	char* title = new char[75];
	float price;
	int amountAvailable;
	int amountPurchased = 0;
	int issueNumber;
	
	cout << endl << "Adding a Magazine:" << endl
		 <<	"------------------" << endl;
	cin.ignore();
	cout << "Please enter the title: ";
	cin.getline(title, 75);
	cout << "Please enter the price: $";
	cin >> price;
	cout << "Please enter the amount of " << title << " to be added to the catalog: ";
	cin >> amountAvailable;
	cout << "Please enter the issue number of " << title << " : ";
	cin >> issueNumber;
	MagazinePointer magazine = new Magazine(id, string(title), price, amountAvailable, amountPurchased, issueNumber);
	catalog->add(magazine);
	cout << endl << "The magazine " << title << ", issue " << issueNumber << ", was added successfully!"<< endl;
}

/**
 * Adds a textbook to the catalog 
 */
void addTextbookToCatalog()
{
	int id = 0;
	char* title = new char[75];
	float price;
	int amountAvailable;
	int amountPurchased = 0;
	char* author = new char[75];
	int edition;
	char* isbn = new char[14];
	
	cout << endl << "Adding a Textbook:" << endl
		 <<	"------------------" << endl;
	cin.ignore();
	cout << "Please enter the title: ";
	cin.getline(title, 75);
	cout << "Please enter the price: $";
	cin >> price;
	cout << "Please enter the amount of " << title << " to be added to the catalog: ";
	cin >> amountAvailable;
	cin.ignore();
	cout << "Please enter the author of " << title << " : ";
	cin.getline(author, 75);
	cout << "Please enter the edition of " << title << " : ";
	cin >> edition;
	cin.ignore();
	cout << "Please enter the ISBN of " << title << " : ";
	cin.getline(isbn, 14);
	TextbookPointer textbook = new Textbook(id, string(title), price, amountAvailable, amountPurchased, string(author), edition, string(isbn));
	catalog->add(textbook);
	cout << endl << "The textbook " << title << ", edition " << edition << ", was added successfully!"<< endl;
}

/**
 * Removes a product from the catalog. 
 */
void removeProductFromCatalog(int id)
{
	ProductPointer product = catalog->findById(id);
	if(product != NULL)
	{
		catalog->remove(product);
		cout << "Product #" << id << " was successfully removed!"<< endl;
	}
	else
	{
		cout << "No product with that ID is in the catalog." << endl;
	}
}

/** Adds a book into the shopping cart. This method will also display all books 
 *in the cart with title, id, and price of each book and the total price. Three 
 *“Most Popular Books” will also be displayed. If the cart does not exist a new
 * linked list will be created.
 */
void addProductToCart(int id) // need to replace parameter with BookNode userCart
{
	ProductPointer product = catalog->findById(id);
	if(product->getAmountAvailable() > 0)
	{
		shoppingCart->add(catalog->findById(id));
		cout << "Product #" << id << " was successfully added to your cart!" << endl << endl
			 << "**Additional Purchase Suggestions**" << endl;
		viewMostPopularProducts();
	}
	else
	{
		cout << "Sorry, but that product is not available." << endl;
	}
}

void removeProductFromCart(int id) // need to replace parameter with BookNode userCart
{
	ProductPointer product = shoppingCart->findById(id);
	if(product != NULL)
	{
		shoppingCart->remove(product);
		cout << "Product #" << id << " was successfully removed!"<< endl;
	}
	else
	{
		cout << "No such product is in your shopping cart." << endl;
	}
}

/**
 * Function that views the cart by calling display()
 */
void viewCart()
{
	shoppingCart->display();
}

/**
 * Function that empties the cart by calling removeAll()
 */
void emptyCart()
{
	shoppingCart->removeAll();
	cout << "Your cart has been emptied." << endl;
}

/**
 * Function that calls checkout() to checkout
 */
void checkout()
{
	shoppingCart->checkout();
};



