/*
* Filename: Experiment-2
* Description: This experiment is a part of Task 2. It is aimed at getting you familiar with I/O interfacing by writing a code to sense pressing of a push button switch.
* Author: e-Yantra Team
* Functions: main(),port_init(),led_on(),led_off().
*/

//TeamID.112312


// Note : You may write more functions depending on requirement.


//#define __OPTIMIZE__ -O1
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
	DDRJ = DDRJ | 0xF0;
	DDRE = DDRE & 0x7F;
	PORTJ = PORTJ | 0xF0;
        PORTE = PORTE | 0x80;

}
/*Function name: led_on
Input: none
Output: none
Logic: Code to turn on bar led
*/
void led_on(void)
{
	if(PE7 == (PINE | 0x80))
	{
	 PORTJ = PORTJ | 0xF0;
	 }
}

/*Function name: led_off
Input: none
Output: none
Logic: Code to turn off bar led
*/


/*Function name: main
Input: none
Output: none
Logic: Program Execution starts from this function. Your code can have only one main function.
*/
void led_off(void)
{
}

int main()
{
	port_init();
        while(1)
        {
         led_on();
        }
}
