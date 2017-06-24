/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "../../../Unity-master/src/unity.h"
#include "../../../CMock/src/cmock.c"
#include "Mocklcd.h"
char* new_string;
static const char* CMockString_ADC_Conversion_wl_sensor = "ADC_Conversion_wl_sensor";
static const char* CMockString_ADC_conversion = "ADC_conversion";
static const char* CMockString_Ch = "Ch";
static const char* CMockString_Sharp_GP2D12_estimation = "Sharp_GP2D12_estimation";
static const char* CMockString___ms = "__ms";
static const char* CMockString__delay_ms = "_delay_ms";
static const char* CMockString_adc_reading = "adc_reading";
static const char* CMockString_channel = "channel";
static const char* CMockString_cmock_arg1 = "cmock_arg1";
static const char* CMockString_coloumn = "coloumn";
static const char* CMockString_column = "column";
static const char* CMockString_digits = "digits";
static const char* CMockString_init_ports = "init_ports";
static const char* CMockString_lcd_cursor = "lcd_cursor";
static const char* CMockString_lcd_init = "lcd_init";
static const char* CMockString_lcd_line1 = "lcd_line1";
static const char* CMockString_lcd_line2 = "lcd_line2";
static const char* CMockString_lcd_print = "lcd_print";
static const char* CMockString_lcd_reset = "lcd_reset";
static const char* CMockString_lcd_string = "lcd_string";
static const char* CMockString_lcd_wr_char = "lcd_wr_char";
static const char* CMockString_lcd_wr_command = "lcd_wr_command";
static const char* CMockString_print_sensor = "print_sensor";
static const char* CMockString_row = "row";
static const char* CMockString_value = "value";

typedef struct _CMOCK_init_ports_CALL_INSTANCE
{
  int LineNumber;

} CMOCK_init_ports_CALL_INSTANCE;

typedef struct _CMOCK_lcd_reset_CALL_INSTANCE
{
  int LineNumber;

} CMOCK_lcd_reset_CALL_INSTANCE;

typedef struct _CMOCK_lcd_init_CALL_INSTANCE
{
  int LineNumber;

} CMOCK_lcd_init_CALL_INSTANCE;

typedef struct _CMOCK_lcd_wr_command_CALL_INSTANCE
{
  int LineNumber;
  unsigned char Expected_cmock_arg1;

} CMOCK_lcd_wr_command_CALL_INSTANCE;

typedef struct _CMOCK_lcd_wr_char_CALL_INSTANCE
{
  int LineNumber;
  char Expected_cmock_arg1;

} CMOCK_lcd_wr_char_CALL_INSTANCE;

typedef struct _CMOCK_lcd_line1_CALL_INSTANCE
{
  int LineNumber;

} CMOCK_lcd_line1_CALL_INSTANCE;

typedef struct _CMOCK_lcd_line2_CALL_INSTANCE
{
  int LineNumber;

} CMOCK_lcd_line2_CALL_INSTANCE;

typedef struct _CMOCK_lcd_string_CALL_INSTANCE
{
  int LineNumber;
  char* Expected_cmock_arg1;

} CMOCK_lcd_string_CALL_INSTANCE;

typedef struct _CMOCK_lcd_print_CALL_INSTANCE
{
  int LineNumber;
  char Expected_row;
  char Expected_coloumn;
  unsigned int Expected_value;
  int Expected_digits;

} CMOCK_lcd_print_CALL_INSTANCE;

typedef struct _CMOCK__delay_ms_CALL_INSTANCE
{
  int LineNumber;
  double Expected___ms;

} CMOCK__delay_ms_CALL_INSTANCE;

typedef struct _CMOCK_lcd_cursor_CALL_INSTANCE
{
  int LineNumber;
  char Expected_row;
  char Expected_column;

} CMOCK_lcd_cursor_CALL_INSTANCE;

typedef struct _CMOCK_ADC_conversion_CALL_INSTANCE
{
  int LineNumber;
  unsigned char ReturnVal;
  unsigned char Expected_cmock_arg1;

} CMOCK_ADC_conversion_CALL_INSTANCE;

