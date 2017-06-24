
/*
* File name: Experiment-1
* Description: This experiment is a part of Task 4. It is aimed to get you familiar with internal Timer module of Atmega2560.
* This experiment involves writing code to display a counter that counts from "0" to "10" with a delay of 2 seconds. 
* This delay has to be generated using Timer 1 of Atmega 2560.
* Author: e-Yantra Team
*/

//TeamID.2342

/* LCD Connections

		  	 LCD	 Microcontroller Pins
 			  RS  --> PC0
			  RW  --> PC1
			  EN  --> PC2
			  DB7 --> PC7
			  DB6 --> PC6
			  DB5 --> PC5
			  DB4 --> PC4
*/
/* Buzzer Connections
		
	Buzzer control pin is connected to PC3 of microcontroller.
*/



#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "delay_new.h"    // A header file which contains the essential functions defined to create a given delay. For more details refer to the "Readme" file.

volatile unsigned int counter=0; 

/*
* Function Name: port_init 
* Input: none
* Output: none
* Logic: Code to initialize desired I/O port using IO port registers 
		 viz. DDRx and PORTx.
Example Call:port_init().
*/

void port_init(void)
{
	DDRC = 0xFF;  //4th pin (PC3) as output for buzzer control.
	PORTC = 0x00; //Set all the pins to logic "0" initially.
	DDRJ = 0xFF;  //Set all the pins of PORTJ as output
	PORTJ = 0x00; //Set all the pins to logic "0" initially.
}

/*
* Function Name: buzzer_on
* Input: none
* Output: none
* Logic: Code to turn on the buzzer connected to 4th pin of PORTC(PC3).
Example Call:buzzer_on()
*/
void buzzer_on (void)
{
	PORTC= PORTC | 0x08;        //  Set PC3 to "1", making sure that other port pin values are unaffected.
}


/*
* Function Name: buzzer_off
* Input: none
* Output: none
* Logic: Code to turn off the buzzer connected to 4th pin of PORTC(PC3).
Example Call:buzzer_on()
*/
void buzzer_off (void)
{
   PORTC= PORTC & 0xF7;     // Set PC3 to "0", making sure that other port pin values are unaffected.
}

/*
* Function Name: timer1_init
* Input: none
* Output: none
* Logic: Code to initialize timer 1 i.e. setting the count value, defining the mode of operation etc.
Example Call:timer1_init()
*/

void timer1_init(void)
{
	TCCR1A = 0x00;	 // Timer 1 mode selection (Use Normal mode)
	TCCR1B = 0x00;	 //Timer 1 mode selection
	TCNT1H = 0x00; 	 //Counter higher 8 bit value
	TCNT1L = 0x00;	 //Counter lower 8 bit value
	TCCR1B = 0x04;	 //start Timer by selecting prescalar (avoid overwriting mode selection bits)
}


/*
* Function Name: Interrupt Service Routine (ISR)
* Input: none
* Output: none
* Logic: Code reload the count value and display appropriate integer on the lcd etc. 
  Note : ISR is not a callable function, the execution jumps directly to the ISR whenever an interrupt occurs.
*/


ISR(TIMER1_OVF_vect)
{
	int w=1;
}

/*
* Function Name: interrupt_init
* Input: none
* Output: none
* Logic: Code to enable interrupt for Timer 1
  Example call: interrupt_init()
*/
void interrupt_init()
{
	cli();    //Clears the global interrupts
	
	TIMSK1 = 0x01;  //TIMER 1 overflow interrupt enable
	
	sei();   //Enables the global interrupts
}



int main(void)
{
	port_init();      
	interrupt_init();
	timer1_init();
	
	while(1)
	{
		PORTJ = 0x01;
		for(int j=1; j<=3; j++)
		{
			delay_new_ms(j*1000);
			PORTJ = 2*PORTJ + 1;
		}
		for(int j=2; j>=1; j--)
		{
			delay_new_ms(j*1000);
			PORTJ = 2*PORTJ + 1;
		}
		
		buzzer_on();
		delay_new_ms(2000);
		buzzer_off();
		/*Start with First LED at glowing state and the glow the Second LED after 1 sec delay
		then glow third LED after 2 sec then fourth LED after 3 sec then fifth LED after 2 sec and finally sixth LED after 1 sec.*/
		// Turn on the buzzer for 2 second to indicate end of the run. 
		// You have to use only delay_new_ms() for producing the delay i.e. you can not use _delay_ms().

	}
	

				
}
