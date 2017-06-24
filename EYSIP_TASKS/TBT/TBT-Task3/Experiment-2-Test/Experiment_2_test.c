#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include <stdio.h>
#include "/home/vinay/Desktop/CMock/lib/mocks/MockTBT3.h"

void lcd_port_config(void);
void lcd_display_number(int number);
void main_test(void);

void test_lcd_port_config()
{
lcd_port_config();
if (!(DDRC == 0xFF | DDRC == 0xF7 ))
{
	TEST_FAIL();
}
TEST_ASSERT_EQUAL_INT(0x00,PORTC);
}


void test_lcd_display(int a)
{
int tens,ones;
tens=a/10 ; 
tens=tens+48;
ones=a %10 ;	
ones=ones+48;	               
lcd_wr_char_CMockExpect(1,tens);
lcd_wr_char_CMockExpect(1,ones);
lcd_display_number(a);
}

void test_function()
{
test_lcd_display(45);
test_lcd_display(78);
test_lcd_display(99);
}

void test_main()
{
	lcd_port_config();
	lcd_init_CMockIgnore();
	lcd_wr_char_CMockIgnore();
	lcd_wr_command_CMockExpect(1,0xC0);
	main_test();

}

void main()
{
UNITY_BEGIN();
RUN_TEST(test_lcd_port_config);
RUN_TEST(test_function);
RUN_TEST(test_main);
}
