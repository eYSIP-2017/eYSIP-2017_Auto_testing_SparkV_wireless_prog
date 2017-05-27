#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 14745600UL
#include <util/delay.h>

void init_ports();

//Function to configure LCD port
void Bar_LED_Config(void)
{
 DDRC = DDRJ | 0xFF; //all the LCD pin's direction set as output
 PORTJ = PORTJ | 0xFA; // all the LCD pins are set to logic 0 except PORTC 7
}

void disable_Bar_LED()
{
DDRC = DDRJ & 0x00;
PORTJ = PORTJ & 0x00;
}

//Function to Initialize PORTS
void port_init()
{
	Bar_LED_Config();
}

void clear()
{
 PORTJ = PORTJ & 0x00;
}

void Set_LED(int x)
{
PORTJ = PORTJ | x;
}

int main()
{
 port_init();

 _delay_ms(3000);

 clear();

 Set_LED(0x64);

 _delay_ms(3000);

 disable_Bar_LED();
}

