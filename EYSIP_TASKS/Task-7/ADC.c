#include </usr/lib/avr/include/avr/io.h>
#include </usr/lib/avr/include/avr/interrupt.h>
#define F_CPU 14745600UL
#include"../../CMock/lib/mocks/MockADC_Function_Header.h"
#include <math.h> 
#include "lcd.c"
int check[2];
int check2[1];
int check1[2];
int i =0;

unsigned char ADC_Conversion(unsigned char);
unsigned char ADC_Value;
unsigned char sharp, distance, adc_reading;
unsigned int value;
float BATT_Voltage, BATT_V;

//Function to configure LCD port
void lcd_port_config (void)
{
 DDRC = DDRC | 0xF7; //all the LCD pin's direction set as output
 PORTC = PORTC & 0x80; // all the LCD pins are set to logic 0 except PORTC 7
}

//ADC pin configuration
void adc_pin_config (void)
{
 DDRF = 0x00; //set PORTF direction as input
 PORTF = 0x00; //set PORTF pins floating
 DDRA = 0x00; //set PORTK direction as input
 PORTA = 0x00; //set PORTK pins floating
}

//Function to Initialize PORTS
void port_init()
{
	lcd_port_config();
	adc_pin_config();	
}

//Function to Initialize ADC
void adc_init()
{
	ADCSRA = 0x00;
	check[0] = ADCSRA;
	ADCSRB = 0x00;		//MUX5 = 0
	ADMUX = 0x20;		//Vref=5V external --- ADLAR=1 --- MUX4:0 = 0000
	//ACSR = 0x80;
	ADCSRA = 0x86;		//ADEN=1 --- ADIE=1 --- ADPS2:0 = 1 1 0
	check[1] = ADCSRA;
}



//This Function accepts the Channel Number and returns the corresponding Analog Value 
unsigned char ADC_Conversion1(unsigned char Ch)
{
	unsigned char a;
	if(Ch>7)
	{
		ADCSRB = 0x08;
		check1[0] = ADCSRB;
	}
	Ch = Ch & 0x07;  			
	ADMUX= 0x20| Ch;
	check2[0] = ADMUX;	   		
	ADCSRA = ADCSRA | 0x40;		//Set start conversion bit
	check[0] = ADCSRA;
	//while((ADCSRA&0x10)==0);	//Wait for ADC conversion to complete
	a=ADCH;
	ADCSRA = ADCSRA|0x10; //clear ADIF (ADC Interrupt Flag) by writing 1 to it
	check[1] = ADCSRA;
	ADCSRB = 0x00;
	check1[1] = ADCSRB;
	return a;
}


// This Function prints the Analog Value Of Corresponding Channel No. at required Row
// and Coloumn Location. 

void print_sensor1(char row, char coloumn,unsigned char channel)
{
	ADC_Value = ADC_Conversion1(channel);
	lcd_print(row, coloumn, ADC_Value, 3);
}


// This Function calculates the actual distance in millimeters(mm) from the input
// analog value of Sharp Sensor. 
unsigned int Sharp_GP2D12_estimation1(unsigned char adc_reading)
{
	float distance;
	unsigned int distanceInt;
	distance = (int)(10.00*(2799.6*(1.00/(pow(adc_reading,1.1546)))));
	distanceInt = (int)distance;
	if(distanceInt>800)
	{
		distanceInt=800;
	}
	return distanceInt;
}

void init_devices (void)
{
 cli(); //Clears the global interrupts
 port_init();
 adc_init();
 sei(); //Enables the global interrupts
}


//Main Function

int main_test(void)
{
	unsigned int value;
	init_devices();
	
	lcd_set_4bit();
	lcd_init();
	
	//while(1)
	{
		BATT_V = ADC_Conversion(0);
		BATT_Voltage = ((ADC_Conversion(0))*0.07902) + 0.7;	//Prints Battery Voltage Status
		lcd_print(1,1,BATT_Voltage,4);

		print_sensor(1,1,0);							//Prints Battery voltage binary value

		print_sensor(1,6,5);							//Prints IR Proximity Sensor 1
		print_sensor(1,10,6);							//Prints vlaue of Analog IR Proximity Sensor 2
		print_sensor(1,14,7);							//Prints value of Analog IR Proximity Sensor 3
		print_sensor(2,2,3);							//Prints value of White Line Sensor1
		print_sensor(2,6,2);							//Prints Value of White Line Sensor2
		print_sensor(2,10,1);							//Prints Value of White Line Sensor3

		print_sensor(2,9,11); 						//Analog Value Of Front Sharp Sensor

		sharp = ADC_Conversion(11);						//Stores the Analog value of front sharp connected to ADC 
		value = Sharp_GP2D12_estimation(sharp);				//Stores Distance calsulated in a variable "value".
		lcd_print(2,14,value,3); 						//Prints Value Of Distanc in MM measured by Sharp Sensor.
	}
} 
