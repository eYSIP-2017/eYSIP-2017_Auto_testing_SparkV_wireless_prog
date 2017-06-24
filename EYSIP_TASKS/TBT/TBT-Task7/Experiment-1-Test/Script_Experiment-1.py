#This is the script that is to be run for automatic evaluation and building of submissions.
import re
import os
import glob
import shutil
totalmarks = 0.0
i = 0
list_of_files = sorted(glob.glob('./Submissions/*.c'))

path_to_mocked_function_header = "../../../../../CMock/lib/mocks/MockTBT7.h"
path_to_mocked_function_c = "../../../../CMock/lib/mocks/MockTBT7.c"
path_to_untiy = "../../../../Unity-master/src/unity.c"
path_to_avr_io = "/usr/lib/avr/include/avr/"


def open_submissions():
	q = 0
	for file_name in list_of_files:
		os.system("geany " + list_of_files[q])
		q += 1

def Find_Team_ID():
	k = 0  
	for file_name in list_of_files:
		temp = open( './Grades/Submission' +str(k+1)+ '.csv' ,'w')
		with open(file_name, 'r') as file1:
		    for line in file1:
			if re.search("ID.",line):
				temp.write("Team ID," + line)
		    k +=1


def check_CPU_frequency(): # function is used to check wether the student has used the correct CPU Frequency
	global totalmarks
	global i  
	for file_name in list_of_files:
		temp = open( './Grades/Submission' +str(i+1)+ '.csv' ,'a')
		with open(file_name, 'r') as file1:
		    for line in file1:
			if '#define F_CPU' in line:
				if '14745600' in line:
					temp.write('1. Correct CPU Frequency, 0 Mark\n') 
					totalmarks += 1
					temp.close
				else:
					temp.write('1. Incorrect CPU Frequency, 0 Mark\n')
					temp.close
		    i += 1		

def remove_infinite_loops(): # function is used to remove any infinite loops within a submission so as to allow that function to be tested       
	global i
	i = 0 
	os.system("mkdir Temp")
	list_of_temp = sorted(glob.glob('./Temp/*.c'))
	for file_name in list_of_files:
		delete = ["while(1)", "while (1)", "while(1);"]
		file_in = open(list_of_files[i])
		file_out = open( './Temp/Temp' +str(i+1)+ '.c' ,'w')
		for line in file_in:
		    for word in delete:
			line = line.replace(word, "for (int qwer = 1; qwer > 0; qwer-- );")
		    file_out.write(line)
		i +=1
		file_in.close()
		file_out.close()


def copy():
	global i
	i = 0 
	list_of_temp = sorted(glob.glob('./Temp/*.c'))
	for file_name in list_of_files:
		file_in = open(list_of_files[i],"w")
		file_out = open(list_of_temp[i],"r")
		for line in file_out:
			file_in.write(line);
		i +=1
		file_in.close()
		file_out.close()
def copy_makefile():
	file_in = open("Makefile","w")
	file_out = open("Makefile1","r")
	for line in file_out:
		file_in.write(line);
	file_in.close()
	file_out.close()



def add_required_syntax(): # function is used to add the required syntax to make the given Embedded Program testable
       	global i
	i = 0 
	list_of_temp = sorted(glob.glob('./Temp/*.c'))
	for file_name in list_of_files:	
		file2 = open(list_of_temp[i],'w+')
		with open(list_of_files[i], 'r') as file1:
		    for line in file1:
			if re.search("#include \"delay_new.h\"", line):
				file2.write("\n#include \"" + path_to_mocked_function_header + "\"")
			elif re.search("#include <avr/interrupt.h>", line):
				file2.write("#include <"+ path_to_avr_io +"interrupt.h>\n")	
			elif re.search("#include <avr/io.h>", line):
				file2.write("#include <"+ path_to_avr_io +"io.h>\n")
			elif re.search("#include <util/delay.h>", line):
				file2.write("")	
			elif re.search("volatile unsigned int", line):
				file2.write(line)
				file2.write("\nint check_buzzer[4];\nint a;\nint check_led[7];\nint b;")	
			elif bool(re.search("PORTC =", line)):
				file2.write(line);
				file2.write("check_buzzer[a] = PORTC;\na++;\n")
			elif bool(re.search("PORTC=", line)):
				file2.write(line);
				file2.write("check_buzzer[a] = PORTC;\na++;\n")
			elif bool(re.search("PORTJ =", line)):
				file2.write(line);
				file2.write("check_led[b] = PORTJ;\nb++;\n")
			elif bool(re.search("PORTJ=", line)):
				file2.write(line);
				file2.write("check_led[b] = PORTJ;\nb++;\n")				
			else:
				file2.write(line)
		file2.close()
		i += 1

def rename_main(): # function is used to rename the main function of a submission so as to render it testable 
       	global i
	i = 0 
	list_of_temp = sorted(glob.glob('./Temp/*.c'))
	for file_name in list_of_files:	
		file2 = open(list_of_temp[i],'w+')
		with open(list_of_files[i], 'r') as file1:
		    for line in file1:
			if re.search("int main()", line):
				file2.write("int main_test()\n")
			else:
				file2.write(line)
		file2.close()
		i += 1       

