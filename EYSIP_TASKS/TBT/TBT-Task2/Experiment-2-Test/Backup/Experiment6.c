/*
* Filename: Experiment-2
* Description: This experiment is a part of Task 2. It is aimed at getting you familiar with I/O interfacing by writing a code to sense pressing of a push button switch.
* Author: e-Yantra Team
* Functions: main(),port_init(),led_on(),led_off().
*/

//TeamID.02934

// Note : You may write more functions depending on requirement.



#include </usr/lib/avr/include/avr/io.h>
#include <stdio.h>
#define F_CPU 14745600



/*Function name: port_init
Input: none
Output: none
Logic: Code to initialize desired I/O ports
*/

void port_init(void)
{
DDRJ=0xFF;
DDRE=0x7F;
PORTE=0x80;

}
/*Function name: led_on
Input: none
Output: none
Logic: Code to turn on bar led
*/
void led_on(void)
{
PORTJ=0xF0;
}

/*Function name: led_off
Input: none
Output: none
Logic: Code to turn off bar led
*/
void led_off(void)
{
		PORTJ=0x00;
}

/*Function name: main
Input: none
Output: none
Logic: Program Execution starts from this function. Your code can have only one main function.
*/

int main()
{
		while(1)
	{
	

		if((PINE & 0x80) == 0x80) //switch is not pressed

		{
		led_off();
		}
		else
		{
		led_on();
	
		}
	}	
}
