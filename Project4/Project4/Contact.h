//******************************************************************************
// Project:     Project4
// Class:       CSE 220 
// Date:        November 23, 2013 
// File:        Contact.h
//******************************************************************************

#ifndef CONTACT_H
#define	CONTACT_H

class Contact
{
public:
	Contact(char* address, char* phone, char* email);
	~Contact();

	virtual char* getAddress();
	virtual void setAddress(char* address);
	virtual char* getPhone();
	virtual void setPhone(char* phone);
	virtual char* getEmail();
	virtual void setEmail(char* email);

private:
	char* address;
	char* phone;
	char* email;
};

typedef Contact* ContactPointer;

#endif	/* CONTACT_H */