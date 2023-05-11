#ifndef GENETIC_ALGORITHM_HPP
#define GENETIC_ALGORITHM_HPP

#include "individual/individual.hpp"

using namespace std;

class GeneticAlgorithm {
    public:
        // Variables
        ChessBoard board;
        Sorting sort;
        vector<Individual> population;
        vector<Individual> newPopulation;
        int generation = 0;

        // Constructor
        GeneticAlgorithm(int numberOfIndividuals);

        // Methods
        void generateIndividualsOfPopulation();
        void fitnessFunction();
        int selection();
        Individual reproduce(Individual x, Individual y);
};

#endif
