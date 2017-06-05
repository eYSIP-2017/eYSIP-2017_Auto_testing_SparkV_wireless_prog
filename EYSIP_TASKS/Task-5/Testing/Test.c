#define __builtin_avr_delay_cycles
#include </usr/lib/avr/include/avr/io.h>
#include "../../../Unity-master/src/unity.h"
#include "Motion_Control.h"
#include "../../../CMock/lib/mocks/Mock_ms_delay.h"
#include <stdio.h>

extern int check[40];

void motion_pin_config_test()
{
motion_pin_config();
TEST_ASSERT_EQUAL_INT(0x0F, DDRA);
TEST_ASSERT_EQUAL_INT(0x00, PORTA);
TEST_ASSERT_EQUAL_INT(0x18, DDRC);
TEST_ASSERT_EQUAL_INT(0x18, PORTC);
}

void forward_test()
{
forward();
TEST_ASSERT_EQUAL_INT(0x06, PORTA);
}

void back_test()
{
back();
TEST_ASSERT_EQUAL_INT(0x09, PORTA);
}

void left_test()
{
left();
TEST_ASSERT_EQUAL_INT(0x05, PORTA);
}

void right_test()
{
right();
TEST_ASSERT_EQUAL_INT(0x0A, PORTA);
}

void soft_left_test()
{
soft_left();
TEST_ASSERT_EQUAL_INT(0x04, PORTA);
}

void soft_right_test()
{
soft_right();
TEST_ASSERT_EQUAL_INT(0x02, PORTA);
}

void stop_test()
{
stop();
TEST_ASSERT_EQUAL_INT(0x00, PORTA);
}

void soft_left_2_test()
{
soft_left_2();
TEST_ASSERT_EQUAL_INT(0x01, PORTA);
}

void soft_right_2_test()
{
soft_right_2();
TEST_ASSERT_EQUAL_INT(0x08, PORTA);
}

void test_main() 
{
_delay_ms_CMockExpect(126, 1000);
_delay_ms_CMockExpect(122, 500);
_delay_ms_CMockExpect(126, 1000);
_delay_ms_CMockExpect(122, 500);
_delay_ms_CMockExpect(126, 1000);
_delay_ms_CMockExpect(122, 500);
_delay_ms_CMockExpect(126, 1000);
_delay_ms_CMockExpect(122, 500);
_delay_ms_CMockExpect(126, 1000);
_delay_ms_CMockExpect(122, 500);
_delay_ms_CMockExpect(126, 1000);
_delay_ms_CMockExpect(122, 500);
_delay_ms_CMockExpect(126, 1000);
_delay_ms_CMockExpect(122, 500);
_delay_ms_CMockExpect(126, 1000);
_delay_ms_CMockExpect(122, 1000);
 main_test();
 TEST_ASSERT_EQUAL_INT(0x06, check[0]);
 TEST_ASSERT_EQUAL_INT(0x00, check[1]);
 TEST_ASSERT_EQUAL_INT(0x09, check[2]);
 TEST_ASSERT_EQUAL_INT(0x00, check[3]);
 TEST_ASSERT_EQUAL_INT(0x05, check[4]);
 TEST_ASSERT_EQUAL_INT(0x00, check[5]);
 TEST_ASSERT_EQUAL_INT(0x0A, check[6]);
 TEST_ASSERT_EQUAL_INT(0x00, check[7]);
 TEST_ASSERT_EQUAL_INT(0x04, check[8]);
 TEST_ASSERT_EQUAL_INT(0x00, check[9]);
 TEST_ASSERT_EQUAL_INT(0x02, check[10]);
 TEST_ASSERT_EQUAL_INT(0x00, check[11]);
 TEST_ASSERT_EQUAL_INT(0x01, check[12]);
 TEST_ASSERT_EQUAL_INT(0x00, check[13]);
 TEST_ASSERT_EQUAL_INT(0x08, check[14]);
 TEST_ASSERT_EQUAL_INT(0x00, check[15]); 
 
} 

int main()
{
UNITY_BEGIN();
RUN_TEST(test_main);
RUN_TEST(motion_pin_config_test);
RUN_TEST(forward_test);
RUN_TEST(back_test);
RUN_TEST(left_test);
RUN_TEST(right_test);
RUN_TEST(soft_left_test);
RUN_TEST(soft_right_test);
RUN_TEST(stop_test);
RUN_TEST(soft_left_2_test);
RUN_TEST(soft_right_2_test);
}
