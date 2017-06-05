all: Final

Final: Bar_LED.map Bar_LED.lst 
	avr-objcopy -j .text -j .data -O ihex Bar_LED.elf Bar_LED.hex

Bar_LED.map: Bar_LED.elf 
	avr-gcc -g -mmcu=atmega2560 -Wl,-Map,Bar_LED.map -o Bar_LED.elf Bar_LED.o

Bar_LED.lst: Bar_LED.elf
	avr-objdump -h -S Bar_LED.elf > Bar_LED.lst	 

Bar_LED.elf: Bar_LED.o
	avr-gcc -g -mmcu=atmega2560 -o Bar_LED.elf Bar_LED.o 	 
Bar_LED.o: Bar_LED.c
	avr-gcc -g -Os -mmcu=atmega2560 -c Bar_LED.c	 

clean:
	rm -rf *.o  *.eps *.png *.pdf *.bak 
	rm -rf *.lst *.map *.hex *.bin *.srec
