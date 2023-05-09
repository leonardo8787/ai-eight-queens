#include "tabuleiro.hpp"

// Jogar individuo no tabuleiro
// calcular numero de ataques (Fitness function)
// Selecionar (metade incial de um com metade final de outro)
// Crossover
// Mutação (Random)
// Reinicia com nova geração de individuo
// Até 200 gerações

int main(){
    Tabuleiro Itera1;
    vector<vector<int>> tabuleiro(8, vector<int>(8, 0));
    vector<vector<int>> listaDeIndividuos(4, vector<int>(8, 0));
    vector<int> numeroAtaquesPorIndividuos(vector<int>(4,0));
    int geracao = 0;

    Itera1.gerarIndividuos(listaDeIndividuos);
    Itera1.printMatriz(listaDeIndividuos);
    cout << "\n\n";

    while(geracao < 1){
        Itera1.fitnessFunction(numeroAtaquesPorIndividuos, listaDeIndividuos, tabuleiro);
        geracao++;
    }

    return 0;
}