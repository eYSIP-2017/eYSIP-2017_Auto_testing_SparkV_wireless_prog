# Makefile to compile link and create an executable for the simple math functions.
all: Final

Final: Main_Math.o function_Factorial.o function_GCD.o Arithmetic_Header.h
	gcc Main_Math.c function_Factorial.c function_GCD.c -o Task

Main_Math.o: Main_Math.c
	gcc -c Main_Math.c	 

function_Factorial.o: function_Factorial.c
	gcc -c function_Factorial.c	 

function_GCD.o: function_GCD.c
	gcc -c function_GCD.c	 

Test: Test.o Arithmetic.o 
	gcc Test.c Arithmetic.c /home/vinay/Desktop/Unity-master/src/unity.c -o Test

Test.o: Test.c
	gcc -c Test.c

Arithmetic.o: Arithmetic.c
	gcc -c Arithmetic.c 

clean:
	rm -r *o Task Test
