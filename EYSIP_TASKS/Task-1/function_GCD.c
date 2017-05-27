#include <stdio.h>
int GCD(int c, int b)
{
    int n1 = c;
    int n2 = b;
 
    if(n1== 0 | n2 == 0)   
      {
        printf("GCD of the two numbers does not exist ");
        return 9000;
      }
    else
      {
    	printf("Enter two integers: ");
    	scanf("%d %d",&n1,&n2);

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