typedef struct _CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE
{
  int LineNumber;
  unsigned int ReturnVal;
  unsigned char Expected_adc_reading;

} CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE;

typedef struct _CMOCK_print_sensor_CALL_INSTANCE
{
  int LineNumber;
  char Expected_row;
  char Expected_coloumn;
  unsigned char Expected_channel;

} CMOCK_print_sensor_CALL_INSTANCE;

typedef struct _CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE
{
  int LineNumber;
  unsigned char ReturnVal;
  unsigned char Expected_Ch;

} CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE;

static struct MocklcdInstance
{
  int init_ports_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE init_ports_CallInstance;
  int lcd_reset_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_reset_CallInstance;
  int lcd_init_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_init_CallInstance;
  int lcd_wr_command_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_wr_command_CallInstance;
  int lcd_wr_char_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_wr_char_CallInstance;
  int lcd_line1_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_line1_CallInstance;
  int lcd_line2_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_line2_CallInstance;
  int lcd_string_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_string_CallInstance;
  int lcd_print_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_print_CallInstance;
  int _delay_ms_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE _delay_ms_CallInstance;
  int lcd_cursor_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE lcd_cursor_CallInstance;
  int ADC_conversion_IgnoreBool;
  unsigned char ADC_conversion_FinalReturn;
  CMOCK_MEM_INDEX_TYPE ADC_conversion_CallInstance;
  int Sharp_GP2D12_estimation_IgnoreBool;
  unsigned int Sharp_GP2D12_estimation_FinalReturn;
  CMOCK_MEM_INDEX_TYPE Sharp_GP2D12_estimation_CallInstance;
  int print_sensor_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE print_sensor_CallInstance;
  int ADC_Conversion_wl_sensor_IgnoreBool;
  unsigned char ADC_Conversion_wl_sensor_FinalReturn;
  CMOCK_MEM_INDEX_TYPE ADC_Conversion_wl_sensor_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mocklcd_Verify(void)
{
  int cmock_line = TEST_LINE_NUM;
  if (Mock.init_ports_IgnoreBool)
    Mock.init_ports_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_init_ports);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.init_ports_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_reset_IgnoreBool)
    Mock.lcd_reset_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_reset);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_reset_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_init_IgnoreBool)
    Mock.lcd_init_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_init);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_init_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_wr_command_IgnoreBool)
    Mock.lcd_wr_command_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_wr_command);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_wr_command_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_wr_char_IgnoreBool)
    Mock.lcd_wr_char_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_wr_char);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_wr_char_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_line1_IgnoreBool)
    Mock.lcd_line1_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_line1);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_line1_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_line2_IgnoreBool)
    Mock.lcd_line2_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_line2);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_line2_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_string_IgnoreBool)
    Mock.lcd_string_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_string);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_string_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_print_IgnoreBool)
    Mock.lcd_print_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_print);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_print_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock._delay_ms_IgnoreBool)
    Mock._delay_ms_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString__delay_ms);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock._delay_ms_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.lcd_cursor_IgnoreBool)
    Mock.lcd_cursor_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_lcd_cursor);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.lcd_cursor_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.ADC_conversion_IgnoreBool)
    Mock.ADC_conversion_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_ADC_conversion);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.ADC_conversion_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Sharp_GP2D12_estimation_IgnoreBool)
    Mock.Sharp_GP2D12_estimation_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Sharp_GP2D12_estimation);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Sharp_GP2D12_estimation_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.print_sensor_IgnoreBool)
    Mock.print_sensor_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_print_sensor);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.print_sensor_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.ADC_Conversion_wl_sensor_IgnoreBool)
    Mock.ADC_Conversion_wl_sensor_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_ADC_Conversion_wl_sensor);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.ADC_Conversion_wl_sensor_CallInstance, cmock_line, CMockStringCalledLess);
}

void Mocklcd_Init(void)
{
  Mocklcd_Destroy();
}

