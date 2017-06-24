/*
* Experiment Number: 2
* Description: This experiment is part of Task-3. It is aimed to get you familiar with the LCD interfacing. 
* This experiment involves writing a code to display two 2-digit numbers on the LCD.
* Author: e-Yantra Team
*/

//TeamID.13231

/*  			   
LCD Connections:
 			  LCD	  Microcontroller Pins
 			  RS  --> PC0
			  RW  --> PC1
			  EN  --> PC2
			  DB7 --> PC7
			  DB6 --> PC6
			  DB5 --> PC5
			  DB4 --> PC4 

*/

//#define F_CPU 14745600 specified in project configuration options
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"		// user-defined header file - it is included in project folder


/*
*	Global Variable Declaration
*/
 // Declare any global variables if you require here
int a=54;	// number1
int b=63;	// number2
 
/*
* Function Name: lcd_port_config 
* Input: none
* Output: none
* Logic: Code to initialize desired I/O port using IO port registers 
		 viz. DDRx and PORTx.
Example Call: lcd_port_config() 
*/
void lcd_port_config (void)
{
	DDRC = DDRC | 0xF7;      // all the LCD pin's direction set as output

	PORTC = PORTC & 0x08;     // all the LCD pins are set to logic 0

}


/*
* Function Name: lcd_display_number 
* Input: unsigned int number
* Output: none
* Logic: Code to split a given 2-digit value into ten's digit and unit's digit, then convert the digits into equivalent ASCII values and display them on the LCD
* Example Call: lcd_display_number(81)
*/
void lcd_display_number(int number)
{
    unsigned char digit_tens, digit_units;

	digit_tens= number / 10 + 48;            //Step 1: extract the ten's digit using the division operator and convert to its ascii equivalent
	lcd_wr_char(digit_tens);    	 //Step 2: pass the ten's digit as argument to lcd_wr_char()

	//Similarly write code for unit's digit 
	//Note cursor is set to auto increment so no need to set cursor every time

	digit_units= number % 10 +48;			//Step 3: extract the unit's digit using the modulo operator and convert to its ascii equivalent
	lcd_wr_char(digit_units);       	//Step 4: pass the unit's digit as argument to lcd_wr_char()

}

/*
* Function Name:lcd_set_4bit
* Input:none
* Output: none
* Logic: Initialization sequence of LCD in 4-bit mode
* Example call: lcd_set_4bit();

Note : This function has been defined in the C file "lcd.c".
*/


/*
* Function Name: lcd_wr_command
* Input: unsigned char cmd
* Output: none
* Logic: Splits command - splits into two 4 bit nibbles and sends them to LCD
* Example call: lcd_wr_command(command in hex);

Note : This function has been defined in the C file "lcd.c".
*/
/*
*
* Function Name: lcd_wr_char
* Input: signed char
* Output: none
* Logic: Splits data into two 4 bit nibbles and sends them to LCD
* Example call: lcd_wr_char(ASCII value of data);

Note : This function has been defined in the C file "lcd.c".
*/


int main (void)
{
	lcd_port_config();
	lcd_init();
	lcd_display_number(a);
	lcd_wr_command(0xC0); // Write command to move cursor to 2nd row first column of the LCD.
    lcd_display_number(b); 
	while(1);  // Infinite loop. To halt the execution 
}

//Your lcd should display the numbers a and b 
