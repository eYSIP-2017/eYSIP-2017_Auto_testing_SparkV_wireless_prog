#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include <stdio.h>
//#include "/home/vinay/Desktop/CMock/lib/mocks/Mock_ms_delay.h"
#include "/home/vinay/Desktop/CMock/lib/mocks/MockTBT4.h"


void port_init(void);
void buzzer_on(void);
void buzzer_off(void);
void timer1_init(void);
void interrupt_init(void);
void isr_call(void);
void main_test(void);
extern volatile unsigned int counter;
extern int check[3];

void expect_delay(int a)
{
_delay_ms_CMockExpect(1, a);
} 


double calculate_delay()
{
   timer1_init();
   double scale;
   switch((TCCR1B & 0x07))
	{
	   case 0x03 :
		scale = 64;
	   break;
	   case 0x04 :
		scale = 256;
	   break;
           case 0x05 : 
		scale = 1024;
           break;
        }
	
        uint16_t ticks = 0x0000 | (uint16_t)TCNT1H;
               ticks = ticks << 8 | (uint16_t)TCNT1L;
       // printf("%i\n",TCCR1B);
                  
   
   uint16_t diff = OCR1A - ticks +1;
   
   double delay = ( (double)diff * scale ) / 14745600 ;
  
   //printf("%f\n",delay);
   
   return delay;
}

void clear_ports()
{
  DDRC = 0;
  PORTC = 0;
}

void test_port_init()
{
port_init();
TEST_ASSERT_EQUAL_INT(0xFF, DDRC);
TEST_ASSERT_EQUAL_INT(0x00, PORTC);
clear_ports();
}

void test_buzzer_on()
{
buzzer_on();
if (!((PORTC == 0x08) | (PORTC == 0xFF)))
{
   TEST_FAIL();
}
    
clear_ports();
}

void test_buzzer_off()
{
buzzer_off();
if (!((PORTC == 0xF7) | (PORTC == 0x00)))
{
   TEST_FAIL();
}
clear_ports();
}

void test_timer1_init()
{
  timer1_init();
  if (!(TCCR1A == 0x00 | TCCR1A == 0xC0))
	{
		TEST_FAIL();
	}
  double d = calculate_delay();
  if (!((d > 2.1) | (d < 1.9) | (d > 1.1) | (d < .9) ))
      {
          printf("Delay was not in the accepted range. The delay calculated was:%f\n",d);
          TEST_FAIL();
      }
  clear_ports(); 
}


void test_ISR()
{
  counter = 0;
  double d = calculate_delay();
  printf("%f\n",d);
  if (!((d > 2.1) | (d < 1.9)))
	{
	  lcd_print_CMockExpect(1,2,1,counter+2,2);
	  isr_call();
	  TEST_ASSERT_EQUAL_INT(2,counter);
	}

  else if (!((d > 1.1) | (d < .9)))
	{
	  if (counter = 1)
		{
		  printf("sda\n");
		  lcd_print_CMockExpect(1,2,1,counter+1,2);
	  	  isr_call();
	  	  TEST_ASSERT_EQUAL_INT(2,counter);
		}
	  else if (counter = 0)
		{
		  isr_call();
	  	  TEST_ASSERT_EQUAL_INT(1,counter);
		}
	}
  else
        {
          printf("Delay was not in the accepted range. The delay calculated was:%f\n",d);
          TEST_FAIL();
	}
} 


void test_main()
{
   lcd_init_CMockExpect(1);
   lcd_string_CMockExpect(1,"Counter");
   lcd_print_CMockIgnore();
   lcd_wr_command_CMockIgnore();
   counter = 10;
   if (counter == 10)
	{
            if ((TIMSK1 == 0x00) | (TCCR1B = 0x00))
		{
		   expect_delay(1000);
	           expect_delay(1000);
	   	   main_test();
		   if (!(check[2] == 0xFF | check[2] == 0x08))
			{
				TEST_FAIL();
			}
		   if (!(check[3] == 0x00 | check[3] == 0xF7))
			{	

				TEST_FAIL();
			}
		}
	    else 
		{
 		   TEST_FAIL();
		}
	}
}


int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_port_init);
RUN_TEST(test_timer1_init);
RUN_TEST(test_main);
RUN_TEST(test_ISR);
}