void Mocklcd_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

void init_ports(void)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_init_ports_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_init_ports);
  cmock_call_instance = (CMOCK_init_ports_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.init_ports_CallInstance);
  Mock.init_ports_CallInstance = CMock_Guts_MemNext(Mock.init_ports_CallInstance);
  if (Mock.init_ports_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_CLR_DETAILS();
}

void init_ports_CMockIgnore(void)
{
  Mock.init_ports_IgnoreBool = (int)1;
}

void init_ports_CMockExpect(int cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_init_ports_CALL_INSTANCE));
  CMOCK_init_ports_CALL_INSTANCE* cmock_call_instance = (CMOCK_init_ports_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.init_ports_CallInstance = CMock_Guts_MemChain(Mock.init_ports_CallInstance, cmock_guts_index);
  Mock.init_ports_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  UNITY_CLR_DETAILS();
}

void lcd_reset(void)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_reset_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_reset);
  cmock_call_instance = (CMOCK_lcd_reset_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_reset_CallInstance);
  Mock.lcd_reset_CallInstance = CMock_Guts_MemNext(Mock.lcd_reset_CallInstance);
  if (Mock.lcd_reset_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_CLR_DETAILS();
}

void lcd_reset_CMockIgnore(void)
{
  Mock.lcd_reset_IgnoreBool = (int)1;
}

void lcd_reset_CMockExpect(int cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_reset_CALL_INSTANCE));
  CMOCK_lcd_reset_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_reset_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_reset_CallInstance = CMock_Guts_MemChain(Mock.lcd_reset_CallInstance, cmock_guts_index);
  Mock.lcd_reset_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  UNITY_CLR_DETAILS();
}

void lcd_init(void)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_init_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_init);
  cmock_call_instance = (CMOCK_lcd_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_init_CallInstance);
  Mock.lcd_init_CallInstance = CMock_Guts_MemNext(Mock.lcd_init_CallInstance);
  if (Mock.lcd_init_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_CLR_DETAILS();
}

void lcd_init_CMockIgnore(void)
{
  Mock.lcd_init_IgnoreBool = (int)1;
}

void lcd_init_CMockExpect(int cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_init_CALL_INSTANCE));
  CMOCK_lcd_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_init_CallInstance = CMock_Guts_MemChain(Mock.lcd_init_CallInstance, cmock_guts_index);
  Mock.lcd_init_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  UNITY_CLR_DETAILS();
}

void lcd_wr_command(unsigned char cmock_arg1)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_wr_command_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_wr_command);
  cmock_call_instance = (CMOCK_lcd_wr_command_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_wr_command_CallInstance);
  Mock.lcd_wr_command_CallInstance = CMock_Guts_MemNext(Mock.lcd_wr_command_CallInstance);
  if (Mock.lcd_wr_command_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_lcd_wr_command,CMockString_cmock_arg1);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_cmock_arg1, cmock_arg1, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_lcd_wr_command(CMOCK_lcd_wr_command_CALL_INSTANCE* cmock_call_instance, unsigned char cmock_arg1)
{
  cmock_call_instance->Expected_cmock_arg1 = cmock_arg1;
}

void lcd_wr_command_CMockIgnore(void)
{
  Mock.lcd_wr_command_IgnoreBool = (int)1;
}

void lcd_wr_command_CMockExpect(int cmock_line, unsigned char cmock_arg1)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_wr_command_CALL_INSTANCE));
  CMOCK_lcd_wr_command_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_wr_command_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_wr_command_CallInstance = CMock_Guts_MemChain(Mock.lcd_wr_command_CallInstance, cmock_guts_index);
  Mock.lcd_wr_command_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_lcd_wr_command(cmock_call_instance, cmock_arg1);
  UNITY_CLR_DETAILS();
}

