#include </usr/lib/avr/include/avr/io.h>
#include "../../../../Unity-master/src/unity.h"
#include <stdio.h>
#include "/home/vinay/Desktop/CMock/lib/mocks/MockTBT3.h"

void lcd_port_config(void);
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

void test_position()
{
lcd_init_CMockIgnore();
lcd_wr_command_CMockExpect(1,0xC0);
lcd_wr_char_CMockIgnore();
main_test();
}


void test_main()
{
lcd_init_CMockIgnore();
lcd_wr_command_CMockExpect(1,0xC0);
lcd_wr_char_CMockExpect(1,101);
lcd_wr_char_CMockExpect(1,45);
lcd_wr_char_CMockExpect(1,89);
lcd_wr_char_CMockExpect(1,97);
lcd_wr_char_CMockExpect(1,110);
lcd_wr_char_CMockExpect(1,116);
lcd_wr_char_CMockExpect(1,114);
lcd_wr_char_CMockExpect(1,97);
main_test();
}




void main()
{
UNITY_BEGIN();
RUN_TEST(test_lcd_port_config);
RUN_TEST(test_position);
RUN_TEST(test_main);
}
