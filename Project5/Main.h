/* 
 * File:   main.h
 *
 * Project Description: This project simulates an online shopping system where
 * users can: add a book into the sale catalog; remove a book from the sale 
 * catalog; add books into their shopping cart; view recommendations of the
 * three most popular books; and check out the books from their shopping cart.
 */

#ifndef MAIN_H
#define	MAIN_H

int main();									// done

void showMainMenu();						// done
bool processMainMenu();						// done
void showBrowseCatalogMenu();				// done
bool processBrowseCatalogMenu();			// done
void showManageCatalogMenu();				// done
bool processManageCatalogMenu();			// done
void showShoppingCartMenu();				// done
bool processShoppingCartMenu();				// TODO

void readData();							// TO DO
void writeData();							// TO DO

void viewAllCatalogProducts();				// done
void viewMostPopularProducts();				// TO DO

void addGenericBookToCatalog();				// TO DO
void addFictionBookToCatalog();				// TO DO
void addMagazineToCatalog();				// TO DO
void addTextbookToCatalog();				// TO DO
void viewAllCatalogProducts();
void removeProductFromCatalog(int id);		// TO DO

void addProductToCart(int id);			// TO DO
void removeProductFromCart(int id);		// TO DO
void viewCart();							// TO DO
void emptyCart();							// TO DO
void checkout();							// TO DO

#endif	/* MAIN_H */

