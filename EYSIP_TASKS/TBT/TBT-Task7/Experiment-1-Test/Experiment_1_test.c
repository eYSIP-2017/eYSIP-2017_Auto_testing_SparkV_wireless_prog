#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include <stdio.h>
//#include "/home/vinay/Desktop/CMock/lib/mocks/Mock_ms_delay.h"
#include "/home/vinay/Desktop/CMock/lib/mocks/MockTBT7.h"


void port_init(void);
void buzzer_on(void);
void buzzer_off(void);
void timer1_init(void);
void main_test(void);
extern volatile unsigned int counter;
extern int check_buzzer[4];
extern int check_led[7];

void expect_delay(int a)
{
delay_new_ms_CMockExpect(1,a);
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
        //printf("%i\n",TCCR1B);
                  
   uint16_t diff = OCR1A - ticks +1;

  // printf("%d\n",diff);
   double delay = ( (double)diff * scale ) / 14745600 ;  
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
TEST_ASSERT_EQUAL_INT(0xFF, DDRJ);
TEST_ASSERT_EQUAL_INT(0x00, PORTJ);
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
  TCNT1H = 0x02; 	 
  TCNT1L = 0x58;
  double d = calculate_delay();
  if ((d > 1.11) | (d < .89))
      {
          printf("Delay was not in the accepted range. The delay calculated was:%f\n",d);
          TEST_FAIL();
      }
  clear_ports(); 
}

void test_led()
{
	int k;
 	for(int i=1; i<=3; i++)
	{
		expect_delay(i*1000);
	}
	for(int i=2; i>=1; i--)
	{
		expect_delay(i*1000);
	}

	expect_delay(2*1000);

	main_test();
	for(int i=0; i<=4; i++)
	{
		k = 2*k+1;
		TEST_ASSERT_EQUAL_INT(k,check_led[i+2]);
	}
}
void test_buzzer()
{
	if (!(check_buzzer[2]== 0x08 | check_buzzer[2] == 0xFF))
	{	
		printf("%d\n",check_buzzer[3]);
		TEST_FAIL();
	}
	if (!((check_buzzer[3] & 0x08) == 0x00))
	{
		printf("%d\n",(check_buzzer[3] & 0x08));
		TEST_FAIL();
	}
}

int main(void)
{
UNITY_BEGIN();
calculate_delay();
RUN_TEST(test_port_init);
RUN_TEST(test_timer1_init);
RUN_TEST(test_led);
RUN_TEST(test_buzzer);
}
