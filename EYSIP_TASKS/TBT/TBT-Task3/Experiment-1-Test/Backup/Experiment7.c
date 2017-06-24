/*
* File name: Experiment-1
* Description: This experiment is a part of Task 4. It is aimed to get you familiar with internal Timer module of Atmega2560.
* This experiment involves writing a code to display a counter that counts from "0" to "10" with a dealy of 1 second. 
  This delay has to be generated using Timer 1 of Atmega 2560.
  Author: e-Yantra Team
*/

//TeamID.314

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
#include "lcd.h"    // A header file which contains all the essential functions defined to display data on the LCD. For more details refer to the "Readme" file.

volatile unsigned int counter=0; // A global variable to act as a counter


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
	DDRC = 0xFF; //Set all the pins of PORTC as output i.e. including the 4 data pins, 3 control pins of LCD and 1 pin (PC3) for buzzer control
	PORTC = 0x00; //Set all the pins to logic "0" initially.
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
	PORTC=  PORTC | 0x08;        //  Set PC3 to "1", making sure that other port pin values are unaffected.
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
   //PORTC=0x00;
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
	TCCR1A = 0x00;	 // Timer 1 mode selection
	TCCR1B = 0x00;	 //Timer 1 mode selection, prescalar selection
	TCNT1H = 0x1F; 	 //Counter higher 8 bit value
	TCNT1L = 0x01;	 //Counter lower 8 bit value
	TCCR1B = 0x04;	 //start Timer
}


/*
* Function Name: Interrupt Service Routine (ISR)
* Input: none
* Output: none
* Logic: Code to initialize timer 1 i.e. setting the count value, defining the mode of operation etc. 
  Note : ISR is not a callable function, the execution jumps directly to the ISR whenever an interrupt occurs.
*/


ISR(TIMER1_OVF_vect)
{
	//TIMER1 has overflowed
	TCNT1H = 0x1F;	//reload counter high value
	TCNT1L = 0x01; 	//reload counter low value
	counter++;     // increment counter variable every time, the overflow occurs
	
	lcd_print(2,1,counter,2); // This function is defined in the header file "lcd.h". 
				   //Provide appropriate arguments to display counter value on 2nd row 1st column of LCD.

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
	lcd_init();              // function is defined in the header file "lcd.h"
	lcd_string("Counter");   // function is defined in the header file "lcd.h
	timer1_init();
	lcd_print(2,1,0,2);   // display initial value of the counter varialbe by providing appropriate arguments to this function.

	while(1)
	{
		
		if(counter>=10)
		{
			TCCR1B=0x00;
			TIMSK1 = 0x00;
			buzzer_on();
			_delay_ms(1000);
			buzzer_off();
			counter=0;

		}
	
		
		// Write program code to check whether counter varible has reached 10, if yes turn off timer and the corresponding interrupt.
		// Turn on the buzzer for 1 second to indicate end of the count. 
		//You can use function in delay.h for buzzer on time.
		

	}


				
}
