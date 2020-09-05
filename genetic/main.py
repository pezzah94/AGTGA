from genetic import Genetic
from configuration import Configuration
from executor import Executor


def main():

    C = Configuration('conf.json')

    E = Executor(srcPath=C.srcPath)

    G = Genetic(populationSize=C.populationSize,  # Population pop_size
              chromosomeSize=C.chromosomeSize,  # size of chromosome (can be bytes, size of a number, size of a string...)
              parentsNumber=C.parentsNumber,  # How many chromosomes are entering crossover
              mutationRate=C.mutationRate,  # selfexplanatory
              generationsCount=C.generationsCount,  # Number of generations (iterations)
              geneTypeList=C.geneTypeList, #list of
              executor=E)

    G.start_evolution();

    return 0;


main()