void lcd_wr_char(char cmock_arg1)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_wr_char_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_wr_char);
  cmock_call_instance = (CMOCK_lcd_wr_char_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_wr_char_CallInstance);
  Mock.lcd_wr_char_CallInstance = CMock_Guts_MemNext(Mock.lcd_wr_char_CallInstance);
  if (Mock.lcd_wr_char_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_lcd_wr_char,CMockString_cmock_arg1);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_cmock_arg1, cmock_arg1, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_lcd_wr_char(CMOCK_lcd_wr_char_CALL_INSTANCE* cmock_call_instance, char cmock_arg1)
{
  cmock_call_instance->Expected_cmock_arg1 = cmock_arg1;
}

void lcd_wr_char_CMockIgnore(void)
{
  Mock.lcd_wr_char_IgnoreBool = (int)1;
}

void lcd_wr_char_CMockExpect(int cmock_line, char cmock_arg1)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_wr_char_CALL_INSTANCE));
  CMOCK_lcd_wr_char_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_wr_char_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_wr_char_CallInstance = CMock_Guts_MemChain(Mock.lcd_wr_char_CallInstance, cmock_guts_index);
  Mock.lcd_wr_char_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_lcd_wr_char(cmock_call_instance, cmock_arg1);
  UNITY_CLR_DETAILS();
}

void lcd_line1(void)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_line1_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_line1);
  cmock_call_instance = (CMOCK_lcd_line1_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_line1_CallInstance);
  Mock.lcd_line1_CallInstance = CMock_Guts_MemNext(Mock.lcd_line1_CallInstance);
  if (Mock.lcd_line1_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_CLR_DETAILS();
}

void lcd_line1_CMockIgnore(void)
{
  Mock.lcd_line1_IgnoreBool = (int)1;
}

void lcd_line1_CMockExpect(int cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_line1_CALL_INSTANCE));
  CMOCK_lcd_line1_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_line1_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_line1_CallInstance = CMock_Guts_MemChain(Mock.lcd_line1_CallInstance, cmock_guts_index);
  Mock.lcd_line1_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  UNITY_CLR_DETAILS();
}

void lcd_line2(void)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_line2_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_line2);
  cmock_call_instance = (CMOCK_lcd_line2_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_line2_CallInstance);
  Mock.lcd_line2_CallInstance = CMock_Guts_MemNext(Mock.lcd_line2_CallInstance);
  if (Mock.lcd_line2_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_CLR_DETAILS();
}

void lcd_line2_CMockIgnore(void)
{
  Mock.lcd_line2_IgnoreBool = (int)1;
}

void lcd_line2_CMockExpect(int cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_line2_CALL_INSTANCE));
  CMOCK_lcd_line2_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_line2_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_line2_CallInstance = CMock_Guts_MemChain(Mock.lcd_line2_CallInstance, cmock_guts_index);
  Mock.lcd_line2_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  UNITY_CLR_DETAILS();
}

void lcd_string(char* cmock_arg1)
{
new_string = (char*)malloc(sizeof(char) * strlen(cmock_arg1)+1);
int count = 0;
  //int sdfk = strlen(cmock_arg1);	
  //printf("%i",sdfk);
  for(int i = 0; i < strlen(cmock_arg1)+1; i++)
	{

		//printf("%i\n",cmock_arg1[i]);
		if (!(cmock_arg1[i] ==  32))
		{
		
			new_string[count++] = cmock_arg1[i];
			//printf("%i\n",new_string[i]);
			

		}	
		else
		{
			//i++;
			new_string[count++] = cmock_arg1[i+1];
			//printf("%i\n",new_string[i]);
			i++;

		}
	new_string[count] = '\0';
	
		//printf("%s\n",&new_string[i]);
	} 

//printf("%s\n",new_string);
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_string_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_string);
  cmock_call_instance = (CMOCK_lcd_string_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_string_CallInstance);
  Mock.lcd_string_CallInstance = CMock_Guts_MemNext(Mock.lcd_string_CallInstance);
  if (Mock.lcd_string_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_lcd_string,CMockString_cmock_arg1);
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_cmock_arg1, cmock_arg1, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_lcd_string(CMOCK_lcd_string_CALL_INSTANCE* cmock_call_instance, char* cmock_arg1)
{
  cmock_call_instance->Expected_cmock_arg1 = cmock_arg1;
}

