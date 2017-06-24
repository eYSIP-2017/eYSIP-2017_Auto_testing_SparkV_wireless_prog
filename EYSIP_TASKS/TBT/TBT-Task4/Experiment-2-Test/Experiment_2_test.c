#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include <stdio.h>
#include "/home/vinay/Desktop/CMock/lib/mocks/Mock_ms_delay.h"



void port_init(void);
void buzzer_on(void);
void buzzer_off(void);
void timer1_init(void);
void interrupt_init(void);
void main_test(void);
void isr_call(void);
volatile extern unsigned int counter;
extern int check[4];

void expect_delay(int a)
{
_delay_ms_CMockExpect(1, a);
} 

int number_of_ones(int a)
{
int ones;
int temp = a;
   for(int i=0; i < 8; i++)
	 {
	    if(temp & 1)
		{
		  ones++;
		}
		temp >>= 1;
	  }
 return ones/2;
}

double calculate_delay()
{
   timer1_init();
   double scale;
   switch(TCCR1B)
	{
	   case 0x04 :
		scale = 256;
	   break;
           case 0x05 : 
		scale = 1024;
           break;
        }
	
        uint16_t ticks = 0x0000 | (uint16_t)TCNT1H;
               ticks = ticks << 8 | (uint16_t)TCNT1L;
        //printf("%i\n",ticks);
                  
   
   uint16_t diff = 0xFFFF - ticks;
   
   double delay = ( (double)diff * scale ) / 14745600 ;
  
  //printf("%f\n",delay);
   
   return delay;
}

void clear_ports()
{
  DDRC = 0;
  PORTC = 0;
  PORTJ = 0;
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
  TEST_ASSERT_EQUAL_INT(0x00, TCCR1A);
  double d = calculate_delay();
  if (!((d > 2.1) | (d < 1.9) | (d > 1.1) | (d < .9) ))
      {
          TEST_FAIL();
      }
  clear_ports(); 
}

void test_ISR()
{
  counter = 0;
  int k = 0;
  for (int j =0; j < 8 ; j++)
 	{
	   //printf("%d\n",counter);
           k = 2*k+1;
           isr_call();
           TEST_ASSERT_EQUAL_INT(PORTJ,k);
	}

} 



void test_main()
{
     counter = 8;
     expect_delay(1000); 
     main_test();

			if (!((check[2] == 0x08) | (check[2] == 0xFF)))
			{
			  // printf("%d\n",check[2]);
			   TEST_FAIL();
			}
		        else if (!((check[3] == 0xF7) | (check[3] == 0x00)))
			{
			  // printf("2\n");
			   TEST_FAIL();
			}
		        
			else
			{ 
			  
			}

}

int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_port_init);
RUN_TEST(test_timer1_init);
RUN_TEST(test_main);
clear_ports();
RUN_TEST(test_ISR);
}
