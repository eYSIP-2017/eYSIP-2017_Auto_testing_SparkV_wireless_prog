/*
* Filename: Experiment-2
* Description: This experiment is a part of Task 2. It is aimed at getting you familiar with I/O interfacing by writing a code to sense pressing of a push button switch.
* Author: e-Yantra Team
* Functions: main(),port_init(),led_on(),led_off().
*/

//TeamID.13
// Note : You may write more functions depending on requirement.



#include </usr/lib/avr/include/avr/io.h>
#include <stdio.h>
#define F_CPU 14745600UL
//#include <util/delay.h>


/*Function name: port_init
Input: none
Output: none
Logic: Code to initialize desired I/O ports
*/

void port_init(void)
{
	DDRJ = 0xFF;
	PORTJ = 0x00;

}
/*Function name: led_on
Input: none
Output: none
Logic: Code to turn on bar led
*/
void led_on(void)
{
	PORTJ = 0xF0;
}

/*Function name: led_off
Input: none
Output: none
Logic: Code to turn off bar led
*/
void led_off(void)
{
	PORTJ = 0x00;
}

/*Function name: main
Input: none
Output: none
Logic: Program Execution starts from this function. Your code can have only one main function.
*/

int main()
{
	port_init();
	while(1)
	{
// Code 1 for PINE comparison
	if((PINE & 0x80) == 0x80) //switch is not pressed
		{
			led_off(); //Turn off 4 upper nibble bargraph LEDs			
		}
	else
		{
			led_on(); //Turn on 4 upper nibble bargraph LEDs
		}
		
/* Code 2 for PINE comparison		
		if(PINE >= 0x00 && PINE <=0x7F)
		{
		led_on();						//PINE(8) = 0 
		}
		else
		if(PINE >=0x80 && PINE <=0xFF)
		{
		led_off();							//PINE(8) = 1 
		}
*/
	}
}
