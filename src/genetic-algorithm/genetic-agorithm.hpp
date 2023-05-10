#ifndef GENETIC_ALGORITHM_HPP
#define GENETIC_ALGORITHM_HPP

#include "../chess-board/chess-board.hpp"

using namespace std;

class GeneticAlgorithm {
    public:
        // Variables
        ChessBoard board;
        Sorting sort; // Voltar aqui
        vector<vector<int>> population;
        int generation = 0;

        // Constructor
        GeneticAlgorithm();

        // Methods
        void generateIndividualsOfPopulation();
        void fitnessFunction();
};

#endif
