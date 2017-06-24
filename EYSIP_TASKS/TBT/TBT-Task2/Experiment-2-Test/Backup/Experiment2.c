/*
* Filename: Experiment-2
* Description: This experiment is a part of Task 2. It is aimed at getting you familiar with I/O interfacing by writing a code to sense pressing of a push button switch.
* Author: e-Yantra Team
* Functions: main(),port_init(),led_on(),led_off().
*/
//TeamID.13123


// Note : You may write more functions depending on requirement.



#include </usr/lib/avr/include/avr/io.h>
#include <stdio.h>
#define F_CPU 14745600
//#include <util/delay.h>


/*Function name: port_init
Input: none
Output: none
Logic: Code to initialize desired I/O ports
*/

void port_init(void)
{
	// write your code here
DDRE= DDRE & 0X7F; // pin 7 is set as i/p pin i.e pin 7 is "0" and remaing all pins unchanged
PORTE= 0X80;   // to activate pullup at pin 7 of port E (i/p pin)
DDRJ= DDRJ | 0XFF; //PORTJ Upper nibble o/p
PORTJ= PORTJ & 0X0F;  // Clear upper nibble of PORTJ
}
/*Function name: led_on
Input: none
Output: none
Logic: Code to turn on bar led
*/
void led_on(void)
{

PORTJ= PORTJ | 0XF0; // Turn ON upper nibble
	//write your code here
}

/*Function name: led_off
Input: none
Output: none
Logic: Code to turn off bar led
*/
void led_off(void)
{
PORTJ =PORTJ & 0X0F;  // Turn OFF upper nibble
	// write your code here
}

/*Function name: main
Input: none
Output: none
Logic: Program Execution starts from this function. Your code can have only one main function.
*/

int main()
{
int X=0;
while (1)
{
port_init();
X = PINE;
if(X==0X00)   // Check whether buttonis pressed ie. if pressed zero in PORTE.7
{
led_on();

}
else if(X==0X80)    // Check whether buttonis released ie. if released ONE in PORTE.7
{
led_off();
}
}
	//write your code here
}
