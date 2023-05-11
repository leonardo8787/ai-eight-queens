#include "genetic-agorithm.hpp"
#include <random>

GeneticAlgorithm::GeneticAlgorithm(int numberOfIndividuals) {
    this->population.reserve(numberOfIndividuals);
    
    for (int i=0; i<numberOfIndividuals; i++) {
        Individual individual;
        this->population.push_back(individual);
    }
}

void GeneticAlgorithm::generateIndividualsOfPopulation(){
    for(unsigned int i=0; i<this->population.size(); i++){
        for(unsigned int j=0; j<this->population[i].queenPositions.size(); j++){
            this->population[i].queenPositions[j] = sort.sorting(8); // sort a integer between 1 and 8
        }
    }
}

void GeneticAlgorithm::fitnessFunction(){
    for(auto& individual: this->population){
        this->board.fillBoard(individual.queenPositions);
        // Calculating conflicts
        individual.fitness =  this->board.returnNumberOfConflicts(individual.queenPositions);
    }
}

int GeneticAlgorithm::selection(){
    int totalFitnessPopulation = 0;

    for(const auto& individual: this->population){
        totalFitnessPopulation = individual.fitness;
    }

    // Creating a custom probability distribution
    random_device rd;
    default_random_engine engine(rd());
    discrete_distribution<int> distribution;

    // Mapping fitness function values to probabilities
    vector<double> probabilities;
    for (const auto& individual : this->population) {
        probabilities.push_back(static_cast<double>(totalFitnessPopulation - individual.fitness + 1) / totalFitnessPopulation);
    }

    // Configuring the probability distribution based on calculated probabilities
    distribution = discrete_distribution<int>(probabilities.begin(), probabilities.end());

    // Generating a random index based on probabilities
    int randomIndex = distribution(engine);

    return randomIndex;
}

Individual GeneticAlgorithm::reproduce(Individual x, Individual y){
    Individual child;
    child.queenPositions.clear();

    // Split the original vector into two parts
    // cout << "X1 = ";
    for(int i=0; i<4; i++){
        // cout << x.queenPositions[i] << " ";
        child.queenPositions.push_back(x.queenPositions[i]);
    }
    // cout << "\n";
    // cout << "Y2 = ";
    for(int i=4; i<8; i++){
        // cout << y.queenPositions[i] << " ";
        child.queenPositions.push_back(y.queenPositions[i]);
    }

    //cout << "\n";

    // Mutation
    int indexChromosome = this->sort.sorting(8);
    int newChromosome = this->sort.sorting(8);

    child.queenPositions[indexChromosome] = newChromosome;

    // cout << "Filho:\n";
    // cout << "[ ";
    // for(auto& i: child.queenPositions){
    //     cout << i << " ";
    // }
    // cout << "]" << endl;
    
    return child;
}