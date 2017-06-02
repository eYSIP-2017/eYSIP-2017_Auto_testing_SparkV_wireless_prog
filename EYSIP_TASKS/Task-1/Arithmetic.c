/*
A simple functions written to familiarize myself with C programing 
*/
#include <stdio.h>

int add(int a, int b)
{

return a+b;

}

int cube(int c)
{

  return c*c*c;

}

int factorial(int n)
{
    if (n >= 1)
        return n*factorial(n-1);
    else
        return 1;
}

int GCD(int a, int b)
{
    int n1 = a;
    int n2 = b;
 
    if((n1== 0)|(n2 == 0))   
      {
        //printf("GCD of the two numbers does not exist\n ");
        return 9000;
      }
    else
      {
    	n1 = ( n1 > 0) ? n1 : -n1;
    	n2 = ( n2 > 0) ? n2 : -n2;


    	while(n1!=n2)
    	 {
           if(n1 > n2)
             n1 -= n2;
           else
             n2 -= n1;
         }
       }
    return n1;
}
