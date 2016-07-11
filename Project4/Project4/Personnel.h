//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Personnel.h
//******************************************************************************
#ifndef PERSONNEL_H
#define	PERSONNEL_H

#include <iostream>
#include "Contact.h"

using namespace std;

class Personnel
{
public:
	Personnel(char* name, char* birthday, char* address, char* phone, char* email);
	~Personnel();

	virtual char* getName();
	virtual void setName(char* name);
	virtual char* getBirthday();
	virtual void setBirthday(char* birthday);
	virtual int getId();
	virtual void setId(int id);
	virtual ContactPointer getContact();
	virtual void setContact(ContactPointer contact);
	virtual void display();

protected:
	ContactPointer contact;

private:
	char* name;
	int id;
	char* birthday;
	static int lastId;
};


typedef Personnel* PersonnelPointer;
#endif	/* PERSONNEL_H */

