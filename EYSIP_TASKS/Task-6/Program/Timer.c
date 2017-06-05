#include </usr/lib/avr/include/avr/io.h>
#include </usr/lib/avr/include/avr/interrupt.h>
#define F_CPU 14745600UL
#include </usr/lib/avr/include/util/delay.h>
unsigned char toggel = 0; //used as a variable for buzzer state toggel action

//Function to initialize Buzzer 
void buzzer_pin_config (void)
{
 DDRC = DDRC | 0x08;		//Setting PORTC 3 as outpt
 PORTC = PORTC & 0xF7;		//Setting PORTC 3 logic low to turnoff buzzer
}

void port_init (void)
{
 buzzer_pin_config();
}

void buzzer_on (void)
{
 unsigned char port_restore = 0;
 port_restore = PINC;
 port_restore = port_restore | 0x08;
 PORTC = port_restore;
}

void buzzer_off (void)
{
 unsigned char port_restore = 0;
 port_restore = PINC;
 port_restore = port_restore & 0xF7;
 PORTC = port_restore;
}

//TIMER4 initialize - prescale:1024
// WGM: 0) Normal, TOP=0xFFFF
// desired value: 1Hz
// actual value:  1.000Hz (0.0%)
void timer4_init(void)
{
 TCCR4B = 0x00; //stop
 TCNT4H = 0x1F; //Counter higher 8 bit value
 TCNT4L = 0x01; //Counter lower 8 bit value
 OCR4AH = 0x00; //Output Compair Register (OCR)- Not used
 OCR4AL = 0x00; //Output Compair Register (OCR)- Not used
 OCR4BH = 0x00; //Output Compair Register (OCR)- Not used
 OCR4BL = 0x00; //Output Compair Register (OCR)- Not used
 OCR4CH = 0x00; //Output Compair Register (OCR)- Not used
 OCR4CL = 0x00; //Output Compair Register (OCR)- Not used
 ICR4H  = 0x00; //Input Capture Register (ICR)- Not used
 ICR4L  = 0x00; //Input Capture Register (ICR)- Not used */
 TCCR4A = 0x00; 
 TCCR4C = 0x00;
 TCCR4B = 0x04; //start Timer
}

//This ISR can be used to schedule events like refreshing ADC data, LCD data
ISR(TIMER4_OVF_vect)
{
 //TIMER4 has overflowed
 TCNT4H = 0x1F; //reload counter high value
 TCNT4L = 0x01; //reload counter low value
 toggel = ~toggel;

 if (toggel == 0)
 {
  buzzer_on();
 }
 else
 {
  buzzer_off();
 }
} 

void init_devices(void)
{
 cli(); //Clears the global interrupts
 port_init(); //Initializes all ports 
 timer4_init();
 TIMSK4 = 0x01; //timer4 overflow interrupt enable
 sei();   //Enables the global interrupts
}

//Main Function
int main_test(void)
{
	init_devices();
	__vector_45();
	__vector_45();
	while(1)
}
