
import sys
import json

"""
Class represent configuration of genetic algorithm
it gets parameters from json file  

"""



class Configuration:

    ##ovo moze da bude private members samo se dodaju dve crte dole i to ne moze da se dohvati sa C.populationSize ...


    # default constructor
    def __init__(self, jsonPath):

        #proveriti da li je validan json file

        if jsonPath == 'conf.json':

            file = open(jsonPath, "r")
            jsonData = json.loads(file.read());
            file.close();

            self.testPath = jsonData['testPath'];
            self.populationSize = jsonData['populationSize'];
            self.chromosomeSize = jsonData['chromosomeSize'];
            self.parentsNumber = jsonData['parentsNumber'];
            self.mutationRate = jsonData['mutationRate'];
            self.generationsCount = jsonData['generationsCount'];
        else:
            print('conf.json not found', file=sys.stderr);

