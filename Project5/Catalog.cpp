/* 
 * File:   Catalog.cpp
 * 
 * Created on December 13, 2013, 5:04 PM
 */

#include <fstream>

#include "Catalog.h"

int Catalog::lastId = 0;

/**
 * Constructor function for Catalog
 */
Catalog::Catalog()
{
	this->products = new vector<ProductPointer>();
}

/**
 * De-constructor function for Catalog
 */
Catalog::~Catalog()
{
	delete this->products;
}

/**
 * Function that adds a product to the catalog
 * @param product
 */
void Catalog::add(ProductPointer product)
{
	product->setId(generateId());
	products->push_back(product);
}

/**
 * Function that removes product from the catalog
 * @param product
 */
void Catalog::remove(ProductPointer product)
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
 * Function that finds out what the most popular product from a copy of the 
 * product vector (aka catalog) is. 
 * @param products
 * @return mostPopular
 */
ProductPointer Catalog::mostPopularProduct(vector<ProductPointer>* products)
{
	ProductPointer mostPopular = (ProductPointer) NULL;
	int largestAmountPurchased = -1;
	for(unsigned int index = 0; index < products->size(); index++)
	{
		if(products->at(index)->getAmountPurchased() > largestAmountPurchased)
		{
			mostPopular = products->at(index);
			largestAmountPurchased = mostPopular->getAmountPurchased();
		}
	}
	return mostPopular;
}

/**
 * Function that finds out the most popular products. A copy of the product 
 * vector(catalog) is used to so once the most popular product is found it is 
 * removed from the copy of the catalog so the next most popular product can be 
 * found.  
 * @param numberOfProducts
 * @return 
 */
vector<ProductPointer>* Catalog::mostPopularProducts(int numberOfProducts)
{
	vector<ProductPointer>* popularProducts = new vector<ProductPointer>();
	popularProducts->reserve(numberOfProducts);
	ProductPointer mostPopular;
	vector<ProductPointer>* copyOfProducts = new vector<ProductPointer>(*products);
	for(int round = 0; round < numberOfProducts; round++)
	{
		mostPopular = mostPopularProduct(copyOfProducts);
		popularProducts->push_back(mostPopular);
		for(unsigned int index = 0; index < copyOfProducts->size(); index++)
		{
			if(mostPopular->getId() == copyOfProducts->at(index)->getId())
			{
				copyOfProducts->erase(copyOfProducts->begin() + index);
				break;
			}
		}
	}
	return popularProducts;
}

/**
 * Function that loads/reads products from a .txt file - there is a Book.txt file 
 * included in this project that specifies how the file is formatted - into the 
 * catalog 
 * @param fileName
 */
void Catalog::loadBooks(string fileName)
{
	string line;
	ifstream catalogFile;
	char* temp = new char[1024];
	catalogFile.open(fileName.c_str(), ifstream::in);
	catalogFile.getline(temp, 1024);
	line = temp;
	while(line.size() > 0)
	{
		trim(line);
		if(line.size() > 0 && line.at(0) != '#')
		{
			vector<string>* elements = split(',', line);
			BookPointer book = (BookPointer) NULL;
			if(elements->at(4) == "Book")
				book = new Book(atoi(elements->at(0).c_str()), elements->at(5), atof(elements->at(1).c_str()), atoi(elements->at(2).c_str()), atoi(elements->at(3).c_str()));
			else if(elements->at(4) == "FictionBook")
				book = (BookPointer) new FictionBook(atoi(elements->at(0).c_str()), elements->at(5), atof(elements->at(1).c_str()), atoi(elements->at(2).c_str()), atoi(elements->at(3).c_str()), elements->at(6));
			else if(elements->at(4) == "Magazine")
				book = (BookPointer) new Magazine(atoi(elements->at(0).c_str()), elements->at(5), atof(elements->at(1).c_str()), atoi(elements->at(2).c_str()), atoi(elements->at(3).c_str()), atoi(elements->at(6).c_str()));
			else if(elements->at(4) == "Textbook")
				book = (BookPointer) new Textbook(atoi(elements->at(0).c_str()), elements->at(5), atof(elements->at(1).c_str()), atoi(elements->at(2).c_str()), atoi(elements->at(3).c_str()), elements->at(6), atoi(elements->at(7).c_str()), elements->at(8));
			else
				cout << "Error: Unknown Book Type '" << elements->at(4) << "' found. Skipping" << endl;
			if(book != NULL)
				add(book);
		}
		catalogFile.getline(temp, 1024);
		line = temp;
	}
	catalogFile.close();
}

/**
 * Function that saves/writes the products from the catalog into a .txt in a 
 * specified format.
 * @param fileName
 */
void Catalog::saveBooks(string fileName)
{
	ofstream catalogFile;
	catalogFile.open(fileName.c_str(), ofstream::out);
	for(unsigned int index = 0; index < products->size(); index++)
		catalogFile << products->at(index)->serialize() << endl;
	catalogFile.close();
}

/**
 * Function that searches for a product by its ID number
 * @param id
 * @return productFound
 */
ProductPointer Catalog::findById(int id)
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
 * Function that displays the catalog
 */
void Catalog::display()
{
	cout << endl << "Catalog:" << endl
				 << "--------" << endl;
	if (products->size() == 0)
	{
		cout << "There are no products in the catalog." << endl;
	}
	else
	{
		for (unsigned int index = 0; index < products->size(); index++)
			products->at(index)->display();
	}
}

/**
 * Function that creates an ID number for each product that is added
 * @return lastId - incremented one greater than the previous book in the catalog
 */
int Catalog::generateId()
{
	return ++lastId;
};

/**
 * Function that is used by loadBooks() in the creation of the vector using input 
 * information from the .txt file
 * @param deliminator
 * @param line
 * @return elements
 */
vector<string>* Catalog::split(const char deliminator, string& line)
{
	vector<string>* elements = new vector<string>();
	unsigned int startOfElement = 0;
	for(unsigned int index = 0; index < line.size(); index++)
	{
		const char character = line.at(index);
		if(character == deliminator || index == line.size() - 1)
		{
			if(startOfElement != index)
			{
				string element;
				if(index == line.size() - 1)
					element = line.substr(startOfElement, index + 1 - startOfElement);
				else
					element = line.substr(startOfElement, index - startOfElement);
				trim(element);
				elements->push_back(element);
			}
			else
			{
				elements->push_back("");
			}
			startOfElement = index + 1;
		}
	}
	return elements;
}

/**
 * Function that is used by loadBooks() in the creation of the vector using input 
 * information from file
 * @param line
 */
void Catalog::trim(string& line)
{
	unsigned int indexOfNonWhitespace = -1;
	for(unsigned int index = 0; index < line.size(); index++)
	{
		char character = line.at(index);
		if(character != ' ' && character != '\t' && character != '\n' && character != '\r')
		{
			indexOfNonWhitespace = index;
			break;
		}
	}
	if(indexOfNonWhitespace == -1)
	{
		line = "";
		return;
	}
	line.erase(0, indexOfNonWhitespace);
	indexOfNonWhitespace = -1;
	for(unsigned int index = line.size() - 1; index >= 0; index--)
	{
		char character = line.at(index);
		if(character != ' ' && character != '\t' && character != '\n' && character != '\r')
		{
			indexOfNonWhitespace = index;
			break;
		}
	}
	if(indexOfNonWhitespace != -1 && indexOfNonWhitespace != line.size() - 1)
		line.erase(indexOfNonWhitespace + 1, line.size());
};