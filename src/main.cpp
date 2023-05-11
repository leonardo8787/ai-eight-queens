#include "genetic-algorithm/genetic-agorithm.hpp"
#include <chrono>

using namespace std;

// [x] - Jogar individuo no tabuleiro
// [x] - calcular numero de ataques (Fitness function)
// [x] - Selecionar (metade incial de um com metade final de outro)
// [x] - Crossover
// [x] - Mutação (Random)
// [x] - Reinicia com nova geração de individuo

int main(){
    auto startTime = chrono::steady_clock::now();

    GeneticAlgorithm ga(500); // GA with n individuals
    bool find = false;

    Individual x;
    Individual y;
    Individual child;

    ga.generateIndividualsOfPopulation();

    cout << "Tamanho da população: " << ga.population.size() << endl;

    cout << "Procurando solução ótima..." << endl;

    while(!find){
        ga.fitnessFunction();

        for(auto& individual: ga.population){
            if(individual.fitness == 0){
                cout << "\nPosição ótima encontrada!\n";
                cout << "[ ";
                for(unsigned int i=0; i<individual.queenPositions.size(); i++){
                    cout << individual.queenPositions[i] << " ";
                }
                cout << "]\n";
                cout << "Geração: " << ga.generation << endl;
                ga.board.fillBoard(individual.queenPositions);
                ga.board.printBoard();
                find = true;
            }
        }
        if(!find){
            for(unsigned int i=0; i<ga.population.size(); i++){
                int firstRandomIndex = ga.selection();
                int secondRandomIndex = ga.selection();
                
                copy(ga.population[firstRandomIndex].queenPositions.begin(), ga.population[firstRandomIndex].queenPositions.end(), x.queenPositions.begin());
                copy(ga.population[secondRandomIndex].queenPositions.begin(), ga.population[secondRandomIndex].queenPositions.end(), y.queenPositions.begin());

                ga.newPopulation.push_back(ga.reproduce(x, y));
            }
            ga.population.clear();
            for(unsigned int i=0; i<ga.newPopulation.size(); i++){
                ga.population.push_back(ga.newPopulation[i]);
            }
            ga.newPopulation.clear();
            ga.generation++;
        }
    }
    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

    cout << "Tempo de execução: " << duration << " milisegundos." << endl;
    cout << "Tempo de execução: " << duration/1000 << " segundos." << endl;

    return 0;
}