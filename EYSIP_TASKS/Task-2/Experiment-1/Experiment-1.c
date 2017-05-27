/*
* Filename: Experiment-1 
* Description: This experiment is part of Task 1. It is aimed to get you familiar with the AVR Studio 4.17 IDE. This experiment will help you get familiar with 
debugging techniques. You will be able to locate error in code and remove it to generate effective code
* Author: e-Yantra Team
* Functions: main()
*/

/*
* Preprocessor declarations
*/

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 8000000UL
#include <util/delay.h>

// variable declarations
int i,
k;
float j;
char value;


/*
Function Name: main
Input: none
Output: none
Logic: Program Execution starts from this function. Your code can have only one main function.
*/

// Make changes in the code to remove all the errors/warnings. You cannot delete any statement or part of this code to remove an error/warning.
int main()
{
	_delay_ms(100);
	value='a';
	i=0;
	j=0;
	for(i=0;i<45;i++)
	{
		value++;
	}
	
	while(j<=100)
	{
		value+-1;
		j=j+1;
	}
}


	


