//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Contact.cpp
// Description: Contact class was provided in the CSE220-Project4-Recursion.pdf
//******************************************************************************

#include "Contact.h"

Contact::Contact(char* address, char* phone, char* email)
{
	this->address = address;
	this->phone = phone;
	this->email = email;
}

Contact::~Contact()
{
	delete this->address;
	delete this->phone;
	delete this->email;
}

char* Contact::getAddress()
{
	return address;
}

void Contact::setAddress(char* address)
{
	this->address = address;
}

char* Contact::getPhone()
{
	return phone;
}

void Contact::setPhone(char* phone)
{
	this->phone = phone;
}

char* Contact::getEmail()
{
	return email;
}

void Contact::setEmail(char* email)
{
	this->email = email;
}