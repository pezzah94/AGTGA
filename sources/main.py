from genetic import Genetic
from configuration import Configuration
from evaluate import Execution
from testsaver import TestSaver



def main():

    program_name = '../test/test'

    E = Execution() #zasto imam 2 execution objekta

    E.compile_program();

    C = Configuration('conf.json')
    #G = Genetic()

    G = Genetic(populationSize=C.populationSize,  # Population pop_size
              chromosomeSize=C.chromosomeSize,  # size of chromosome (can be bytes, size of a number, size of a string...)
              parentsNumber=C.parentsNumber,  # How many chromosomes are entering crossover
              mutationRate=C.mutationRate,  # selfexplanatory
              generationsCount=C.generationsCount # Number of generations (iterations)
              #,geneTypeList=C.geneTypeList
               )

    G.start_evolution();

    return 0;


main()