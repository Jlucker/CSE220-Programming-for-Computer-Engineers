//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Personnel.cpp
// Description: Personnel class was provided in the CSE220-Project4-Recursion.pdf
//******************************************************************************

#include "Personnel.h"

int Personnel::lastId = 0;

Personnel::Personnel(char* name, char* birthday, char* address, char* phone, char* email)
{
	this->name = name;
	this->birthday = birthday;
	this->id = Personnel::lastId++;
	this->contact = new Contact(address, phone, email);
}

Personnel::~Personnel()
{
	delete this->name;
	delete this->birthday;
	delete this->contact;
}

char* Personnel::getName()
{
	return name;
}

void Personnel::setName(char* name)
{
	this->name = name;
}

char* Personnel::getBirthday()
{
	return birthday;
}

void Personnel::setBirthday(char* birthday)
{
	this->birthday = birthday;
}

int Personnel::getId()
{
	return id;
}

void Personnel::setId(int id)
{
	this ->id = id;
}

ContactPointer Personnel::getContact()
{
	return contact;
}

void Personnel::setContact(ContactPointer contact)
{
	this->contact = contact;
}

void Personnel::display()
{
	cout << "Personnel" << endl;
	cout << "\tName:\t" << name << endl;
	cout << "\tBirthday:\t" << birthday << endl;
	cout << "\tId:\t" << id << endl;
	cout << "\tAddress:\t" << contact->getAddress() << endl;
	cout << "\tPhone:\t" << contact->getPhone() << endl;
	cout << "\tEmail:\t" << contact->getEmail() << endl;
};
