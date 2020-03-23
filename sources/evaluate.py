#!/usr/bin/python
import sys
import os
from subprocess import Popen, PIPE
"""
To get file coverage we first call compiler with follwoing commands
	1) g++ -o test	-fprofile-arcs -ftest-coverage test.cpp 
	2) we run the program with tests
	3) we call : gcov test.cpp
	4) we read our what our gcov returns
"""


def main():
	# print("Main function")
	# print('Number of arguments:', len(sys.argv), 'arguments.')
	# print('Argument List:', str(sys.argv))
	
	"""
	Parsing program
	"""
	program_name = sys.argv[1]
	if program_name[-2:] == '.c': # c program
		#print("Working with C")
		extension = '.c'
		program_name = program_name[:-2]
	elif program_name[-4:] in ('.cpp','.c++'):
		#print("Working with c++")
		extension = '.cpp'
		program_name = program_name[:-4] # cutting off extension
	else:
		print("Extension is not c or c++")
		exit()

	# we compile program for check coverage
	os.system('g++ -o ' + program_name + ' -fprofile-arcs -ftest-coverage ' + program_name + extension)
	_execute_test_program(program_name, values = [1])
	# we need to determine what variables we are working with, what our test program expects to be in STDIN

	return 42 # coverage

def _execute_test_program(program_name, values = [] ):#, varibales = []):
	# p = Popen([program_name], shell=True, stdout=PIPE, stdin=PIPE)
	# we need to determine how many variables we are working with, currently its hardcoded
	
	for i in range(0, len(values)):
		p_test = Popen([program_name], shell=True, stdin=PIPE, stdout=PIPE)
		# we need to determine how many variables we are working with, currently its hardcoded
		value = bytes(str(values[i]) + '\n', 'UTF-8') # needed in python 3 
		p_test.stdin.write(value)
		p_test.stdin.flush()
		#p_test.kill()
		# p_gcov = Popen(['gcov', program_name])

	# for ii in range(10):
	# 		value = str(ii) + '\n'
	# 		value = bytes(value, 'UTF-8')	# Needed in Python 3.
	# 		p.stdin.write(value)
	# 		p.stdin.flush()
	# 		result = p.stdout.readline().strip()
	# 		print(result)



main()