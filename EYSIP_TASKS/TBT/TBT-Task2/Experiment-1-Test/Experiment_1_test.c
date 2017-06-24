#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include "../../../../CMock/lib/mocks/Mock_ms_delay.h"
#include <stdio.h>

void main_test(void);
void port_init(void);
void led_on_topfour(void);
void led_off_topfour(void);
void led_on_bottomfour(void);
void led_off_bottomfour(void);

extern int value[5]; 



/*
* Function Name: clear_ports 
* Input: none
* Output: none
* Logic: Code to clear the values that have been written to PORTJ and DDRJ
Example Call: clear_ports.
*/

void clear_ports()  
{
DDRJ = 0;
PORTJ = 0;
}

/*
* Function Name: test_port_init 
* Input: none
* Output: none
* Logic: Code to test the initialization of desired I/O port using IO port registers 
		 viz. DDRJ and PORTJ
*/

void test_port_init()
{
port_init();
TEST_ASSERT_EQUAL_INT(0xFF, DDRJ);
TEST_ASSERT_EQUAL_INT(0x00, PORTJ);
clear_ports();
}

/*
* Function Name: test_led_on_topfour
* Input: none
* Output: none
* Logic: Code to Test wether the top four BAR LEDs are turned on
Example Call: RUN_TEST(test_led_on_topfour)
*/

void test_led_on_topfour()
{
led_on_topfour();
TEST_ASSERT_EQUAL_INT(0xF0, PORTJ);
clear_ports();
}

/*
* Function Name: test_led_off_topfour
* Input: none
* Output: none
* Logic: Code to Test wether the top four BAR LEDs are turned off
Example Call: RUN_TEST(test_led_off_topfour)
*/

void test_led_off_topfour()
{
led_off_topfour();
TEST_ASSERT_EQUAL_INT(0x00, PORTJ);
clear_ports();
}

/*
* Function Name: test_led_on_bottomfour
* Input: none
* Output: none
* Logic: Code to Test wether the bottom four BAR LEDs are turned on 
Example Call: RUN_TEST(test_led_on_bottomfour)
*/ 

void test_led_on_bottomfour()
{
led_on_bottomfour();
TEST_ASSERT_EQUAL_INT(0x0F, PORTJ);
clear_ports();
}

/*
* Function Name: test_led_off_bottomfour
* Input: none
* Output: none
* Logic: Code to Test wether the bottom four BAR LEDs are turned off
Example Call: RUN_TEST(test_led_off_bottomfour)
*/ 

void test_led_off_bottomfour()
{
led_off_bottomfour();
TEST_ASSERT_EQUAL_INT(0x00, PORTJ);
clear_ports();
}

/*
* Function Name: expect_delay
* Input: double 
* Output: none
* Logic: Code to expect a delay in the test with the parameter that is passed as an arguement.
*/ 


void expect_delay(double A)
{
_delay_ms_CMockExpect(1,A);
}

/*
* Function Name: test_main
* Input: none
* Output: none
* Logic: Code to Test the functionality of the main function in the submitted C program.
*/ 

void test_main_1()
{
  expect_delay(1000);
  expect_delay(1000);
  main_test();

  if (value[1]== 0x00)
	{
	     if(value[2]== 0xF0)
			{
			    if (value[3]== 0x00)
				{
				   TEST_ASSERT_EQUAL_INT(0x0F,value[4]);
				}
			    else 
				{
				    TEST_FAIL();
				}
	      


			}

	     else if (value[2]== 0x0F)
			{
			    if (value[3]== 0x00)
				{
				   TEST_ASSERT_EQUAL_INT(0xF0,value[4]);
				}
			    else 
				{
				    TEST_FAIL();
				}

			}
	     else 
		{		
			TEST_FAIL();
		}
			
	}
 else
	{
		TEST_FAIL();
	}
}


void test_main_2()
{
  expect_delay(1000);
  expect_delay(1000);
  if (value[1]== 0xF0)
	{
	     if(value[2]== 0x00)
			{
			    if (value[3]== 0x0F)
				{
				   TEST_ASSERT_EQUAL_INT(0x00,value[4]);
				}
			    else 
				{
				    TEST_FAIL();
				}
			}
	     else if (value[2]== 0xF0)
			{

			    if (value[3]== 0x0F)
				{
				   TEST_ASSERT_EQUAL_INT(0x0F,value[4]);
				}
			    else 
				{
				    TEST_FAIL();
				}
			}
	     else
		{
			TEST_FAIL();
		}
	}
 else
	{
		TEST_FAIL();
	}
}
void test_main_3()
{
  expect_delay(1000);
  expect_delay(1000);
  if (value[1]== 0x0F)
	{
	     if(value[2]== 0x00)
			{
			    if (value[3]== 0xF0)
				{
				   TEST_ASSERT_EQUAL_INT(0x00,value[4]);
				}
			    else 
				{
				    TEST_FAIL();
				}
			}
	     else if (value[2]== 0x0F)
			{

			    if (value[3]== 0xF0)
				{
				   TEST_ASSERT_EQUAL_INT(0xF0,value[4]);
				}
			    else 
				{
				    TEST_FAIL();
				}
			}
	     else
		{
			TEST_FAIL();
		}
	}
  else
    {
	TEST_FAIL();
    }
}



int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_port_init);
clear_ports();
RUN_TEST(test_main_1);
RUN_TEST(test_main_2);
RUN_TEST(test_main_3);
clear_ports();
RUN_TEST(test_led_on_topfour);
RUN_TEST(test_led_on_bottomfour);

}
