/*
* File name: Experiment-1
* Description: This experiment is a part of Task 5. It is aimed to get you familiar with simple motion control of DC motor.
* This experiment involves writing a code to create a Shape "C" using motion control of DC motor. 
  Author: e-Yantra Team
*/
#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//TeamID.34234


/*
* Function Name: motion_pin_config 
* Input: none
* Output: none
* Logic: Code to initialize desired I/O port using IO port registers 
		 viz. DDRx and PORTx.
Example Call: motion_pin_config () 
*/
void motion_pin_config (void)
{
 DDRA = DDRA | 0x0F;	//set direction of the PORTA pins (PA3-PA0) as output
 PORTA = PORTA & 0xF0;    // set initial value of the PORTA pins (PA3-PA0) to logic 0
 DDRL =  DDRL | 0x18; 	//Setting PL3 and PL4 pins as output for PWM generation
 PORTL = PORTL | 0x18; 	//PL3 and PL4 pins are used for velocity control using PWM
}


/*
* Function Name: forward 
* Input: none
* Output: none
* Logic: Code used for setting motor's direction 
		 viz.PORTx.
Example Call: forward()
*/
void forward (void) //both wheels forward
{
  PORTA= (PORTA & 0xF0) | 0x06;

  // Write sutiable value in PORTA to set direction of both wheels as forward.
}
/*
* Function Name: left 
* Input: none
* Output: none
* Logic: Code used for setting motor's direction 
		 viz.PORTx.
Example Call: left()
*/
void left (void) 
{
 PORTA= (PORTA & 0xF0) | 0x05;
    //Write suitable value in PORTA register to rotate Left wheel backward and Right wheel forward
}
/*
* Function Name: right 
* Input: none
* Output: none
* Logic: Code used for setting motor's direction 
		 viz.PORTx.
Example Call: right()
*/
void right (void) 
{
  PORTA= (PORTA & 0xF0) | 0x0A;
 	//Write suitable value in PORTA register to rotate Left wheel forward and Right wheel backward
}
/*
* Function Name: stop 
* Input: none
* Output: none
* Logic: Code used for setting motor's direction 
		 viz.PORTx.
Example Call: stop()
*/
void stop (void)
{
  PORTA= PORTA & 0xF0;
	//Write suitable value in PORTA register to stop the robot.
}
/*
* Function Name: create_shape 
* Input: none
* Output: none
* Logic: Code to make the shape"L" 
Example Call: create_shape()
*/
void create_shape()
{
	
	forward();		//start, move forward 
	_delay_ms(3000);
	stop();			//stop after 3secs
	_delay_ms(500);	

	left();			//turn left
	_delay_ms(600);
	stop();
	_delay_ms(500);

	forward();		//again move forwrd
	_delay_ms(3000); // two times the hori length
	_delay_ms(3000);
	stop();			//stop after 6secs
	_delay_ms(500);

	left();			//again turn left
	_delay_ms(600);
	stop();
	_delay_ms(500);

	forward();
	_delay_ms(3000);
	stop();			//stop after 3secs


	/***********************************************************************
				WRITE YOUR CODE HERE. Please write inline comments. 

	************************************************************************/
}
//Main Function
int main()
{
	motion_pin_config();
		
	// sample function call
	create_shape();
}

