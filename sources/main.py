from genetic import Genetic
from configuration import Configuration
from evaluate import Execution

#znaci ovde kada se importuje importuje se klasa


def main():
    G = Genetic()

    program_name = '../test/test'

    E = Execution()

    #objektno testiranje svih funkcija pojedinacno


    E.compile_program() ## za sad radi

    #E.execute_test_program(program_name, '-123'); ##za sad radi

    #resultGcov = E.run_gcov(program_name);

    C = Configuration('config.json')


    chromo, score = G.generations(pop_size=C.populationSize,  # Population pop_size
                                  c_size=C.chromosomeSize,  # size of chromosome (can be bytes, size of a number, size of a string...)
                                  n_parents=C.parentsNumber,  # How many chromosomes are entering crossover
                                  mutation_rate=C.mutationRate,  # selfexplanatory
                                  n_gen=C.generationsCount # Number of generations (iterations)
                                  )


   # C = Configuration('conf.json')

    #print(C.populationSize)

    return 0;


main()