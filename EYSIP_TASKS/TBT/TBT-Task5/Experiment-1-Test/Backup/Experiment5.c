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

//TeamID.237

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
 DDRA = 0x0F;	//set direction of the PORTA pins (PA3-PA0) as output
 PORTA = 0x00;   // set initial value of the PORTA pins (PA3-PA0) to logic 0
 DDRL = 0x18;  	//Setting PL3 and PL4 pins as output for PWM generation
 PORTL =0x18;  	//PL3 and PL4 pins are used for velocity control using PWM
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
  PORTA= 0x06;  // Write sutiable value in PORTA to set direction of both wheels as forward.
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
 PORTA= 0x05;    //Write suitable value in PORTA register to rotate Left wheel backward and Right wheel forward
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
  PORTA= 0x0A; 	//Write suitable value in PORTA register to rotate Left wheel forward and Right wheel backward
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
  PORTA= 0x00;	//Write suitable value in PORTA register to stop the robot.
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
	/***********************************************************************
				WRITE YOUR CODE HERE. Please write inline comments. 

	************************************************************************/
	forward ();
	_delay_ms(2500);
	//stop();
	_delay_ms(1000);	
	left();
	_delay_ms(500);
	//stop();
	_delay_ms(1000);
	forward ();
	_delay_ms(5000);
	//stop();
	//_delay_ms(1000);
	left();
	_delay_ms(500);
	//stop();
	_delay_ms(1000);
	_delay_ms(1000);
	forward ();
	_delay_ms(2500);
	//stop();


}
//Main Function
int main()
{
	motion_pin_config();
		
	// sample function call
	create_shape();
}

