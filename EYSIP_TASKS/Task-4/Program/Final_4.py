#This is the script that is to be run for automatic evaluation and building of submissions.
import re
import os
totalmarks = 0

def check_CPU_frequency(): # function is used to check wether the studenet has used the correct CPU Frequency
	global totalmarks
	with open('Buzzer_Beep.c', 'r') as file1:
	    for line in file1:
		if '#define F_CPU' in line:
			if '14745600UL' in line:
				temp = open('Grades.csv','w')
				temp.write('1.Correct CPU Frequency - 1 Mark\n') 
				totalmarks += 1
				temp.write('\n')
				temp.close
			else:
				temp = open('Grades.csv','w')
				temp.write('1. Incorrect CPU Frequency - 0 Mark\n')
				temp.write('\n')
				temp.close

def remove_infinite_loops(): # function is used to remove any infinite loops within a submission so as to allow that function to be tested
	delete = ["while(1)"]
	file_in = open("Buzzer_Beep.c")
	file_out = open("Buzzer_Beep1.c","w")
	for line in file_in:
	    for word in delete:
		line = line.replace(word, "for (int qwer = 1; qwer > 0; qwer-- )")
	    file_out.write(line)
	file_in.close()
	file_out.close()

def add_mock_functions(): # function is used to add the correct mock header file to allow certain functions to be mocked 
	file2 = open('Buzzer_Beep2.c','w+')
	with open('Buzzer_Beep1.c', 'r') as file1:
	    for line in file1:
		if re.search("delay.h", line):
			file2.write("#include \"../../../CMock/lib/mocks/Mock_ms_delay.h\"\n")
		else:
			file2.write(line)
	file2.close()

def rename_main(): # function is used to rename the main function of a submission so as to render it testable 
	file2 = open('Buzzer_Beep3.c','w+')
	with open('Buzzer_Beep2.c', 'r') as file1:
	    for line in file1:
		if re.search("int main()", line):
			file2.write("int main_test()\n")
		else:
			file2.write(line)
	file2.close()

def run_test(): # function is used to run the Makefile which in turn builds the submission as well as the tests
	os.chdir("/home/vinay/Desktop/EYSIP_TASKS/Task-4")
	os.system("make")

def copy_test_results_to_grades(): # function is used to transfer the results of the Unit Test to the grade sheet 
	file2 = open('Program/Grades.csv','a')
	with open('Results/Submission_1.csv', 'r') as file1:
		for line in file1:
			file2.write(line)
		file2.write('\n')
	file2.close()

def assign_grades(): # function is used to assign grades to the submissions based on the Unit Test 
	k = 1
	global totalmarks
	file2 = open('Program/Grades.csv','a')
	with open('Results/Submission_1.csv', 'r') as file1:
		for line in file1:
			if re.search('test_main',line):
				k+=1
				if re.search('PASS',line):
					if (corner_casea() & corner_caseb()):
						file2.write('%d. Main Function working as expected but suspected Hardcoding - 7 Marks\n' % k)
						totalmarks += 7
					else:	
						file2.write('%d. Main Function working as expected - 10 Marks\n' % k)
						totalmarks += 10
				else:
					file2.write('%d. Main Function is not working as expected - 0 Marks\n' % k)
			if re.search('test_buzzer',line):
				k+=1
				if re.search('PASS',line):
					file2.write('%d. Function working as expected - 3 Marks\n' % k)
					totalmarks += 3
				else:
					file2.write('%d. Function is not working as expected - 0 Marks\n' % k)
		file2.write('\n')
		file2.write('Total Marks: %d' %totalmarks )

def corner_casea(): # function is used to theck if the main function has passed or not
	file2 = open('Program/Grades.csv','a')
	with open('Results/Submission_1.csv', 'r') as file1:
		for line in file1:
			if re.search('test_main',line):
				if re.search('PASS',line):
					return 1
				else:
					return 0
	file2.closb()

def corner_caseb(): # function is used to check if anyone of the required functions has failed or not
	file2 = open('Program/Grades.csv','a')
	with open('Results/Submission_1.csv', 'r') as file1:
		for line in file1:
			if re.search('test_buzzer',line):
				if re.search('PASS',line):
					return 0
				else:
					return 1

def corner_casec(): # function is used to check wether the main function works even if a function test fails. This is to detected hardcoding.
	file2 = open('Program/Grades.csv','a')
	k = corner_casea()
	j = corner_caseb()
	q = 0
	if (k & j) == 1:
		file2 = open('Program/Grades.csv','a')
		with open('Buzzer_Beep3.c', 'r') as file1:
			 copy = False
			 file2.write('Suspected Hardcoding.\nPrinting Main Function:\n\n')
			 for line in file1:
				if line.strip() == "int main_test()":
				    copy = True
				    file2.write(line)
				elif copy & (line.strip() == "{"):
					file2.write(line)				    
					q += 1 
				elif copy & (line.strip() == "}"):
				    file2.write(line)
				    if q == 0:			    
					copy = False
				elif copy:
					file2.write(line)
				
check_CPU_frequency()
remove_infinite_loops()
add_mock_functions()
rename_main()
run_test()
copy_test_results_to_grades()
corner_casec()
assign_grades()













