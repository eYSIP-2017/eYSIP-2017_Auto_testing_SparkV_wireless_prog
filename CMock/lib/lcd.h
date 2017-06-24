void init_ports();
void lcd_reset();
void lcd_init();
void lcd_wr_command(unsigned char);
void lcd_wr_char(char);
void lcd_line1();
void lcd_line2();
void lcd_string(char*);
void lcd_print (char row, char coloumn, unsigned int value, int digits);
void _delay_ms(double __ms);
void lcd_cursor (char row, char column);
unsigned char ADC_conversion(unsigned char);
unsigned int Sharp_GP2D12_estimation(unsigned char adc_reading);
void print_sensor(char row, char coloumn,unsigned char channel);
unsigned char ADC_Conversion_wl_sensor(unsigned char Ch);

