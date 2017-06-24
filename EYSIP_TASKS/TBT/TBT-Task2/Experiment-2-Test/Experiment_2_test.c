#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include <stdio.h>

void main_test(void);
void port_init(void);
void led_on(void);
void led_off(void);



void clear_ports()
{
	DDRJ = 0;
	PORTJ = 0;
}

void set_PINE(int a)
{
   PINE = a;
}

void test_port_init()
{
port_init();
TEST_ASSERT_EQUAL_INT(0xFF, DDRJ);
TEST_ASSERT_EQUAL_INT(0x00, PORTJ);
}

void test_led_on()
{
led_on();
TEST_ASSERT_EQUAL_INT(0xF0, PORTJ);
}

void test_led_off()
{
led_off();
TEST_ASSERT_EQUAL_INT(0x00, PORTJ);
}

void test_press()
{
  set_PINE(0x00);
  main_test();
  TEST_ASSERT_EQUAL_INT(0xF0, PORTJ);
  clear_ports(); 
}

void test_no_press()
{
  set_PINE(0x80);
  main_test();
  TEST_ASSERT_EQUAL_INT(0x00, PORTJ);
  clear_ports();  
}



int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_port_init);
clear_ports();
RUN_TEST(test_press);
clear_ports();
RUN_TEST(test_no_press);
}
