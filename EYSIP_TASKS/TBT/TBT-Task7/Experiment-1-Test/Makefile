# This make file generates Tests as well as builds for a given submission

Test: Compile
	./Test0.elf > ./Test_Results/Submission1.txt
	
Compile: 
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment1.c Experiment_1_test.c ../../../../CMock/lib/mocks/MockTBT7.c ../../../../Unity-master/src/unity.c -o ./Test0.elf
	
clean:
	rm -rf *.o  Makefile1 *.elf ./Temp output.csv
