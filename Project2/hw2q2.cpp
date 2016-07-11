//***************************************************************************
//	Description:	Problem 2 - Modified the correct program that we obtained
//					      in Problem 1.  Change <stdio.h> to <iostream>. Change
//					      printf to cout, and change scanf to cin, etc.
//***************************************************************************
#include <iostream>
using namespace std;
int main()
{
	char ch = '+';											// Sets ch = to '+'
	int f, a=10, b=20;										// Initializes Variables
	cout << "ch = " << ch << endl;							// Prints the current value of ch
	switch (ch)												// Switch Statement w/ breaks
	{
		case '+': f = a + b; break;							// Switch statement sets f = to appropriate value based on ch
		case '-': f = a - b; break;
		case '*': f = a * b; break;
		case '/': f = a / b; break;
		default: cout <<"invalid operator" << endl;
	}
	cout <<"f = " << (int) f << endl;						// Prints the vurrent value of f

	ch = '-';												// Sets ch = to '-'
	cout << "ch = " << ch << endl;							// Prints the current value of ch
	switch (ch)												// Switch Statement w/ breaks
	{
		case '+': f = a + b; break;							// Switch statement sets f = to appropriate value based on ch
		case '-': f = a - b; break;
		case '*': f = a * b; break;
		case '/': f = a / b; break;
		default: cout <<"invalid operator" << endl;
	}
	cout <<"f = " << (int) f << endl;						// Prints the vurrent value of f

	ch = '*';												// Sets ch = to '*'
	cout << "ch = " << ch << endl;							// Prints the current value of ch
	switch (ch)												// Switch Statement w/ breaks
	{
		case '+': f = a + b; break;							// Switch statement sets f = to appropriate value based on ch
		case '-': f = a - b; break;
		case '*': f = a * b; break;
		case '/': f = a / b; break;
		default: cout <<"invalid operator" << endl;
	}
	cout <<"f = " << (int) f << endl;						// Prints the vurrent value of f

	ch = '/';												// Sets ch = to '/'
	cout << "ch = " << ch << endl;							// Prints the current value of ch
	switch (ch)												// Switch Statement w/ breaks
	{
		case '+': f = a + b; break;							// Switch statement sets f = to appropriate value based on ch
		case '-': f = a - b; break;
		case '*': f = a * b; break;
		case '/': f = a / b; break;
		default: cout <<"invalid operator" << endl;
	}
	cout <<"f = " << (int) f << endl;						// Prints the vurrent value of f
}