void lcd_string_CMockIgnore(void)
{
  Mock.lcd_string_IgnoreBool = (int)1;
}

void lcd_string_CMockExpect(int cmock_line, char* cmock_arg1)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_string_CALL_INSTANCE));
  CMOCK_lcd_string_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_string_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_string_CallInstance = CMock_Guts_MemChain(Mock.lcd_string_CallInstance, cmock_guts_index);
  Mock.lcd_string_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_lcd_string(cmock_call_instance, cmock_arg1);
  UNITY_CLR_DETAILS();
}

void lcd_print(char row, char coloumn, unsigned int value, int digits)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_print_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_print);
  cmock_call_instance = (CMOCK_lcd_print_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_print_CallInstance);
  Mock.lcd_print_CallInstance = CMock_Guts_MemNext(Mock.lcd_print_CallInstance);
  if (Mock.lcd_print_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_lcd_print,CMockString_row);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_row, row, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_lcd_print,CMockString_coloumn);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_coloumn, coloumn, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_lcd_print,CMockString_value);
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_value, value, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_lcd_print,CMockString_digits);
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_digits, digits, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_lcd_print(CMOCK_lcd_print_CALL_INSTANCE* cmock_call_instance, char row, char coloumn, unsigned int value, int digits)
{
  cmock_call_instance->Expected_row = row;
  cmock_call_instance->Expected_coloumn = coloumn;
  cmock_call_instance->Expected_value = value;
  cmock_call_instance->Expected_digits = digits;
}

void lcd_print_CMockIgnore(void)
{
  Mock.lcd_print_IgnoreBool = (int)1;
}

void lcd_print_CMockExpect(int cmock_line, char row, char coloumn, unsigned int value, int digits)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_print_CALL_INSTANCE));
  CMOCK_lcd_print_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_print_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_print_CallInstance = CMock_Guts_MemChain(Mock.lcd_print_CallInstance, cmock_guts_index);
  Mock.lcd_print_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_lcd_print(cmock_call_instance, row, coloumn, value, digits);
  UNITY_CLR_DETAILS();
}

void _delay_ms(double __ms)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK__delay_ms_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString__delay_ms);
  cmock_call_instance = (CMOCK__delay_ms_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock._delay_ms_CallInstance);
  Mock._delay_ms_CallInstance = CMock_Guts_MemNext(Mock._delay_ms_CallInstance);
  if (Mock._delay_ms_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString__delay_ms,CMockString___ms);
    UNITY_TEST_ASSERT_EQUAL_FLOAT(cmock_call_instance->Expected___ms, __ms, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters__delay_ms(CMOCK__delay_ms_CALL_INSTANCE* cmock_call_instance, double __ms)
{
  cmock_call_instance->Expected___ms = __ms;
}

void _delay_ms_CMockIgnore(void)
{
  Mock._delay_ms_IgnoreBool = (int)1;
}

void _delay_ms_CMockExpect(int cmock_line, double __ms)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK__delay_ms_CALL_INSTANCE));
  CMOCK__delay_ms_CALL_INSTANCE* cmock_call_instance = (CMOCK__delay_ms_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock._delay_ms_CallInstance = CMock_Guts_MemChain(Mock._delay_ms_CallInstance, cmock_guts_index);
  Mock._delay_ms_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters__delay_ms(cmock_call_instance, __ms);
  UNITY_CLR_DETAILS();
}

void lcd_cursor(char row, char column)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_lcd_cursor_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcd_cursor);
  cmock_call_instance = (CMOCK_lcd_cursor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcd_cursor_CallInstance);
  Mock.lcd_cursor_CallInstance = CMock_Guts_MemNext(Mock.lcd_cursor_CallInstance);
  if (Mock.lcd_cursor_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_lcd_cursor,CMockString_row);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_row, row, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_lcd_cursor,CMockString_column);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_column, column, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_lcd_cursor(CMOCK_lcd_cursor_CALL_INSTANCE* cmock_call_instance, char row, char column)
{
  cmock_call_instance->Expected_row = row;
  cmock_call_instance->Expected_column = column;
}

