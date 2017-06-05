//This is a program to controll the motors on the FireBird V. This is to be considered as an assignment and Tested using UNITY and CMOCK
#include </usr/lib/avr/include/avr/io.h>
#include </usr/lib/avr/include/avr/interrupt.h>
#define F_CPU 14745600UL
#include <stdio.h>
#include </usr/lib/avr/include/util/delay.h>

void motion_pin_config (void)
{
 DDRA = DDRA | 0x0F; //set direction of the PORTA 3 to PORTA 0 pins as output
 PORTA = PORTA & 0xF0; // set initial value of the PORTA 3 to PORTA 0 pins to logic 0
 DDRC = DDRC | 0x18;   //Setting PL3 and PL4 pins as output for PWM generation
 PORTC = PORTC | 0x18; //PL3 and PL4 pins are for velocity control using PWM
}

//Function to initialize ports
void port_init()
{
 motion_pin_config();
}


//Function used for setting motor's direction
void motion_set (unsigned char Direction)
{
 unsigned char PortARestore = 0;

 Direction &= 0x0F; 			// removing upper nibbel as it is not needed
 PortARestore = PORTA; 			// reading the PORTA's original status
 PortARestore &= 0xF0; 			// setting lower direction nibbel to 0
 PortARestore |= Direction; 	// adding lower nibbel for direction command and restoring the PORTA status
 PORTA = PortARestore; 
 			// setting the command to the port
}


void forward (void) //both wheels forward
{
  motion_set(0x06);
}

void back (void) //both wheels backward
{
  motion_set(0x09);
}

void left (void) //Left wheel backward, Right wheel forward
{
  motion_set(0x05);
}

void right (void) //Left wheel forward, Right wheel backward
{
  motion_set(0x0A);
}

void soft_left (void) //Left wheel stationary, Right wheel forward
{
 motion_set(0x04);
}

void soft_right (void) //Left wheel forward, Right wheel is stationary
{
 motion_set(0x02);
}

void soft_left_2 (void) //Left wheel backward, right wheel stationary
{
 motion_set(0x01);
}

void soft_right_2 (void) //Left wheel stationary, Right wheel backward
{
 motion_set(0x08);
}

void stop (void) //hard stop
{
  motion_set(0x00);
}

void init_devices (void)
{
 //cli(); Clears the global interrupts
 port_init();
 //sei(); Enables the global interrupts
}


//Main Function
int main()
{
	init_devices();
		
	while(1)
	{
	
		forward(); //both wheels forward
		_delay_ms(1000);

		stop();						
		_delay_ms(500);
	
		back(); //bpth wheels backward						
		_delay_ms(1000);

		stop();						
		_delay_ms(500);
		
		left(); //Left wheel backward, Right wheel forward
		_delay_ms(1000);
		
		stop();						
		_delay_ms(500);
		
		right(); //Left wheel forward, Right wheel backward
		_delay_ms(1000);

		stop();						
		_delay_ms(500);

		soft_left(); //Left wheel stationary, Right wheel forward
		_delay_ms(1000);
		
		stop();						
		_delay_ms(500);

		soft_right(); //Left wheel forward, Right wheel is stationary
		_delay_ms(1000);

		stop();						
		_delay_ms(500);

		soft_left_2(); //Left wheel backward, right wheel stationary
		_delay_ms(1000);

		stop();						
		_delay_ms(500);

		soft_right_2(); //Left wheel stationary, Right wheel backward
		_delay_ms(1000);

		stop();						
		_delay_ms(1000);
	}
}
