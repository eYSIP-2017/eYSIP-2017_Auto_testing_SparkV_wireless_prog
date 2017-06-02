# This make file generates Tests as well as builds for a given submission

Testing: Open_Results

Open_Results: Test
	gedit Results/Submission_1.csv

Test: Compile
	./Testing/Test > Results/Submission_1.csv
	
Compile: 
	gcc -Os -DTEST -std=c99 Program/Buzzer_Beep3.c Testing/Test.c ../../CMock/lib/mocks/Mock_ms_delay.c ../../Unity-master/src/unity.c -o Testing/Test


Build: Buzzer_Beep.elf
	avr-objcopy -j .text -j .data -O ihex Hex/Buzzer_Beep.elf /Hex/Buzzer_Beep.hex
	rm -rf Hex/Buzzer_Beep.elf

Buzzer_Beep.elf: Buzzer_Beep.o 
	avr-gcc -g -mmcu=atmega2560 -o Hex/Buzzer_Beep.elf Program/Buzzer_Beep.o 	 

Buzzer_Beep.o: /home/vinay/Desktop/EYSIP_TASKS/Task-4/Program/Buzzer_Beep.c 
	avr-gcc -g -Os -mmcu=atmega2560 -c Program/Buzzer_Beep.c 


