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

extern int value[5]; // Array to store any changes to Port J



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
* Function Name: test_main_1
* Input: none
* Output: none
* Logic: One of the Unit Test cases to check the functionality of the main function in the submitted C program. 
*/ 

void test_main_1()
{
  expect_delay(1000);
  expect_delay(1000);
  _delay_ms_CMockIgnore();  // Ignores any delays that the user might have used as they are not relevent to the Unit Test.
  main_test();     

  if (value[1]== 0x00) // Checks if the user has intially turned off all four LEDs
	{
	     if(value[2]== 0xF0) // Checks if the user has then turned on the top four LEDs
			{
			    if (value[3]== 0x00) // Checks if the user has then turned off the four LEDs
				{
				   TEST_ASSERT_EQUAL_INT(0x0F,value[4]); // Checks if the user has then turned on the bottom four LEDs
				}
			    else if (value[3]== 0x0F) //Checks if the user has then turns on the bottom four LEDs
				{
				   
				}
	      		    else 
				{
					TEST_FAIL(); 
				}


			}

	     else if (value[2]== 0x0F) // Checks if the user then turned on the bottom four LEDs
			{
			    if (value[3]== 0x00) // Checks if the user then turned off the four LEDs
				{
				   TEST_ASSERT_EQUAL_INT(0xF0,value[4]); // Checks if the user then turned on the top four LEDs
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

/*
* Function Name: test_main_2
* Input: none
* Output: none
* Logic: One of the Unit Test cases to check the functionality of the main function in the submitted C program. 
*/ 

void test_main_2()
{
  expect_delay(1000);
  expect_delay(1000);
  if (value[1]== 0xF0) // Checks if the user has intially turned on the top four LEDs
	{
	     if(value[2]== 0x00)  // Checks if the user has then turned off the top four LEDs
			{
			    if (value[3]== 0x0F) // Checks if the user has then turned on the bottom four LEDs
				{
				   TEST_ASSERT_EQUAL_INT(0x00,value[4]); // Checks if the user has finally turned off the LEDs
				}
			    else 
				{
				    TEST_FAIL();
				}
			}
	     else if (value[2]== 0xF0) // Checks if the user has then turned off the bottom four LEDs
			{

			    if (value[3]== 0x0F) // Checks if the user has then turned on the bottom four LEDs
				{
				   TEST_ASSERT_EQUAL_INT(0x0F,value[4]); // Checks if the user has then turned off the top four LEDs
				}
			    else 
				{
				    TEST_FAIL();
				}
			}
	     else if (value[2]== 0x0F) // Checks if the user then toggles the top and bottom four LEDs
			{

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

/*
* Function Name: test_main_3
* Input: none
* Output: none
* Logic: One of the Unit Test cases to check the functionality of the main function in the submitted C program. 
*/ 

void test_main_3()
{
  expect_delay(1000);
  expect_delay(1000);
  if (value[1]== 0x0F) // Checks if the user has intially turned on the bottom four LEDs
	{
	     if(value[2]== 0x00) // Checks if the user has then turned off the top four LEDs
			{
			    if (value[3]== 0xF0) // Checks if the user has then turned on the top four LEDs
				{
				   TEST_ASSERT_EQUAL_INT(0x00,value[4]); // Checks if the user has finally turned off the LEDs
				}
			    else 
				{
				    TEST_FAIL();
				}
			}
	     else if (value[2]== 0x0F) // Checks if the user has then turned off the top four LEDs
			{

			    if (value[3]== 0xF0) // Checks if the user has then turned on the top four LEDs
				{
				   TEST_ASSERT_EQUAL_INT(0xF0,value[4]); // Checks if the user has then turned off the top four LEDs
				}
			    else 
				{
				    TEST_FAIL();
				}
			}
	     else if (value[2]== 0xF0) // Checks if the user then toggles the top and bottom four LEDs
			{

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
clear_ports();
RUN_TEST(test_led_on_bottomfour);

}
