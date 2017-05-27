//#define TEST
#include </usr/lib/avr/include/avr/io.h>
//#include "Ex.h"
#include "/home/vinay/Desktop/Unity-master/src/unity.h"
#include "Buzzer_Beep.h"
#include <stdio.h>

void test_main_1()
{
main_1();
TEST_ASSERT_EQUAL_INT (0x08, DDRC);
TEST_ASSERT_EQUAL_INT (0x00, PORTC);
}

void test_buzzer_pin_config()
{
buzzer_pin_config();
TEST_ASSERT_EQUAL_INT (0x08, DDRC);
TEST_ASSERT_EQUAL_INT (0x00, PORTC);
}

void test_buzzer_on()
{
buzzer_on();
TEST_ASSERT_EQUAL_UINT8 (0x08, DDRC);
TEST_ASSERT_EQUAL_UINT8 (0x08, PORTC);
}


int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_main_1);
RUN_TEST(test_buzzer_on);
RUN_TEST(test_buzzer_pin_config);
return UNITY_END();
}
