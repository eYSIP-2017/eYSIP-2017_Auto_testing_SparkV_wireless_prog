/*
* Filename: Experiment-1
* Description: This experiment is a part of Task 2. It is aimed at getting you familiar with I/O interfacing by writing a code to alternately blink a set of LEDs.
 Bar graph LED, present on Firebird-V robot, is an array of 10 LEDs present on a single module. 8 LEDs are connected to PortJ of Atmegs2560 microcontroller. 
 Purpose of this experiment is to turn on/off upper 4 LEDs and bottom 4 LEDs alternately with a delay of 1 second.

* 
Author: e-Yantra Team
* Functions: main(),port_init(),led_on_topfour(),led_off_topfour(),led_on_bottomfour(),led_off_bottomfour().
*/

/*
* Preprocessor declarations
*/

// TeamID.356

#include </usr/lib/avr/include/avr/io.h>
#include <stdio.h>
#define F_CPU 14745600
#include <util/delay.h>


/* 
Function name: port_init
Input: none
Output: none
Logic: Code to initialize desired I/O port using IO port registers viz. DDRx and PORTx
Example Call: port_init(); 
*/

void port_init(void)
{
	DDRJ = 0xFF;					// DDRJ register is used to initialize PortJ as output port. 
						    //All 8 pins of PortJ is connected to 8 LEDs of Bar graph LED module. 
							//Write suitable value to ensure all 8 LEDs of Bar LED can be used.  
	
	PORTJ = 0x00;			// PORTJ register is used to turn on/off output device. 
	                         //Write suitable value to ensure all 8 LEDs of Bar LED is turned off at the start.  

}
	
/* 
Function names: led_on_topfour
Input: none
Output: none
Logic: Code to turn on four LEDs of bar graph LED module, connected to upper nibble. You can use PORTJ register for this purpose.
Example Call: led_on_topfour(); 
*/

void led_on_topfour(void)
{
  PORTJ = 0xF0;
  _delay_ms(1000);
//write your code here

}

/* 
Function names: led_off_topfour
Input: none
Output: none
Logic: Code to turn off four LEDs of bar graph LED module, connected to upper nibble. You can use PORTJ register for this purpose.
Example Call: led_off_topfour(); 
*/

void led_off_topfour(void)
{
  PORTJ = 0x00;
}

/* 
Function names: led_on_bottomfour
Input: none
Output: none
Logic: Code to turn on four LEDs of bar graph LED module, connected to lower nibble. You can use PORTJ register for this purpose.
Example Call: led_on_bottom four(); 
*/

void led_on_bottomfour(void)
{
 PORTJ = 0x0F;
 _delay_ms(1000);
}


void led_off_bottomfour(void)
{
}


/* 
Function names: led_off_bottomfour
Input: none
Output: none
Logic: Code to turn off four LEDs of bar graph LED module, connected to lower nibble. You can use PORTJ register for this purpose.
Example Call: led_off_bottomfour(); 
*/
/*
Function Name: main
Input: none
Output: none
Logic: Program Execution starts from this function. Your code can have only one main function. 
Use functions defined above to turn on/off upper 4 LEDs and bottom 4 LEDs alternately with a delay of 1 second. 
*/

int main()
{
    while(1)
	{
	 port_init();
	 led_on_topfour();
	 led_off_topfour();
	 led_on_bottomfour();
	 led_off_topfour();
	}
}
