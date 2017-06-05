# This make file generates Tests as well as builds for a given submission

Testing: Open_Results

Open_Results: Test
	gedit Results/Submission_1.csv

Test: Compile
	./Testing/Test > Results/Submission_1.csv
	
Compile: 
	gcc -Os -DTEST -std=c99 Program/Motion_Controll_Simple3.c Testing/Test.c ../../CMock/lib/mocks/Mock_ms_delay.c ../../Unity-master/src/unity.c -o Testing/Test


Build: Buzzer_Beep.elf
	avr-objcopy -j .text -j .data -O ihex Hex/Motion_Controll_Simple.elf Hex/Motion_Controll_Simple.hex
	rm -rf Hex/Motion_Controll_Simple.elf

Motion_Controll_simple.elf: Motion_Controll_simple.o 
	avr-gcc -g -mmcu=atmega2560 -o Hex/Motion_Controll_Simple.elf Program/Motion_Controll_Simple.o 	 

Motion_Controll_simple.o: Program/Motion_Controll_simple.c 
	avr-gcc -g -Os -mmcu=atmega2560 -c Program/Motion_Controll_Simple.c 


