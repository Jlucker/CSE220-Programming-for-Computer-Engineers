/* 
 * File:   Catalog.h
 *
 * Created on December 13, 2013, 5:04 PM
 */

#ifndef CATALOG_H
#define	CATALOG_H
#include <cstdlib>
#include <vector>
#include "Product.h"
#include "Book.h"
#include "FictionBook.h"
#include "Magazine.h"
#include "Textbook.h"

using namespace std;

class Catalog
{
public:
	Catalog();
	virtual ~Catalog();
	
	virtual void add(ProductPointer product);
	virtual void remove(ProductPointer product);
	virtual vector<ProductPointer>* mostPopularProducts(int numberOfProducts);
	virtual void loadBooks(string fileName);
	virtual void saveBooks(string fileName);
	virtual ProductPointer findById(int id);
	virtual void display();
private:
	vector<ProductPointer>* products;
	static int lastId;
	
	int generateId();
	vector<string>* split(const char deliminator, string& line);
	void trim(string& line);
	virtual ProductPointer mostPopularProduct(vector<ProductPointer>* products);
};

typedef Catalog* CatalogPointer;
#endif	/* CATALOG_H */

