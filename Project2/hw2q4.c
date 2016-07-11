//***************************************************************************

//	Description:	Problem 4 - Wrote a C program based on the provided
//					      algorithm.  This program takes an integer as input and
//					      then applies it to a while loop.  If the integer is even
//					      the while loop divides it by 2.  If the integer is odd
//					      then the while loop multiplies by 3 and adds 1.  This
//					      program outputs the n value for every iteration, the
//					      count, the time that the while loop took to complete in
//					      seconds and the number of ticks that the while loop took
//					      to complete.
//***************************************************************************
#include <stdio.h>
#include <time.h>
void timestamp()							// Generates a timestamp
{
	time_t now;								// Instantiates necessary values using time_t
	struct tm* now_info;
	time(&now);
	now_info = localtime(&now);
	printf("%s", asctime(now_info));		// Prints timestamp
}

void output(int n, int c)					// Output method takes int n, int c as parameters
{
	printf ("n = %d\n", n);					// Prints the value of n
	printf ("count = %d\n", c);				// Prints the value of c


	timestamp();							// Calls timestamp method
}

void termination(int n)						// Termination method takes int n as parameter
{
	int c = 0;								// Instantiates int c = 0
	clock_t t;								// Instantiates variable t of type clock
	float seconds;							// Declares seconds of type float

	t = clock();							// Sets variable t = to current clock value in ticks
	while (n != 1)							// While loop that iterates while n != 1
	{										// If n is even the while loop divides by 2
		if (n % 2 == 0)						// If n is odd the while loop performs ((3*n)+1)
		{									// While loop increments c (count) after every iteration
			n = (n/2);						// While loop prints current value of n after every iteration
		}
		else
		{
			n = ((3 * n) + 1);
		}
		c++;
		printf ("n = %d\n", n);
	}
	t = clock()-t;							// Sets t = to current value of clock()-t (this determines how long the while loop took to complete in ticks)
	seconds = ((float)t/CLOCKS_PER_SEC);	// Sets seconds = to current value of t cast to float and divided by the system constant CLOCKS_PER_SEC



	printf ("Time to run while loop in seconds = %f \n", seconds);										// Print the results in seconds
	printf ("Time to run while loop in number of clocks = %f \n", (float)CLOCKS_PER_SEC*seconds);		// Print the results in ticks
	output(n, c);

}

int main()
{
	int n;									// Declares int n variable

	scanf ("%d", &n);						// Takes integer input from user
	timestamp();							// calls timestamp function at the end of program

	termination(n);							// calles termination method with value n
}
