#include <stdio.h>
#include <stdint.h>
#ifndef TEST
#include </usr/lib/avr/include/avr/io.h>
#define F_CPU 14745600UL
#include "Ex.h"


//Function to configure LED port
void Bar_LED_Config(void)
{
 DDRJ = DDRJ | 0xFF; //all the LCD pin's direction set as output
 PORTJ = PORTJ | 0xFA; // all the LCD pins are set to logic 0 except PORTC 7
}

void disable_Bar_LED()
{
DDRJ = DDRJ & 0x00;
PORTJ = PORTJ & 0x00;
}

//Function to Initialize PORTS
void port_init()
{
	Bar_LED_Config();
}

//Function to clear the BAR LED
void clear()
{
 PORTJ = PORTJ & 0x00;
}

//Function to set the BAR LED to a specfied configuration
void Set_LED(int x)
{
clear();
PORTJ = PORTJ | x;
}

#ifndef TEST
int main()
{
 port_init();

 _delay_ms(3000);

 clear();

 Set_LED(0x64);

 _delay_ms(3000);

 disable_Bar_LED();
}
#endif 