void lcd_cursor_CMockIgnore(void)
{
  Mock.lcd_cursor_IgnoreBool = (int)1;
}

void lcd_cursor_CMockExpect(int cmock_line, char row, char column)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcd_cursor_CALL_INSTANCE));
  CMOCK_lcd_cursor_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcd_cursor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcd_cursor_CallInstance = CMock_Guts_MemChain(Mock.lcd_cursor_CallInstance, cmock_guts_index);
  Mock.lcd_cursor_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_lcd_cursor(cmock_call_instance, row, column);
  UNITY_CLR_DETAILS();
}

unsigned char ADC_conversion(unsigned char cmock_arg1)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_ADC_conversion_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_ADC_conversion);
  cmock_call_instance = (CMOCK_ADC_conversion_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.ADC_conversion_CallInstance);
  Mock.ADC_conversion_CallInstance = CMock_Guts_MemNext(Mock.ADC_conversion_CallInstance);
  if (Mock.ADC_conversion_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.ADC_conversion_FinalReturn;
    Mock.ADC_conversion_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_ADC_conversion,CMockString_cmock_arg1);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_cmock_arg1, cmock_arg1, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_ADC_conversion(CMOCK_ADC_conversion_CALL_INSTANCE* cmock_call_instance, unsigned char cmock_arg1)
{
  cmock_call_instance->Expected_cmock_arg1 = cmock_arg1;
}

void ADC_conversion_CMockIgnoreAndReturn(int cmock_line, unsigned char cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_ADC_conversion_CALL_INSTANCE));
  CMOCK_ADC_conversion_CALL_INSTANCE* cmock_call_instance = (CMOCK_ADC_conversion_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.ADC_conversion_CallInstance = CMock_Guts_MemChain(Mock.ADC_conversion_CallInstance, cmock_guts_index);
  Mock.ADC_conversion_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.ADC_conversion_IgnoreBool = (int)1;
}

void ADC_conversion_CMockExpectAndReturn(int cmock_line, unsigned char cmock_arg1, unsigned char cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_ADC_conversion_CALL_INSTANCE));
  CMOCK_ADC_conversion_CALL_INSTANCE* cmock_call_instance = (CMOCK_ADC_conversion_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.ADC_conversion_CallInstance = CMock_Guts_MemChain(Mock.ADC_conversion_CallInstance, cmock_guts_index);
  Mock.ADC_conversion_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_ADC_conversion(cmock_call_instance, cmock_arg1);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

unsigned int Sharp_GP2D12_estimation(unsigned char adc_reading)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Sharp_GP2D12_estimation);
  cmock_call_instance = (CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Sharp_GP2D12_estimation_CallInstance);
  Mock.Sharp_GP2D12_estimation_CallInstance = CMock_Guts_MemNext(Mock.Sharp_GP2D12_estimation_CallInstance);
  if (Mock.Sharp_GP2D12_estimation_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.Sharp_GP2D12_estimation_FinalReturn;
    Mock.Sharp_GP2D12_estimation_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_Sharp_GP2D12_estimation,CMockString_adc_reading);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_adc_reading, adc_reading, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_Sharp_GP2D12_estimation(CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE* cmock_call_instance, unsigned char adc_reading)
{
  cmock_call_instance->Expected_adc_reading = adc_reading;
}

void Sharp_GP2D12_estimation_CMockIgnoreAndReturn(int cmock_line, unsigned int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE));
  CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE* cmock_call_instance = (CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Sharp_GP2D12_estimation_CallInstance = CMock_Guts_MemChain(Mock.Sharp_GP2D12_estimation_CallInstance, cmock_guts_index);
  Mock.Sharp_GP2D12_estimation_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.Sharp_GP2D12_estimation_IgnoreBool = (int)1;
}

