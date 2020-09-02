#!/usr/bin/python
import os
import subprocess as sp
import sys
import gzip
import json
from testsaver import TestSaver
DEBUG = 0

"""
To get file coverage we first call compiler with follwoing commands
	1) Compile program for coverage - g++ -o test	-fprofile-arcs -ftest-coverage test.cpp  
	2) Run program with given tests
	3) Calculate coverage gcov test.cpp
	4) Read retunred values
"""
class Execution:

	executed_lines = set();
	total_number_of_lines = -1;
	def compile_program(self):
		"""
		Parsing program
		"""
		testing_dir = "test/"
		dir_path = os.path.dirname(os.path.realpath(__file__)).rpartition('/')[0]

		#program_data = sys.stdin.buffer.read()
		program_name = 'test.cpp' # defined elswhere in program
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
		# data = bytes(program_data[0],'UTF-8')



		#print(4, file=sys.stdout)
		os.system('g++ -o ' + '../' + testing_dir + program_name + ' -fprofile-arcs -ftest-coverage ' + dir_path + '/' + testing_dir  + program_name + extension )
		# need to add if it compiles succsefully
		#os.system('cp ../test/test test')
		#self._execute_test_program(program_name, program_data )

	def execute_test_program(self, program_name, data):
		p_test = sp.Popen(['./' + program_name],stdin=sp.PIPE, stdout=sp.PIPE, stderr=sp.PIPE)

		data = bytes(data, 'UTF-8')

		outs ,err = p_test.communicate(input=data)
		p_test.kill()
		if DEBUG:
			print("Debug: return stdout:", outs.decode("utf-8"), file=sys.stderr)
			print("Debug: return err:", err.decode("utf-8"), file=sys.stderr)
			print("Debug: return code:", p_test.returncode, file=sys.stderr)

		#print(outs);

		# We slice string by new line, since output is always same for gcov, we can hardcode numbers
		# We perform 2 slices ( 3 list elements) and we are intereseted in 2nd element, and then we split by : so we just get number of %
		# Possible hack
		#extracted_data = outs.decode('UTF-8').split('\n',2)[1].split(':')[1].split(' ',1)[0][:-1]
		#print(extracted_data, file=sys.stdout)
		return 0

	def get_score(self, jsonStruct, whatToConsider, testinput):

		#print(jsonStruct)
		lines_count = 0

		score = 0
		for file in jsonStruct['files']:
			lines_count += len(file['lines']); #mozda ovde neka provera da li postoji lines i sl.

			if self.total_number_of_lines <= 0:
				self.total_number_of_lines = len(file['lines']);

			for i in range(0, len(file['lines'])):

				if file['lines'][i]['count'] >= 1:
					score += 1
					self.executed_lines.add(i)


		return score / lines_count


	"""
	
	"""

	def run_gcov(self, program_name, testinput):

		#TODO:treba prethodno i obrisati gz


		#ovde cemo najverovatnije da napravimo spoljasnji json koji posle ucitavamo i parsiramo i pravimo sta treba
		p_gcov = sp.Popen(['gcov', '--json', 'test' + '.gcda'], stdout=sp.PIPE)

		outs ,_ = p_gcov.communicate()
		if DEBUG:
			#outs, _ = p_gcov.communicate()
			print("Debug: return stdout:", outs.decode('UTF-8'),file=sys.stderr)
		p_gcov.kill()

		if os.path.exists('test.gcda'):
			os.remove('test.gcda')
		else:
			print("The file test.gcda does not exist")

		#TODO: ovde ako uspesno napravi ovaj fajl onda raditi sta treba
		with gzip.open('test.gcda.gcov.json.gz', 'rb') as f:
			file_content = f.read()

		# if os.path.exists('test.gcno'):
		# 	os.remove('test.gcno')
		# else:
		# 	print("The file test.gcno does not exist")



		if os.path.exists('test.gcda.gcov.json.gz'):
			os.remove('test.gcda.gcov.json.gz')
		else:
			print("The file test.gcda.gcov.json.gz does not exist")

		gcovData = json.loads(file_content);

		#TODO: ovde treba analizirati gcovData i vratiti jedan broj


		return self.get_score(gcovData, 'lines', testinput);

	def execute_list_tests(self, program_name, test_cases):

		for test in test_cases:
			self.execute_test_program(program_name,test)

		return 0;

	def pretty_progress(self, executed_lines, total_number_of_lines):
		length = 80;
		percentage = executed_lines/total_number_of_lines;
		print('Total coverage:','[' + '#'*int(length*percentage) + '.'*int(length*(1-percentage)) +']', percentage*100, '%')
