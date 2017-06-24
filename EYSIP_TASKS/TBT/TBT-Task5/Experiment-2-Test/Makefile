# This make file generates Tests as well as builds for a given submission

Test: Compile
	./Test0.elf > ./Test_Results/Submission1.txt
	./Test1.elf > ./Test_Results/Submission2.txt
	./Test2.elf > ./Test_Results/Submission3.txt
	./Test3.elf > ./Test_Results/Submission4.txt
	
Compile: 
	gcc -Os -DTEST -std=c99 ./Submissions/Experimen1.c Experiment-2-test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test0.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment2.c Experiment-2-test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test1.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment3.c Experiment-2-test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test2.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment4.c Experiment-2-test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test3.elf
	
clean:
	rm -rf *.o  Makefile1 *.elf Temp 
