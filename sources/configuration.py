
import sys
import json

"""
Class represent configuration of genetic algorithm
it gets parameters from json file  

"""



class Configuration:

    ##ovo moze da bude private members samo se dodaju dve crte dole i to ne moze da se dohvati sa C.populationSize ...

    testPath = "";
    populationSize = 15;
    chromosomeSize = 3;
    parentsNumber = 5;
    mutationRate = 0.1;
    generationsCount = 100;

    # default constructor
    def __init__(self, jsonPath):

        #proveriti da li je validan json file

        if jsonPath[-4:] == '.json':
            jsonData = json.loads(jsonPath);

            self.testPath = jsonData.testPath;
            self.populationSize = jsonData.populationSize;
            self.chromosomeSize = jsonData.chromosomeSize;
            self.parentsNumber = jsonData.parentsNumber;
            self.mutationRate = jsonData.mutationRate;
            self.generationsCount = jsonData.generationsCount;

    def printAll(self):
        print(self)