def create_Makefile():
        global i
	i = 0 
	os.system("mkdir Test_Results")
	file2 = open("Makefile1", "w")
	with open("Makefile", "r+") as file1:
		for line in file1:	
			if re.search("Compile:", line):
				 file2.write(line)
				 for file_name in list_of_files:				
					file2.write("	gcc -Os -DTEST -std=c99 " + list_of_files[i] + " Experiment_1_test.c " + path_to_mocked_function_c+ " " + path_to_untiy + " -o ./Test" +str(i)+ ".elf" +"\n")
				 	i += 1  
			else:
				 file2.write(line)
	file2.close()
	file1.close()

def create_Makefile_run():
        global i
	i = 0 
	file2 = open("Makefile1", "w")
	with open("Makefile", "r+") as file1:
		for line in file1:	
			if re.search("Test:", line):
				 file2.write(line)
				 for file_name in list_of_files:				
					file2.write("	./Test" + str(i)+ ".elf" + " > ./Test_Results/Submission" +str(i+1)+ ".txt\n" )
				 	i += 1  
			else:
					file2.write(line)
	file2.close()
	file1.close()
		

def run_test(): # function is used to run the Makefile which in turn builds the submission as well as the tests
	os.system("make --ignore-errors")

def clean(): # function is used to run the Makefile which in turn builds the submission as well as the tests
	os.system("make clean")


def assign_grades(): # function is used to assign grades to the submissions based on the Unit Test 
	global i
	i = 0 
	k = 1
	global totalmarks
	for file_name in list_of_files:
		totalmarks = 0
		k = 1
		file2 = open('./Grades/Submission' + str(i+1) + '.csv' ,'a')
		with open('./Test_Results/Submission' + str(i+1) + '.txt', 'r') as file1:
			for line in file1:
				if bool(re.search('port_init',line)):
					if  bool(re.search('FAIL',line)):
						k+=1
						file2.write('%d. Port initalization, 0 Marks\n' % k)
						k+=1
						file2.write('%d. Initilization of Timer, 0 Marks\n' % k)
						k+=1
						file2.write('%d. Counter Values Displayed, 0 Marks\n' % k)
						k+=1
						file2.write('%d. Buzzer turned on, 0 Marks\n' % k)
					else:
						k+=1
						file2.write('%d. Port initalization, 2 Marks\n' % k)
						totalmarks += 2
						for line in file1:
							if re.search('timer1_init',line):
								if re.search('PASS',line):	
									k+=1
									file2.write('%d. Initilization of Timer, 4 Marks\n' % k)
									totalmarks += 4
								else:	
									k+=1
									file2.write('%d. Initilization of Timer, 0 Marks\n' % k)
							elif re.search('test_led',line):
								if re.search('PASS',line):	
									k+=1
									file2.write('%d. LEDs Displayed, 4 Marks\n' % k)
									totalmarks += 4
								else:	
									k+=1
									file2.write('%d. Counter Values Displayed, 0 Marks\n' % k)
							elif re.search('test_buzzer',line):
								if re.search('PASS',line):	
									k+=1
									file2.write('%d. Buzzer turned on, 2 Marks\n' % k)
									totalmarks += 2
								else:	
									k+=1
									file2.write('%d. Buzzer turned on, 0 Marks\n' % k)
						
			file2.write('Total Marks, %.1f Marks'%totalmarks )
		i += 1
		file2.close()

def final_grades():
	 global i  
	 i= 0
         temp = open( 'Grades.csv' ,'w')
	 temp.write("Team ID, CPU Frequency, Port Initialization, Timer initalization, LEDs Displayed, Buzzer turned on, Total Marks \n" )
	 temp.close
	 import pandas as pd
	 list_of_grades = sorted(glob.glob('./Grades/*.csv'))
	 for file_name in list_of_grades:
	 	pd.read_csv('./Grades/Submission' +str(i+1)+ '.csv').T.to_csv('output.csv',header=False)
		temp = open( 'Grades.csv' ,'a')
		with open('output.csv', 'r') as file1:
			for line in file1:
				if re.search("TeamID",line):
					temp.write(line.replace("/",""))
                i+=1

def open_grades():
	os.system("libreoffice Grades.csv | gedit ./Test_Results/Results.txt")

def add_team_id_to_results():
	k = 0
	list_of_txt = sorted(glob.glob('./Test_Results/*.txt'))
	for file_name in list_of_txt:
		with open( list_of_files[k] ,'r') as file1:
			for line in file1:
				if re.search("TeamID",line):
					with file(list_of_txt[k], 'r') as original: data = original.read()
					with file(list_of_txt[k], 'w') as modified: modified.write(line.replace("/","") + data)
			k +=1
def concatenate_results():
	k = 0
	list_of_txt = sorted(glob.glob('./Test_Results/*.txt'))
	file1 = open("./Test_Results/Results.txt","w")
	file1.close()
	for file_name in list_of_txt:
		with file(list_of_txt[k], 'r') as original: data = original.read()
		with file("./Test_Results/Results.txt", 'a') as modified: modified.write(data + "\n")
		k +=1



Find_Team_ID()
check_CPU_frequency()
remove_infinite_loops()
copy()
add_required_syntax()
copy()
rename_main()
copy()
create_Makefile_run()
copy_makefile()
create_Makefile()
copy_makefile()
run_test()
assign_grades()
final_grades()
add_team_id_to_results()
concatenate_results()
open_grades()
rename_submissions()
clean()






