#define __builtin_avr_delay_cycles
#include </usr/lib/avr/include/avr/io.h>
#include "../../../Unity-master/src/unity.h"
#include "Buzzer_Beep.h"
#include "../../../CMock/lib/mocks/Mock_ms_delay.h"
#include <stdio.h>

void test_main_1()
{
printf("TESTING main FUNCTION\n");
printf("Initial value of DDRC = 0x%#02x\n",DDRC);
printf("Initial value of PORTC = 0x%#02x\n",PORTC);
_delay_ms_CMockExpect(122, 10000);
_delay_ms_CMockExpect(126, 1000);
main_test();
printf("After execution of the main function the value of DDRC = %#03x\n",DDRC);
printf("After the execution of the main function value of PORTC = 0x%#03x\n",PORTC);
TEST_ASSERT_EQUAL_INT (0x08, DDRC);
TEST_ASSERT_EQUAL_INT (0x00, PORTC);
}

void test_buzzer_on()
{
printf("TESTING buzzer_on FUNCTION\n");
printf("Initial value of DDRC = %#03x\n",DDRC);
printf("Initial value of PORTC = 0x%#03x\n",PORTC);
buzzer_on();
printf("After execution of the buzzer_on function the value of DDRC = %#03x\n",DDRC);
printf("After the execution of the buzzer_on function value of PORTC = %#03x\n",PORTC);
TEST_ASSERT_EQUAL_INT (0x08, PORTC);
}

void test_buzzer_off()
{
printf("TESTING buzzer_off FUNCTION\n");
printf("Initial value of DDRC = %#03x\n",DDRC);
printf("Initial value of PORTC = %#03x\n",PORTC);
buzzer_off();
printf("After execution of the buzzer_off function the value of DDRC = %#03x\n",DDRC);
printf("After the execution of the buzzer_off function value of PORTC = 0x%#03x\n",PORTC);
TEST_ASSERT_EQUAL_INT (0x00, PORTC);
}

int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_main_1);
printf("\n");
RUN_TEST(test_buzzer_on);
printf("\n");
RUN_TEST(test_buzzer_off);
printf("\n");
return UNITY_END();
}
