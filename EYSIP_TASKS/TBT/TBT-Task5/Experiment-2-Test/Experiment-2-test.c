#define __builtin_avr_delay_cycles
#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include "../../../../CMock/lib/mocks/Mock_ms_delay.h"
#include "Motion_Control.h"
#include <stdio.h>
void motion_timer5_init(void);
extern int check_bar_led[9];
extern int check_velocity_left[10];
extern int check_velocity_right[10];

void clear()
{
   PORTA = 0x00;
}

void check_led()
{

 int k = 0;
 for (int j =8; j >= 0 ; j--)
 	{
	   if (!(j == 8))
		{
 	          k = 2*k+1;
                  if (!(check_bar_led[j] == k))
		       {
		 	 TEST_FAIL();
		       }
		}
	   else 
		{
                  if (!(check_bar_led[j] == k))
		       {
		 	 TEST_FAIL();
		       }	
		}

	}
}

void check_velocity()
{
 int k = 0;
 for (int j =7; j >= 0 ; j--)
 	{
	  //printf("%i\n",check_velocity_left[9-j]);
	  int velocity =j*0x20;

	   if (j == 8)
		{
                   if (!((check_velocity_left[9-j] >= velocity) & (check_velocity_right[9-j] >= velocity)))
	           {
			TEST_FAIL();
		   }
		}
	   else 
		{
	           if (!((check_velocity_left[9-j] == velocity) & (check_velocity_right[9-j] == velocity)))
	           {
			TEST_FAIL();
		   }
		}

	}
}


void motion_timer5_init_test()
{
motion_timer5_init();
TEST_ASSERT_EQUAL_INT(0xFF,TCNT5H);
TEST_ASSERT_EQUAL_INT(0x00,TCNT5L);
TEST_ASSERT_EQUAL_INT(0x00,OCR5AH);
TEST_ASSERT_EQUAL_INT(0xFF,OCR5AL);
TEST_ASSERT_EQUAL_INT(0x00,OCR5BH);
TEST_ASSERT_EQUAL_INT(0xFF,OCR5BL);
TEST_ASSERT_EQUAL_INT(0xA9,TCCR5A);
TEST_ASSERT_EQUAL_INT(0x0C,TCCR5B);
}


void motion_pin_config_test()
{
motion_pin_config();

if (!((DDRA == 0x0F) | (DDRA == 0xFF) ))
	{
		TEST_FAIL();
	}
if (!((PORTA == 0xF0) | (PORTA == 0x00)))
	{
		TEST_FAIL();
	}
TEST_ASSERT_EQUAL_INT(0x18, DDRL);
TEST_ASSERT_EQUAL_INT(0x18, PORTL);
}

void forward_test()
{
forward();
TEST_ASSERT_EQUAL_INT(0x06, PORTA);
clear();
}

void stop_test()
{
stop();
TEST_ASSERT_EQUAL_INT(0x00, PORTA);
clear();
}

void test_main()
{
_delay_ms_CMockIgnore();
main_test();

}
void test_velocity()
{
 check_velocity();
}

void test_LED()
{
 check_led();
}



int main()
{
UNITY_BEGIN();
RUN_TEST(test_main);
RUN_TEST(test_velocity);
RUN_TEST(test_LED);
RUN_TEST(motion_pin_config_test);
}
