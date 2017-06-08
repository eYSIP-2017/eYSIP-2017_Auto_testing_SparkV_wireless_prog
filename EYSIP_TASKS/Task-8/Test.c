#include </usr/lib/avr/include/avr/io.h>
#include "../../Unity-master/src/unity.h"
#include <stdio.h>
//#include"../../CMock/lib/mocks/MockADC_Function_Header.h"


void lcd_port_config (void);
void adc_pin_config (void);
void motion_pin_config (void); 
void test_port_init(void);
void timer5_init(void);

void test_timer5_init()
{
timer5_init();
TEST_ASSERT_EQUAL_INT(0xFF,TCNT5H);
TEST_ASSERT_EQUAL_INT(0x01,TCNT5L);
TEST_ASSERT_EQUAL_INT(0x00,OCR5AH);
TEST_ASSERT_EQUAL_INT(0xFF,OCR5AL);
TEST_ASSERT_EQUAL_INT(0x00,OCR5BH);
TEST_ASSERT_EQUAL_INT(0xFF,OCR5BL);
TEST_ASSERT_EQUAL_INT(0x00,OCR5CH);
TEST_ASSERT_EQUAL_INT(0xFF,OCR5CL);
TEST_ASSERT_EQUAL_INT(0xA9,TCCR5A);
TEST_ASSERT_EQUAL_INT(0x0B,TCCR5B);
}

void test_motion_pin_config()
{
motion_pin_config();
TEST_ASSERT_EQUAL_INT(0x0F,DDRA);
TEST_ASSERT_EQUAL_INT(0x00,PORTA);
TEST_ASSERT_EQUAL_INT(0x18,DDRL);
TEST_ASSERT_EQUAL_INT(0x18,PORTL);
} 
void test_adc_pin_config()
{
adc_pin_config();
TEST_ASSERT_EQUAL_INT(0x00,DDRF);
TEST_ASSERT_EQUAL_INT(0x00,PORTF);
TEST_ASSERT_EQUAL_INT(0x00,DDRK);
TEST_ASSERT_EQUAL_INT(0x00,PORTK);
}

void test_lcd_port_config ()
{
lcd_port_config();
TEST_ASSERT_EQUAL_INT(0xF7,DDRC);
TEST_ASSERT_EQUAL_INT(0x00,PORTC);
}

void test_port_init()
{
port_init();
test_lcd_port_config();
test_adc_pin_config();
test_motion_pin_config();	
}


int main()
{
UNITY_BEGIN();
RUN_TEST(test_port_init);
RUN_TEST(test_motion_pin_config);
RUN_TEST(test_lcd_port_config);
RUN_TEST(test_adc_pin_config);
RUN_TEST(test_timer5_init);

