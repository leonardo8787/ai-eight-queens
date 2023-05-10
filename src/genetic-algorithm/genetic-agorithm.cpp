#include "genetic-agorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm() : population(4, vector<int>(8, 0)) {}

void GeneticAlgorithm::generateIndividualsOfPopulation(){
    for(unsigned int i=0; i<this->population.size(); i++){
        for(unsigned int j=0; j<this->population[i].size(); j++){
            this->population[i][j] = sort.sorting(8); // sort a integer between 1 and 8
        }
    }
}

void GeneticAlgorithm::fitnessFunction(){
    vector<int> numberOfConflicts(this->population.size(), 0); // number of conflicts for each population  
    int conflictsInAPopulation; // total conflicts in one population
    
    for(auto individual: this->population){
        this->board.fillBoard(individual);

        // Calculating conflicts
        conflictsInAPopulation = this->board.returnNumberOfConflicts(individual);
        numberOfConflicts.push_back(conflictsInAPopulation);
    }

}