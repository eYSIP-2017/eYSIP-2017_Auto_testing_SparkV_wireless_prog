/*
This main function was written inorder to understand how the main function of a given embedded C program should be tested 
*/

#include <stdio.h>
#include "Arithmetic_Header.h"

int main(void)
{
        int x, y;

        printf("Enter two integers: ");
        scanf("%i %i", &x, &y);

        //int sum = add(x, y);
        //printf("The sum of %i and %i is %i\n", x, y, sum);

        //int cube1 = cube(x);
	//int cube2= cube(y);
        //printf("The cube of the entered numbers are %i and %i\n", cube1, cube2);

	int factorial1 = factorial(x);
	int factorial2 = factorial(y);
	printf("The factorial of the entered numbers are %i and %i\n", factorial1, factorial2);
        int GCD1 = GCD(x,y);
        printf("The GCD of the two numbers is: %i\n",GCD1 );
        return 0;
}
