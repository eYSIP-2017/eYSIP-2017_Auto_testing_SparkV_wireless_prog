#This is the script that is to be run for automatic evaluation and building of submissions.
import re
import os
import glob
import shutil

totalmarks = 0.0	# Variable to store the total marks of a given submission

list_of_files = sorted(glob.glob('./Submissions/*.c'))	# This array stores the sorted name of all the TBT submissions 

path_to_mocked_delay_function_header = "../../../../../CMock/lib/mocks/MockTBT3.h"  # Path to the Mocked Function header file

path_to_mocked_delay_function_c = "../../../../CMock/lib/mocks/MockTBT3.c"  # Path to the Mocked Function C file

path_to_untiy = "../../../../Unity-master/src/unity.c"	# Path to Unity 

path_to_avr_io = "/usr/lib/avr/include/avr/"	# Path to the AVR IO Header file

def open_submissions():   
    """ Opens all the submissions inside the Geany IDE."""
	k = 0
	for file_name in list_of_files:
		os.system("geany " + list_of_files[q])    # The string "geany" is an alias created to simplify the process of opening submissions.
		k += 1

def find_Team_ID():  
    """ Finds the Team ID and creates individual a .csv for each submission file where the interpreted results of the Unit Test will be stored."""
	global totalmarks
	k = 0  
	for file_name in list_of_files:
		temp = open( './Grades/Submission' +str(k+1)+ '.csv' ,'w')
		with open(file_name, 'r') as file1:
		    for line in file1:
			if re.search("ID.",line):
				temp.write("Team ID," + line)
		    k += 1


def check_CPU_frequency(): 
    """ Checks all the submissions to check if the defined CPU Frequency is correct and indicates the result in the respective .csv files.""" 
	global totalmarks  
	i = 0 
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

def remove_infinite_loops(): 
    """Removes any infinite loops within a given submission to render it testable""" 
	i = 0 
	os.system("mkdir Temp")
	list_of_temp = sorted(glob.glob('./Temp/*.c'))
	for file_name in list_of_files:
		list_of_strings_to_delete = ["while(1)", "while (1)", "while(1);", "while(true)"]
		file_in = open(list_of_files[i])
		file_out = open( './Temp/Temp' +str(i+1)+ '.c' ,'w')
		for line in file_in:
		    for word in list_of_strings_to_delete:
			line = line.replace(word, "for (int qwer = 1; qwer > 0; qwer-- );")
		    file_out.write(line)
		i += 1
		file_in.close()
		file_out.close()


def copy():
    """ Copies the changes made to render a submission testable, which are stored in a temporary file back to the original submission"""
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
    """ Copies the populated commands from a temporary file to the Makefile""" 
	file_in = open("Makefile","w")
	file_out = open("Makefile1","r") # Temporary file which contains the populated commands
	for line in file_out:
		file_in.write(line);
	file_in.close()
	file_out.close()



def add_required_syntax(): 
	""" Adds the required syntax to make the given Embedded Program testable. The syntax to be added is determined while development of the Unit Test"""
	i = 0 
	list_of_temp = sorted(glob.glob('./Temp/*.c'))
	for file_name in list_of_files:	
		file2 = open(list_of_temp[i],'w+')
		with open(list_of_files[i], 'r') as file1:
		    for line in file1:
			if re.search("#include \"lcd.h\"", line):
				file2.write("\n#include \"" + path_to_mocked_delay_function_header + "\"")  # Replaces LCD Header with the mocked header file

			elif re.search("#include \"lcd.c\"", line):
				file2.write("")  # 

			elif re.search("#include <avr/interrupt.h>", line):  
				file2.write("#include <"+ path_to_avr_io +"interrupt.h>\n") # Removes interrupt.h since it is not required for the Unit Test
	
			elif re.search("#include <avr/io.h>", line):
				file2.write("#include <"+ path_to_avr_io +"io.h>\n")  # The path has to be specified completely since compilation is done using GCC
	
			elif re.search("#include <util/delay.h>", line):  
				file2.write("")  # Removes delay.h since it is not required for the Unit Test

			else:
				file2.write(line)
		file2.close()
		i += 1

