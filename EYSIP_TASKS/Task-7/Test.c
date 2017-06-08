#include </usr/lib/avr/include/avr/io.h>
#include "../../Unity-master/src/unity.h"
#include <stdio.h>
#include"../../CMock/lib/mocks/MockADC_Function_Header.h"

unsigned int Sharp_GP2D12_estimation1(unsigned char adc_reading);
unsigned char ADC_Conversion1(unsigned char Ch);
void lcd_port_config(void);
void adc_init(void);
void adc_pin_config (void);
void port_init(void);
void init_devices (void); 
int main_test(void);


extern int check[];
extern int check1[];
extern int check2[];
int check3[16] = {32,33,34,35,36,37,38,39,32,33,34,35,36,37,38,39 };
extern float BATT_Voltage;


void test_adc_pin_config()
{
TEST_ASSERT_EQUAL_INT(0x00, DDRF);
TEST_ASSERT_EQUAL_INT(0x00, PORTF);
TEST_ASSERT_EQUAL_INT(0x00, DDRA);
TEST_ASSERT_EQUAL_INT(0x00, PORTA);
}

void test_lcd_port_config()
{
lcd_port_config();
TEST_ASSERT_EQUAL_INT(0xF7, DDRC);
TEST_ASSERT_EQUAL_INT(0x0, PORTC);
}


void test_adc_init()
{
adc_init();
TEST_ASSERT_EQUAL_INT(0x00, check[0]);
TEST_ASSERT_EQUAL_INT(0x86, check[1]);
TEST_ASSERT_EQUAL_INT(0x00, ADCSRB);
TEST_ASSERT_EQUAL_INT(0x20, ADMUX);

}

void test_port_init()
{
 adc_pin_config();
 lcd_port_config();
 test_adc_pin_config();
 test_lcd_port_config();
}

void test_init_devices()
{
 port_init();
 adc_init();
 test_port_init();
 test_adc_init();
}

void test_sharp()
{
  for(unsigned int i = 0; i < 1024; i++)
 	 {
        	unsigned test = Sharp_GP2D12_estimation1(i);
   	        TEST_ASSERT_TRUE (test <= 800 & test >= 0);
	  }
} 

void test_ADC()
{
  for(unsigned int i = 1; i <=16 ; i++)	
	{
       ADC_Conversion1(i);
	 if (i > 7)
		{
		    TEST_ASSERT_EQUAL_INT(0x08, check1[0] );

		}	 
	else 
		{
		    TEST_ASSERT_EQUAL_INT(0x00, check1[0]);
		}
	if (i < 16)

		{
		    TEST_ASSERT_EQUAL_INT(check3[i], check2[0]);
		}	
	TEST_ASSERT_EQUAL_INT(0x50, check[1]);
	TEST_ASSERT_EQUAL_INT(0x00, check1[1]);
	}

}
void main_test1()
{
ADC_Conversion_CMockExpectAndReturn(1,0,0);
ADC_Conversion_CMockExpectAndReturn(1,0,0);
lcd_print_CMockExpect(1,1,1,.7,4);
print_sensor_CMockExpect(1,1,1,0);
print_sensor_CMockExpect(1,1,6,5);							
print_sensor_CMockExpect(1,1,10,6);							
print_sensor_CMockExpect(1,1,14,7);							
print_sensor_CMockExpect(1,2,2,3);							
print_sensor_CMockExpect(1,2,6,2);							
print_sensor_CMockExpect(1,2,10,1);							
print_sensor_CMockExpect(1,2,9,11); 
ADC_Conversion_CMockExpectAndReturn(1,11,0x05);
Sharp_GP2D12_estimation_CMockExpectAndReturn(1,0x05,400);
lcd_print_CMockExpect(1,2,14,400,3);
main_test();
TEST_ASSERT_EQUAL_FLOAT(.7,BATT_Voltage);
test_init_devices();
} 



int main()
{
UNITY_BEGIN();
RUN_TEST(test_ADC);
RUN_TEST(test_adc_init);
RUN_TEST(test_lcd_port_config);
RUN_TEST(test_adc_pin_config);
RUN_TEST(test_port_init);
RUN_TEST(test_sharp);
RUN_TEST(test_init_devices);
RUN_TEST(main_test1);
}