void Sharp_GP2D12_estimation_CMockExpectAndReturn(int cmock_line, unsigned char adc_reading, unsigned int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE));
  CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE* cmock_call_instance = (CMOCK_Sharp_GP2D12_estimation_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Sharp_GP2D12_estimation_CallInstance = CMock_Guts_MemChain(Mock.Sharp_GP2D12_estimation_CallInstance, cmock_guts_index);
  Mock.Sharp_GP2D12_estimation_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_Sharp_GP2D12_estimation(cmock_call_instance, adc_reading);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void print_sensor(char row, char coloumn, unsigned char channel)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_print_sensor_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_print_sensor);
  cmock_call_instance = (CMOCK_print_sensor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.print_sensor_CallInstance);
  Mock.print_sensor_CallInstance = CMock_Guts_MemNext(Mock.print_sensor_CallInstance);
  if (Mock.print_sensor_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_print_sensor,CMockString_row);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_row, row, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_print_sensor,CMockString_coloumn);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_coloumn, coloumn, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_print_sensor,CMockString_channel);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_channel, channel, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_print_sensor(CMOCK_print_sensor_CALL_INSTANCE* cmock_call_instance, char row, char coloumn, unsigned char channel)
{
  cmock_call_instance->Expected_row = row;
  cmock_call_instance->Expected_coloumn = coloumn;
  cmock_call_instance->Expected_channel = channel;
}

void print_sensor_CMockIgnore(void)
{
  Mock.print_sensor_IgnoreBool = (int)1;
}

void print_sensor_CMockExpect(int cmock_line, char row, char coloumn, unsigned char channel)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_print_sensor_CALL_INSTANCE));
  CMOCK_print_sensor_CALL_INSTANCE* cmock_call_instance = (CMOCK_print_sensor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.print_sensor_CallInstance = CMock_Guts_MemChain(Mock.print_sensor_CallInstance, cmock_guts_index);
  Mock.print_sensor_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_print_sensor(cmock_call_instance, row, coloumn, channel);
  UNITY_CLR_DETAILS();
}

unsigned char ADC_Conversion_wl_sensor(unsigned char Ch)
{
  int cmock_line = TEST_LINE_NUM;
  CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_ADC_Conversion_wl_sensor);
  cmock_call_instance = (CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.ADC_Conversion_wl_sensor_CallInstance);
  Mock.ADC_Conversion_wl_sensor_CallInstance = CMock_Guts_MemNext(Mock.ADC_Conversion_wl_sensor_CallInstance);
  if (Mock.ADC_Conversion_wl_sensor_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.ADC_Conversion_wl_sensor_FinalReturn;
    Mock.ADC_Conversion_wl_sensor_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_ADC_Conversion_wl_sensor,CMockString_Ch);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_Ch, Ch, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_ADC_Conversion_wl_sensor(CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE* cmock_call_instance, unsigned char Ch)
{
  cmock_call_instance->Expected_Ch = Ch;
}

void ADC_Conversion_wl_sensor_CMockIgnoreAndReturn(int cmock_line, unsigned char cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE));
  CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE* cmock_call_instance = (CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.ADC_Conversion_wl_sensor_CallInstance = CMock_Guts_MemChain(Mock.ADC_Conversion_wl_sensor_CallInstance, cmock_guts_index);
  Mock.ADC_Conversion_wl_sensor_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.ADC_Conversion_wl_sensor_IgnoreBool = (int)1;
}

void ADC_Conversion_wl_sensor_CMockExpectAndReturn(int cmock_line, unsigned char Ch, unsigned char cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE));
  CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE* cmock_call_instance = (CMOCK_ADC_Conversion_wl_sensor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.ADC_Conversion_wl_sensor_CallInstance = CMock_Guts_MemChain(Mock.ADC_Conversion_wl_sensor_CallInstance, cmock_guts_index);
  Mock.ADC_Conversion_wl_sensor_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_ADC_Conversion_wl_sensor(cmock_call_instance, Ch);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

