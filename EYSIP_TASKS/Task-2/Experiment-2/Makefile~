#This Makfile is used to generate the .hex, .elf, and .map files for Experiment-2. 
all: Final

Final: Experiment-2.map Experiment-2.lst Experiment-2.lst
	avr-objcopy -j .text -j .data -O ihex Experiment-2.elf Experiment-2.hex

Experiment-2.map: Experiment-2.elf 
	avr-gcc -g -mmcu=atmega2560 -Wl,-Map,Experiment-2.map -o Experiment-2.elf Experiment-2.o LCD.o

Experiment-2.lst: Experiment-2.elf
	avr-objdump -h -S Experiment-2.elf > Experiment-2.lst	 

Experiment-2.elf: Experiment-2.o
	avr-gcc -g -mmcu=atmega2560 -o Experiment-2.elf Experiment-2.o LCD.o 	 
Experiment-2.o: Experiment-2.c
	avr-gcc -g -Os -mmcu=atmega2560 -c Experiment-2.c LCD.c	 

clean:
	rm -rf *.o Experiment-2.elf *.eps *.png *.pdf *.bak 
	rm -rf *.lst *.map *.hex *.bin *.srec
