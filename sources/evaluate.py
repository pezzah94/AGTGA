#!/usr/bin/python
import sys
import os
import subprocess as sp

DEBUG = 0

"""
To get file coverage we first call compiler with follwoing commands
	1) Compile program for coverage - g++ -o test	-fprofile-arcs -ftest-coverage test.cpp  
	2) Run program with given tests
	3) Calculate coverage gcov test.cpp
	4) Read retunred values
"""


def main():
	"""
	Parsing program
	"""
	testing_dir = "test/"
	dir_path = os.path.dirname(os.path.realpath(__file__)).rpartition('/')[0]
	
	program_data = sys.stdin.read().split(' ')
	program_name = program_data[0]
	if program_name[-2:] == '.c': # c program
		#print("Working with C")
		extension = '.c'
		program_name = program_name[:-2]
	elif program_name[-4:] in ('.cpp','.c++'):
		#print("Working with c++")
		extension = '.cpp'
		program_name = program_name[:-4] # cutting off extension
	else:
		print(program_name)
		print("Extension is not c or c++")
		return -1
	data = bytes(program_data[1],'UTF-8')


	os.system('g++ -o ' + testing_dir + program_name + ' -fprofile-arcs -ftest-coverage ' + dir_path + '/' + testing_dir  + program_name + extension )
	return _execute_test_program(program_name, data )

def _execute_test_program(program_name, data ):
	p_test = sp.Popen(['test/' + program_name], stdin=sp.PIPE, stdout=sp.PIPE, stderr = sp.PIPE)

	outs ,err = p_test.communicate(input=data)
	p_test.kill()
	if DEBUG:
		print("Debug: return stdout:", outs.decode("utf-8"))
		print("Debug: return err:", err.decode("utf-8"))
		print("Debug: return code:", p_test.returncode)


	p_gcov = sp.Popen(['gcov', program_name], stdout=sp.PIPE)
	outs ,_ = p_gcov.communicate()
	if DEBUG:
		print("Debug: return stdout:", outs.decode('UTF-8')) 
	p_gcov.kill()

	# We slice string by new line, since output is always same for gcov, we can hardcode numbers
	# We perform 2 slices ( 3 list elements) and we are intereseted in 2nd element, and then we split by : so we just get number of %
	# Possible hack
	extracted_data = outs.decode('UTF-8').split('\n',2)[1].split(':')[1].split(' ',1)[0][:-1]
	print(extracted_data)
	return extracted_data

main()