//#define TEST
//#include </usr/lib/avr/include/avr/io.h>
#include "Ex.h"
#include "/home/vinay/Desktop/Unity-master/src/unity.h"
#include "Bar_LED.h"

void test_initial(void)
{
port_init();
TEST_ASSERT_EQUAL_INT (0xFA, DDRJ);
TEST_ASSERT_EQUAL_INT (0xFA, PORTJ);
}

void test_clear()
{
clear();
TEST_ASSERT_EQUAL_INT (0x0A, PORTJ);
}

void test_set_led()
{
Set_LED(0x64);
TEST_ASSERT_EQUAL_INT (0xFF, DDRJ);
TEST_ASSERT_EQUAL_INT (0x64, PORTJ);
Set_LED(0x3A);
TEST_ASSERT_EQUAL_INT (0xFF, DDRJ);
TEST_ASSERT_EQUAL_INT (0x3A, PORTJ);
Set_LED(0x77);
TEST_ASSERT_EQUAL_INT (0xFF, DDRJ);
TEST_ASSERT_EQUAL_INT (0x77, PORTJ);
Set_LED(0xFA);
TEST_ASSERT_EQUAL_INT (0xFF, DDRJ);
TEST_ASSERT_EQUAL_INT (0xFA, PORTJ);
}

void test_disable()
{
disable_Bar_LED();
TEST_ASSERT_EQUAL_INT (0x00, DDRJ);
TEST_ASSERT_EQUAL_INT (0x00, PORTJ);
}

int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_initial);
RUN_TEST(test_clear);
RUN_TEST(test_set_led);
RUN_TEST(test_disable);
return UNITY_END();
}
