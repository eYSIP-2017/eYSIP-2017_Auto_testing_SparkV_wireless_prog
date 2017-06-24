# This make file generates Tests as well as builds for a given submission

Test: Compile
	./Test0.elf > ./Test_Results/Submission1.txt
	./Test1.elf > ./Test_Results/Submission2.txt
	./Test2.elf > ./Test_Results/Submission3.txt
	./Test3.elf > ./Test_Results/Submission4.txt
	./Test4.elf > ./Test_Results/Submission5.txt
	./Test5.elf > ./Test_Results/Submission6.txt
	./Test6.elf > ./Test_Results/Submission7.txt
	
Compile: 
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment1.c Experiment_1_test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test0.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment2.c Experiment_1_test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test1.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment3.c Experiment_1_test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test2.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment4.c Experiment_1_test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test3.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment5.c Experiment_1_test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test4.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment6.c Experiment_1_test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test5.elf
	gcc -Os -DTEST -std=c99 ./Submissions/Experiment7.c Experiment_1_test.c ../../../../CMock/lib/mocks/Mock_ms_delay.c ../../../../Unity-master/src/unity.c -o ./Test6.elf
	
clean:
	rm -rf *.o  Makefile1 *.elf ./Temp *.txt 
