//***************************************************************************
//	Description:	Problem 3 - Wrote a C program based on the provided
//					      algorithm.  This program takes an integer as input and
//				        then applies it to a while loop.  If the integer is even
//					      the while loop divides it by 2.  If the integer is odd
//					      then the while loop multiplies by 3 and adds 1.  This
//					      program outputs the final n value (n=1) and the count.
//***************************************************************************
#include <stdio.h>

void output(int n, int c)				// Output method takes int n, int c as parameters
{										// Prints the current values of required variables
	printf ("n = %d\n", n);				// Prints the value of n
	printf ("count = %d\n", c);			// Prints the value of c
}

void termination(int n)					// Termination method takes int n as parameter
{
	int c = 0;							// Instantiates int c = 0

	while (n != 1)						// While loop that iterates while n != 1
	{
		if (n % 2 == 0)					// If n is even the while loop divides by 2
		{
			n = (n/2);
		}
		else
		{
			n = ((3 * n) + 1);			// If n is odd the while loop performs ((3*n)+1)
		}
		c++;							// While loop increments c (count) after every iteration
	}
	output(n, c);						// After whikle loop complete, output(n, c) is called to print
}

int main()
{
	int n;								// Declares int n variable
	scanf ("%d", &n);					// Takes integer input from user
	termination(n);						// calles termination method with value n
}
