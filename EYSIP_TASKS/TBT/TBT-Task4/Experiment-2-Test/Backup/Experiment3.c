
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
	
//TeamID.165


//#define F_CPU 14745600
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
	DDRC =0XFF;  //Set all the pins of PORTC as output i.e. including the 4 data pins, 3 control pins of LCD and 1 pin (PC3) for buzzer control
	PORTC =0X00;  //Set all the pins to logic "0" initially.
	DDRJ =0XFF;//Set all the pins of PORTJ as output 
	PORTJ =0X00; //Set all the pins to logic "0" initially.
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
	PORTC=PORTC|0x08;
          //  Set PC3 to "1", making sure that other port pin values are unaffected.
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
   PORTC=PORTC & 0xf7;
      // Set PC3 to "0", making sure that other port pin values are unaffected.
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
	TCCR1A = 0X00;	 // Timer 1 mode selection
	TCCR1B =0X00;	 //Timer 1 mode selection, prescalar selection
	TCNT1H = 0XFF;	 //Counter higher 8 bit value
	TCNT1L = 0X01;	 //Counter lower 8 bit value
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
	TCNT1H = 0X1F;	//reload counter high value
	TCNT1L = 0X01;	//reload counter low value
	
	
	if(counter==0)
	{
	PORTJ=0X01;
	
	}
	else if(counter==1)
	{
	PORTJ=0X03;
		
	}
	else if(counter == 2)
	{
	PORTJ=0X07;
	
	}
	else if(counter == 3)
	{
	PORTJ=0X0F;
	
	}
   	else if(counter == 4)
	{
	PORTJ=0X1F;
		
	}
	else if(counter == 5)
	{
	PORTJ=0X3F;
		
	}
	else if(counter == 6)
	{
	PORTJ=0X7F;
		
	}
	else if(counter == 7)
	{
	PORTJ=0XFF;
	
	}
	else if(counter == 8)
	{
	buzzer_on();
	
	}
	else
	{
	buzzer_off();

	}
    counter ++;     // increment counter variable every time, the overflow occurs 
 // Set appropriate value to PORTJ using suitable logic to get desired output. 
	
 
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
	
	TIMSK1 = 0X01;  //TIMER 1 overflow interrupt enable
	
	sei();   //Enables the global interrupts
}



int main(void)
{
	port_init();      
	interrupt_init();
	timer1_init();
	

	while(1)
	{
		
	
	  //Code written in ISR(TIMER1_OVF_vect)
}
   	


				
}
