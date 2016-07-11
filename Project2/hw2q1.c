//***************************************************************************
//	Description:	Problem 1 - Corrected the code that was provided
//	              Demonstrates switch statement using breaks
//***************************************************************************

#include <stdio.h>
void main()
{
	char ch = '+';									// Sets ch = to '+'
	int f, a=10, b=20;								// Initializes Variables
	printf("ch = %c\n", ch);						// Prints the current value of ch
	switch (ch)										// Switch Statement w/ breaks
	{
		case '+': f = a + b; break;					// Switch statement sets f = to appropriate value based on ch
		case '-': f = a - b; break;
		case '*': f = a * b; break;
		case '/': f = a / b; break;
		default: printf("invalid operator\n");
	}
	printf("f = %d\n", f);							// Prints the vurrent value of f

	ch = '-';										// Sets ch = to '-'
	printf("ch = %c\n", ch);						// Prints the current value of ch
	switch (ch)										// Switch Statement w/ breaks
	{
		case '+': f = a + b; break;					// Switch statement sets f = to appropriate value based on ch
		case '-': f = a - b; break;
		case '*': f = a * b; break;
		case '/': f = a / b; break;
		default: printf("invalid operator\n");
	}
	printf("f = %d\n", f);

	ch = '*';										// Sets ch = to '*'
	printf("ch = %c\n", ch);						// Prints the current value of ch
	switch (ch)										// Switch Statement w/ breaks
	{
		case '+': f = a + b; break;					// Switch statement sets f = to appropriate value based on ch
		case '-': f = a - b; break;
		case '*': f = a * b; break;
		case '/': f = a / b; break;
		default: printf("invalid operator\n");
	}
	printf("f = %d\n", f);							// Prints the vurrent value of f

	ch = '/';										// Sets ch = to '/'
	printf("ch = %c\n", ch);						// Prints the current value of ch
	switch (ch)										// Switch Statement w/ breaks
	{
		case '+': f = a + b; break;					// Switch statement sets f = to appropriate value based on ch
		case '-': f = a - b; break;
		case '*': f = a * b; break;
		case '/': f = a / b; break;
		default: printf("invalid operator\n");
	}
	printf("f = %d\n", f);							// Prints the vurrent value of f
}
