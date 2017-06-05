#This is the script that is to be run for automatic evaluation and building of submissions.
import re
import os
totalmarks = 0

def check_CPU_frequency(): # function is used to check wether the student has used the correct CPU Frequency
	global totalmarks
	with open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Timer.c', 'r') as file1:
	    for line in file1:
		if '#define F_CPU' in line:
			if '14745600UL' in line:
				temp = open('Grades.txt','w')
				temp.write('1.Correct CPU Frequency - 1 Mark\n') 
				totalmarks += 1
				temp.write('\n')
				temp.close
			else:
				temp = open('Grades.txt','w')
				temp.write('1. Incorrect CPU Frequency - 0 Mark\n')
				temp.write('\n')
				temp.close

def remove_infinite_loops(): # function is used to remove any infinite loops within a submission so as to allow that function to be tested
	delete = ["while(1)"]
	file_in = open("/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Timer.c")
	file_out = open("Timer1.c","w")
	for line in file_in:
	    for word in delete:
		line = line.replace(word, "for (int qwer = 1; qwer > 0; qwer-- );")
	    file_out.write(line)
	file_in.close()
	file_out.close()

def add_required_syntax(): # function is used to add the required syntax to make the given Embedded Program testable
	file2 = open('Timer2.c','w+')
	with open('Timer1.c', 'r') as file1:
	    for line in file1:
		if re.search("unsigned char toggel = 0;", line):
			file2.write(line);
			file2.write("int check,a,b = 0;\nint verify[2];")
		elif re.search("PORTC = port_restore;", line):
			file2.write(line);
			file2.write(" verify[a] = PORTC;\n a++; ")
		elif re.search("toggel = ~toggel;", line):
			file2.write(line);
			file2.write(" check++;")
		elif re.search("init_devices(); ", line):
			print 'l'
			file2.write(line);
			file2.write("__vector_45()\n __vector_45();")
		else:
			file2.write(line)
	file2.close()

def rename_main(): # function is used to rename the main function of a submission so as to render it testable 
	file2 = open('Timer3.c','w+')
	with open('Timer2.c', 'r') as file1:
	    for line in file1:
		if re.search("int main()", line):
			file2.write("int main_test()\n")
		else:
			file2.write(line)
	file2.close()

def run_test(): # function is used to run the Makefile which in turn builds the submission as well as the tests
	os.chdir("/home/vinay/Desktop/EYSIP_TASKS/Task-6")
	os.system("make")

def copy_test_results_to_grades(): # function is used to transfer the results of the Unit Test to the grade sheet 
	file2 = open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Grades.txt','a')
	with open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Results/Submission_1.csv', 'r') as file1:
		for line in file1:
			file2.write(line)
		file2.write('\n')
	file2.close()

def assign_grades(): # function is used to assign grades to the submissions based on the Unit Test 
	k = 1
	global totalmarks
	file2 = open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Grades.txt','a')
	with open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Results/Submission_1.csv', 'r') as file1:
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
			if re.search('test_',line):
				k+=1
				if re.search('PASS',line):
					file2.write('%d. Function working as expected - 3 Marks\n' % k)
					totalmarks += 3
				else:
					file2.write('%d. Function is not working as expected - 0 Marks\n' % k)
		file2.write('\n')
		file2.write('Total Marks: %d' %totalmarks )

def corner_casea(): # function is used to theck if the main function has passed or not
	file2 = open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Grades.txt','a')
	with open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Results/Submission_1.csv', 'r') as file1:
		for line in file1:
			if re.search('test_main',line):
				if re.search('PASS',line):
					return 1
				else:
					return 0
	file2.close()

def corner_caseb(): # function is used to check if anyone of the required functions has failed or not
	file2 = open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Grades.txt','a')
	with open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Results/Submission_1.csv', 'r') as file1:
		for line in file1:
			if re.search('_test',line):
				if re.search('PASS',line):
					pass
				else:
					return 1
	return 0	

def corner_casec(): # function is used to check wether the main function works even if a function test fails. This is to detected hardcoding.
	file2 = open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Grades.txt','a')
	f = corner_casea()
	e = corner_caseb()
	print f
	print e
	q = 0
	if (f & e) == 1:
		file2 = open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Grades.txt','a')
		with open('/home/vinay/Desktop/EYSIP_TASKS/Task-6/Program/Timer3.c', 'r') as file1:
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
add_required_syntax()
rename_main()
run_test()
copy_test_results_to_grades()
corner_casec()
assign_grades()













