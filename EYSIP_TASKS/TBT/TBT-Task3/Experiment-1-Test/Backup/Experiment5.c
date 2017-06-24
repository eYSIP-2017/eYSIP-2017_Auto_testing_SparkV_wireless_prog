/*
* Experiment Number: 1
* Description: This experiment is a part of Task 3. It is aimed to get you familiar with the LCD interfacing.
* This experiment involves writing a code to display "e-Yantra" on the LCD. 
* Author: e-Yantra Team
*/

//TeamID.908

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


#define F_CPU 14745600
#include </usr/lib/avr/include/avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"		// user-defined header file - it is included in project folder
#include "lcd.c"

/*
*	Global Variable Declaration
*/
 // Declare any global variable if you require here

 
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
	DDRC =0xFF ;      // all the LCD pin's direction set as output

	PORTC =0x00;     // all the LCD pins are set to logic 0

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
	 
	
	lcd_wr_command(0xCA);	//Write command to move the cursor to 2nd line 1st column. Cursor will be set at this position.
	//Refer to the written tutorial for all the lcd commands.
	
	//Use lcd_wr_char() here along with appropriate arguments to display the required text
	 lcd_wr_char('e'); 
        lcd_wr_char('-'); 
	lcd_wr_char('Y'); 
	lcd_wr_char('a'); 
	lcd_wr_char('n'); 
	lcd_wr_char('t'); 
	lcd_wr_char('r'); 
        lcd_wr_char('a'); 


	while(1);  // Infinite loop. To halt the execution 
}
