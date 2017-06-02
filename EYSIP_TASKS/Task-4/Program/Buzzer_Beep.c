#include </usr/lib/avr/include/avr/io.h> //absolute path must be specified as their is no relative path between the files
#include </usr/lib/avr/include/avr/interrupt.h>
#define F_CPU 14745600UL
#include </usr/lib/avr/include/util/delay.h>
#include <stdio.h>

//Function to initialize Buzzer 
void buzzer_pin_config (void)
{
 DDRC = DDRC | 0x08;		//Setting PORTC 3 as output
 PORTC = PORTC & 0xF7;		//Setting PORTC 3 logic low to turnoff buzzer
}

void port_init (void)
{
 buzzer_pin_config();
}

void buzzer_on (void)
{
 unsigned char port_restore = 0;
 port_restore = PINC;
 port_restore = port_restore | 0x08;
 PORTC = port_restore;
}

void buzzer_off (void)
{
 unsigned char port_restore = 0;
 port_restore = PINC;
 port_restore = port_restore & 0xF7;
 PORTC = port_restore;
}

void init_devices (void)
{
 //cli(); //Clears the global interrupts
 port_init();
 //sei(); //Enables the global interrupts
}

//Main Function
int main()
{
	init_devices();
	while(1)
	  {	
	        buzzer_on();
		_delay_ms(1000);
		buzzer_off();
		_delay_ms(1000);
	  }
}



