from genetic import Genetic
from configuration import Configuration
from evaluate import Execution
from testsaver import TestSaver



def main():
    G = Genetic()

    program_name = '../test/test'

    E = Execution()

    #objektno testiranje svih funkcija pojedinacno


    E.compile_program() ## za sad radi

    #E.execute_test_program(program_name, '-123'); ##za sad radi
    #tests = [('233',0.3898305084745763),('232', 0.15254237288135594)]

    #ts = TestSaver('tests.out')
    #ts.save_list(tests);


    # return 0;
    # #E.execute_list_tests(program_name, tests);

    #resultGcov = E.run_gcov(program_name);

    C = Configuration('conf.json')
    #print(C.testPath)

    chromo, score = G.generations(pop_size=C.populationSize,  # Population pop_size
                                  c_size=C.chromosomeSize,  # size of chromosome (can be bytes, size of a number, size of a string...)
                                  n_parents=C.parentsNumber,  # How many chromosomes are entering crossover
                                  mutation_rate=C.mutationRate,  # selfexplanatory
                                  n_gen=C.generationsCount # Number of generations (iterations)
                                  )


    return 0;


main()