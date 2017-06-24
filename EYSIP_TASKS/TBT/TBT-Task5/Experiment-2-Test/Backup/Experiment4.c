/*
* File name: Experiment-2
* Description: This experiment is a part of Task 5. It is aimed to get you familiar with the pulse width modulation.
* This experiment involves writing a code to decelerate(reduce the speed) of the robot and indicate this on the Bar Graph LEDs.
  Author: e-Yantra Team
*/

//TeamID.324234

#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*
*	Global Variable Declaration
*/
// Declare any global variable if you require here


/*
* Function Name: motion_pin_config 
* Input: none
* Output: none
* Logic: Code to initialize desired I/O port using I/O port registers 
		 viz. DDRx and PORTx.
Example Call: motion_pin_config () 
*/
void motion_pin_config (void) 
{
 DDRA = DDRA|0X0F;	//  Port A pins(PA3-PA0) have to be set as outputs.
 PORTA = PORTA|0XF0;	// Write suitable value in the PORT A register to make initial values to be "0"
 DDRL =  DDRL|0X18;  	//Setting PL3 and PL4 pins as output for PWM generation
 PORTL = PORTL|0X18;////Write suitable value in the PORT L register to set initial value of the Port L pins (PL3, PL4) to logic 1.
}
/*
Function name: port_init
Input: none
Output: none
Logic: Code to initialize desired I/O port using I/O port registers viz. DDRx and PORTx
Example Call: port_init();
*/

void port_init(void)
{
	DDRJ =0XFF;					// DDRJ register is used to initialize PortJ as output port.
	//All 8 pins of PortJ is connected to 8 LEDs of Bar graph LED module.
	//Write suitable value to ensure all 8 LEDs of Bar LED can be used.
	
	PORTJ = 0X00;			// PORTJ register is used to turn on/off an output device.
	//Write suitable value to ensure all 8 LEDs of Bar LED is turned ON at the start.

}


/*
* Function Name: motion_timer5_init 
* Input: none
* Output: none
* Logic: Code to initialize the register to generate the PWM using timer 5 
		 viz. TCCR5A,TCCR5B,TCNT5H,TCNT5L,OCR5AL and OCR5BL
Example Call: motion_timer5_init () 
*/
// Timer 5 initialized in PWM mode for velocity control
// Prescale:256
// PWM 8bit fast, TOP=0x00FF
// Timer Frequency:225.000Hz
void motion_timer5_init()
{
	TCCR5B =0X00; 	//Stop the timer initially
	TCNT5H = 0XFF;	//Counter higher 8-bit value to which OCR5xL value is compared with
	TCNT5L = 0X01;	//Counter lower 8-bit value to which OCR5xL value is compared with
	OCR5AL = 0XFF;	//Output compare register low value for Left Motor
	OCR5BL =0XFF;	//Output compare register low value for Right Motor
	TCCR5A =0XA9; 	//Write suitable value in this register to override normal port functionality and to select Fast PWM 8-bit Mode.
	
	TCCR5B = 0X0B;	//Write suitable value in this register to set the desired waveform generation mode and to select a prescalar of 64.
	
}


// Function for robot velocity control
/*
* Function Name: velocity
* Input: none
* Output: none
* Logic: Function for robot velocity control
Example Call: velocity (left motor velocity, right motor velocity)
*/
void velocity (unsigned char left_motor, unsigned char right_motor)
{
	OCR5AL = (unsigned char)left_motor;
	OCR5BL = (unsigned char)right_motor;
}
	
//Function used for setting motor's direction
/*
* Function Name: forward 
* Input: none
* Output: none
* Logic: Code used for setting motor's direction 
		 viz.PORTx.
Example Call: forward()
*/
void forward (void) 
{
  PORTA= PORTA|0X06; //define the port to rotate both wheels forward
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
  PORTA=  PORTA|0X00; //define the port to stop the motor
}
/*
* Function Name: motion_barLED
* Input: none
* Output: none 
Example Call: motion_barLED()
*/
void motion_barLED()
{

	unsigned char v=255;
		for(int i=0;i<=8;i++)

		{
		velocity (v, v); // velocity.changes from 255 to 63
		forward(); //both wheels forward
	
	v=v-24;	// decrement velocity by 24 from 255(max) to 63(min) 	
	
	PORTJ=0XFF;	//turn on all 8 leds in bargraph 
	
	//below code check for the value of i and turn off the leds one by one 	
	if(i==1)
	{
	PORTJ=0X7F;
	
	}
	else if(i==2)
	{
	PORTJ=0X3F;
		
	}
	else if(i==3)
	{
	PORTJ=0X1F;
		
	}
	 else if(i==4)
	{
	PORTJ=0X0F;
		
	}
	else if(i==5)
	{
	
	PORTJ=0X07;
	}
	else if(i==6)
	{
	
	PORTJ=0X03;
	}
	else if(i==7)
	{
	PORTJ=0X01;
		
	}

	else if(i==8)
	{
	

	velocity(0,0);//To stop robot velocity is given zero
	PORTJ=0X00;
	stop();						
		_delay_ms(500);
	}
	

	_delay_ms(5000);
		}
	
	//	stop();						
	//	_delay_ms(500);
	
	 
}



//Main Function
int main()
{
	
	motion_pin_config();
	motion_timer5_init();
	port_init();
 	motion_barLED();//robot moves with different velocity and turning off the light
		
	
	} 
