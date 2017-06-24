#define __builtin_avr_delay_cycles
#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include "../../../../CMock/lib/mocks/Mock_ms_delay.h"
#include "Motion_Control.h"
#include <stdio.h>
extern int motion_check[12];
#define f 0x06
#define s 0x00
#define l 0x05
int check_motion_case_1[12] = {0,0,f,s,l,s,f,s,l,s,f,s};
int check_motion_case_2[12] =  {0,0,f,l,f,l,f,s };
int check_motion_case_3[12] =  {0,0,f,l,f,l,f,};
int check_motion_case_4[12] = {0,0,f,s,l,s,f,s,l,s,f};
int check_motion_case_5[12] = {0,0,f,l,s,f,l,s,f};
int check_motion_case_6[12] = {0,0,f,l,s,f,l,s,f,s};
int flag_case_1 = 0;
int flag_case_2 = 0;
int flag_case_3 = 0;
int flag_case_4 = 0;
int flag_case_5 = 0;
int flag_case_6 = 0;
void clear()
{
   PORTA = 0x00;
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

void left_test()
{
left();
TEST_ASSERT_EQUAL_INT(0x05, PORTA);
clear();
}

void right_test()
{
right();
TEST_ASSERT_EQUAL_INT(0x0A, PORTA);
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
 for (int i =0; i <=11; i++)
     {
          if (!(motion_check[i] == check_motion_case_1[i]))
		{
			flag_case_1 = 1;
		}
	  else 
		{
			
		}
     }

 for (int i =0; i <=10; i++)
     {
          if (!(motion_check[i] == check_motion_case_2[i]))
		{
			flag_case_2 = 1;
		}
	  else 
		{
			
		}
     }
 for (int i =0; i <=10; i++)
     {
          if (!(motion_check[i] == check_motion_case_3[i]))
		{
			flag_case_3 = 1;
		}
	  else 
		{
			
		}
     }
 for (int i =0; i <=10; i++)
     {
          if (!(motion_check[i] == check_motion_case_4[i]))
		{
			flag_case_4 = 1;
		}
	  else 
		{
			
		}
     }
 for (int i =0; i <=10; i++)
     {
          if (!(motion_check[i] == check_motion_case_5[i]))
		{
			flag_case_5 = 1;
		}
	  else 
		{
			
		}
     }
 for (int i =0; i <=10; i++)
     {
          if (!(motion_check[i] == check_motion_case_6[i]))
		{
			flag_case_6 = 1;
		}
	  else 
		{
			
		}
     }
 if (!(flag_case_1 & flag_case_2 & flag_case_3 & flag_case_4 & flag_case_5 & flag_case_6))
     {
         
     }
 else 
     {
           TEST_FAIL();
     }

}


int main()
{
UNITY_BEGIN();
RUN_TEST(motion_pin_config_test);
RUN_TEST(test_main);
RUN_TEST(forward_test);
RUN_TEST(left_test);
RUN_TEST(right_test);
RUN_TEST(stop_test);
}
