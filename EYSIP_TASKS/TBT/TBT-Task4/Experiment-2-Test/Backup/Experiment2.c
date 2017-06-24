
/*
* File name: Experiment-2
* Description: This experiment is a part of Task 4. It is aimed to get you familiar with internal Timer module of Atmega2560.
* This experiment involves writing code to indicate the corresponding value of a counter on Bargraph LED that counts from "0" to "8"
* with a delay of 1 second between successive numbers. 
* This delay has to be generated using Timer 1 of Atmega 2560.
* Author: e-Yantra Team
*/

/* Buzzer Connections
		
	Buzzer control pin is connected to PC3 of microcontroller.
*/

/* Bargraph LED Connections
	
	The Bargraph LEDs are connected to PORT J of microcontroller.
	Note: There are 10 LEDs in the Bargraph, Only 8 are connected and the remaining 2 are not connected.
*/
	
//TeamID.1234


#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

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
	DDRC = 0xFF;  //Set all the pins of PORTC as output i.e. including the 4 data pins, 3 control pins of LCD and 1 pin (PC3) for buzzer control
	PORTC = 0x00; //Set all the pins to logic "0" initially.
	DDRJ = 0xFF;//Set all the pins of PORTJ as output 
	PORTJ =0x00; //Set all the pins to logic "0" initially.
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
	PORTC= 0x08;          //  Set PC3 to "1", making sure that other port pin values are unaffected.
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
   PORTC= 0xF7;     // Set PC3 to "0", making sure that other port pin values are unaffected.
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
	TCCR1A = 0x00;	 	 // Timer 1 mode selection
	TCCR1B = 0x00;	 	 //Timer 1 mode selection, prescalar selection
	TCNT1H = 0x1F;  	 //Counter higher 8 bit value
	TCNT1L = 0x01;	 	 //Counter lower 8 bit value
	TCCR1B = 0x04;	 	 //start Timer
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
	TCNT1H = 0x38;		//reload counter high value, for exactly 1 second at prescale:1024 & Frequency 14.745600MHz
	TCNT1L = 0x3F;  	//reload counter low value, for exactly 1 second at prescale:1024 & Frequency 14.745600MHz
	counter ++;     // increment counter variable every time, the overflow occurs .
	
	PORTJ = 2*PORTJ + 2;// Since Bar graph must have inputs as 0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F & 0xFF
						// To do so PORTJ value must be multiplied by 2 and added to 1 to get desired output
						//    at every 1 seconds delay
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
	PORTJ = 0x01;		// Initializing initial value of PORTJ with 0x01 to glow Bargraph LED 1

	while(1)
	{
		
		// Write program code to check whether counter varible has reached 8, if yes turn off timer and the corresponding interrupt.
		// Turn on the buzzer for 1 second to indicate end of the count. 
		// You can use function in delay.h for buzzer on time after counting upto 8.
		if(counter ==8)			// To check whether counter reaches to 8
		{
			TIMSK1 = 0x00;		// Timer is turned off
			_delay_ms(1000);
			buzzer_on();		// Buzzer is ON for 1 second delay
			_delay_ms(1000);
			buzzer_off();				// Buzzer is OFF after program
			_delay_ms(1000);
		}

	}
	
	

				
}
