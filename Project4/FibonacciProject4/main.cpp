#include<iostream>
#include<string.h>

using namespace std;

/**
 * Prompts the user for a positive integer for the Fibonacci number they would 
 * like to calculate. This number acts like an index, which starts at 0, for the Fibonacci sequence.
 * @return inputNumber - the number the user inputted
 */
int getInput()
{
	double inputNumber;

	cout << "Please enter a positive, whole number for the Fibonacci number you would like calculated: ";
	cin >> inputNumber;

	return inputNumber;
}

/**
 * Calculates the Fibonacci number related to the positive integer that the user
 * provided.
 * @param index - the index of the Fibonacci number the user wanted calculated
 * @return result - the Fibonacci number the user wanted calculated
 */
int fibonacci(double index)
{
	if (index == 0)
		return 0;
	else if (index == 1 ||index== 2)
		return 1;
	int result = fibonacci(index- 1) + fibonacci(index- 2);

	return result;
}

/**
 * Main function that calls the appropriate functions so the user will be 
 * prompted to enter a positive integer so a Fibonacci number can be calculated.
 * @return 0, to represent the program has completed running. 
 */
int main()
{
	double index = 0;
	double fibonacciNumber;
	int invalidInput;

	do
	{
		invalidInput = 0;
		
		index = getInput();
		
		if (index < 0)
		{
			cout << "Please enter a positive integer." << endl;
			invalidInput = 1;
		}
		
	} while (index < 0);

	fibonacciNumber = fibonacci(index);

	cout << "The Fibonacci number is: " << fibonacciNumber << endl;

	return 0;
}


