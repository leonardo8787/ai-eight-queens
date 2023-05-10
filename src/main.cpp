#include "genetic-algorithm/genetic-agorithm.hpp"
using namespace std;

// [x] - Jogar individuo no tabuleiro
// [ ] - calcular numero de ataques (Fitness function)
// [ ] - Selecionar (metade incial de um com metade final de outro)
// [ ] - Crossover
// [ ] - Mutação (Random)
// [ ] - Reinicia com nova geração de individuo
// [ ] - Até 200 gerações

int main(){
    GeneticAlgorithm ga;

    while(ga.generation < 3){
        ga.generateIndividualsOfPopulation();
        ga.fitnessFunction();

        ga.generation++;
    }


    return 0;
}