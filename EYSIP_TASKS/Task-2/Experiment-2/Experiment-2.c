/*
This Experiment was to write the function to find out wether a number is a multiple of 9 or not. 
The experiment was expanded by incuding LCD.c and displaying the result of the function on the LCD screen on the FireBird V
*/

//#define __OPTIMIZE__ -O0			
#include <stdio.h>
#include <avr/io.h>
#define F_CPU 14745600UL
#include <util/delay.h>
#include <avr/interrupt.h>

int multiple_of3(unsigned int number)

{
  unsigned int result;

  number = ( number > 0) ? number : -number;
  
  if(number % 3 == 0)
   {
    result = 1; 
   }
  else
   {
    result = 0;
   } 
 return result;  
}

int main (void)
{
	init_devices();
	lcd_set_4bit();
	lcd_init();
	int i =0;
	int j =1;
	int result_value=0;
	result_value = multiple_of3(9);
        lcd_print(i, i, result_value, j);
	_delay_ms(1000);
        result_value = multiple_of3(31);
	lcd_print(i, i, result_value, j);
	return 0;
}
