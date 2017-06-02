// Header file to be included with the UNIT test inorder to forward declare the required functions.
#ifndef Bar_LED
#define Bar_LED

void Bar_LED_Config(void);

void port_init();

void clear();

void Set_LED(int x);

void disable_Bar_LED();

#endif
