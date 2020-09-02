
import random
from configuration import Configuration

from evaluate import Execution as Exec

import subprocess as sp


# Valid genes 
#GENES = '''abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890, .-;:_!"#%&/()=?@${[]}'''
GENES  = '''1234567890'''
class Genetic:


	def initilization_of_population(self, pop_size, c_size):
		population = []
		for i in range(pop_size):
			# ----------------- With bytes -----------------
			# chromosome = bytearray('\x00' + ''.join(chr(random.randint(0,255)) for _ in range(c_size)) + '\x00', 'utf-8').decode('utf8')
			# chromosome = np.random.bytes(c_size)
			################################################
			# ----------------- With string -----------------
			global GENES
			chromosome = ''.join(random.choices(GENES, k = c_size))
			#################################################
			print('[' + chromosome + ']')

			population.append(chromosome)

			# print(chromosome.decode('utf-8'))
			# print(chromosome)
		return population

	def fitness_score(self, population):
		scores = []
		for chromosome in population:
			# Here we get accuracy score, tricky messy part

			# ovde napraviti posebnu klasu za izvrsavanje i onda
			#evaluate = sp.Popen(['python', 'evaluate.py'], stdin=sp.PIPE, stdout=sp.PIPE, stderr = sp.PIPE)
			#outs ,err = evaluate.communicate(input=bytearray(chromosome,'utf-8'))

			#Executor = Exec.Execution();
			#print(type(chromosome))

			E = Exec()

			E.execute_test_program('../test/test', data=chromosome);

			score = E.run_gcov('../test/test');

			print('Score for input', chromosome, score)

			# try:
			# 	score = float(outs.decode('UTF-8'))
			# except ValueError:
			# 	score = 0.0
			#evaluate.kill()


			scores.append(score)
		population = [x for _,x in sorted(zip(scores,population))]
		scores.sort()
		# print(population, scores)
		return scores, population[::-1]  #reverse list

	def selection(self, pop_after_fit, n_parents):
		population_nextgen = []
		for i in range(n_parents):
			population_nextgen.append(pop_after_fit[i])
		return population_nextgen

	def crossover(self, pop_after_sel):
		population_nextgen=pop_after_sel
		for i in range(len(pop_after_sel)):
			child = pop_after_sel[i][:len(pop_after_sel[i])//2]

			child += pop_after_sel[(i+1)%len(pop_after_sel)][len(pop_after_sel[i])//2:]
			# child.append(pop_after_sel[(i+1)%len(pop_after_sel)])


			# child[3:5] = pop_after_sel[(i+1)%len(pop_after_sel)][3:7]
			population_nextgen.append(child)
		return population_nextgen



	def mutation(self, pop_after_cross, mutation_rate):
		population_nextgen = []
		for i in range(0,len(pop_after_cross)):
			chromosome = pop_after_cross[i]
			# for j in range(len(chromosome)):
					# if random.random() < mutation_rate:
					# 	global GENES

					# 	# --- With bytes ---
					# 	# chromosome[j] =  random.randint(0,255)
					# 	# ------------------

					# 	chromosome += random.choice(GENES)
					# 	# chromosome.replace(chromosome[j],random.choice(GENES))

					# 	# print(chromosome)
			if random.random() < mutation_rate:
				global GENES
				#if random.random() < 1/2:
				clist = list(chromosome)
				clist[random.randrange(len(clist))] = random.choice(GENES)
				chromosome = "".join(clist)
				# chromosome.replace(chromosome[j],random.choice(GENES))
				#else:
				#	chromosome.replace(chromosome[random.randint(0,len(chromosome)-1)],random.choice(GENES))

			population_nextgen.append(chromosome)
		#print(population_nextgen)
		return population_nextgen

	def generations(self, pop_size, c_size, n_parents, mutation_rate, n_gen):
		best_chromo = []
		best_score = []
		population_nextgen = self.initilization_of_population(pop_size, c_size)
		for i in range(n_gen):
			print('Generation no. :',i)
			scores, pop_after_fit = self.fitness_score(population_nextgen)
			pop_after_sel = self.selection(pop_after_fit,n_parents)
			pop_after_cross = self.crossover(pop_after_sel)
			population_nextgen = self.mutation(pop_after_cross,mutation_rate)
			best_chromo.append(str(pop_after_fit[-1]))
			best_score.append(scores[0])
			# print(pop_after_fit)
			print("best chromosome so far:", str(best_chromo[-1]), best_score[-1])
		return best_chromo, best_score


# G = Genetic()
#
# chromo,score=G.generations(pop_size = 15, # Population pop_size
# 						 c_size= 3, # size of chromosome (can be bytes, size of a number, size of a string...)
# 						 n_parents=5, # How many chromosomes are entering crossover
# 						 mutation_rate= 0.1, # selfexplanatory
# 						 n_gen=100 # Number of generations (iterations)
# 						 )



# for i in range(len(chromo)):
# 	print(chromo[i],score[i])