def rename_main(): # function is used to rename the main function of a submission so as to render it testable        	
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
    """Populates a temporary file with the required commands to compile each submission"""
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
    """Populates a temporary file with the required commands to run and store the result of each submission"""
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
		
def run_test(): 
	""" Compiles and runs the Unit Tests via the terminal"""
	os.system("make --ignore-errors")

def clean(): 
	""" Removes all temporary and irrelevant files from the test folder"""
	os.system("make clean")

def assign_grades():
	""" Assigns the required grades to each submission by analyzing the temporary file containing the results of the Unit Test """
	i = 0 
	k = 1
	global totalmarks
	for file_name in list_of_files:
		totalmarks = 0
		k = 1
		file2 = open('./Grades/Submission' + str(i+1) + '.csv' ,'a')
		with open('./Test_Results/Submission' + str(i+1) + '.txt', 'r') as file1:
			for line in file1:
				if bool(re.search('lcd_port_config',line)):
					if  bool(re.search('FAIL',line)):
						k+=1
						file2.write('%d. Port initalization, 0 Marks\n' % k)
						k+=1
						file2.write('%d. Displayed at required Position, 0 Marks\n' % k)
						k+=1
						file2.write('%d. Displayed Message, 0 Marks\n' % k)
					else:
						k+=1
						file2.write('%d. Port initalization, 4 Marks\n' % k)
						totalmarks += 4
						for line in file1:
							if re.search('test_position',line):
								if re.search('PASS',line):	
									k+=1
									file2.write('%d. Displayed at required Position, 2 Marks\n' % k)
									totalmarks += 2
								else:	
									k+=1
									file2.write('%d. Displayed at required Position, 0 Marks\n' % k)
							if re.search('test_main',line):
								if re.search('PASS',line):	
									k+=1
									file2.write('%d. Displayed Message, 2 Marks\n' % k)
									totalmarks += 4
								else:	
									k+=1
									file2.write('%d. Displayed Message, 0 Marks\n' % k)
			file2.write('Total Marks, %.1f Marks'%totalmarks )
		i += 1
		file2.close()

def final_grades():
	"""Creates a final Excell Sheet with the required headings"""
	 i= 0
         temp = open( 'Grades.csv' ,'w')
	 temp.write("Team ID, CPU Frequency, Port Initialization, Timer initialization, Buzzer turned on, Counter Values Displayed, Total Marks \n" )
	 temp.close
	 import pandas as pd
	 list_of_grades = sorted(glob.glob('./Grades/*.csv'))
	 for file_name in list_of_grades:
	 	pd.read_csv('./Grades/Submission' +str(i+1)+ '.csv').T.to_csv('output.csv',header=False) # The grades are originally stored vertically, so the grades are transposed and then stored in the final sheet.
		temp = open( 'Grades.csv' ,'a')
		with open('output.csv', 'r') as file1:
			for line in file1:
				if re.search("TeamID",line):
					temp.write(line.replace("/",""))
                i+=1

def open_grades():
	"""Opens the finals Grades Sheet and Concatenated Results of the Unit Test"""
	os.system("libreoffice Grades.csv | gedit ./Test_Results/Results.txt")

def add_team_id_to_results():
	""" Adds the Team ID to the respective results of each Unit Test"""
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
	""" Concatenates the results of all the Unit Tests"""
	k = 0
	list_of_txt = sorted(glob.glob('./Test_Results/*.txt'))
	file1 = open("./Test_Results/Results.txt","w")
	file1.close()
	for file_name in list_of_txt:
		with file(list_of_txt[k], 'r') as original: data = original.read()
		with file("./Test_Results/Results.txt", 'a') as modified: modified.write(data + "\n")
		k +=1

#open_submissions()
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
clean()













