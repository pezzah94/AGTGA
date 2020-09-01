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

    E.execute_test_program(program_name, '-123'); ##za sad radi

    resultGcov = E.run_gcov(program_name);

    print(resultGcov)
    # chromo, score = G.generations(pop_size=15,  # Population pop_size
    #                               c_size=3,  # size of chromosome (can be bytes, size of a number, size of a string...)
    #                               n_parents=5,  # How many chromosomes are entering crossover
    #                               mutation_rate=0.1,  # selfexplanatory
    #                               n_gen=100  # Number of generations (iterations)
    #                               )



    return 0;


main()