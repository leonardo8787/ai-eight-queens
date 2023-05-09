#ifndef TABULEIRO_H
#define Tabuleiro_H

#include<bits/stdc++.h>
using namespace std;

class Tabuleiro {
    private:
        
    public: 
        int sortearPosicaoRainha(){
            struct timespec ts;
            clock_gettime(CLOCK_MONOTONIC, &ts);
            // usando nanosegundos ao invés de segundos
            srand((time_t)ts.tv_nsec);

            return (rand() % 8) + 1;
        }

        void gerarIndividuos(vector<vector<int>> &listaDeIndividuos){
            for(int i=0; i<listaDeIndividuos.size(); i++){
                for(int j=0; j<listaDeIndividuos[i].size(); j++){
                    listaDeIndividuos[i][j] = sortearPosicaoRainha();
                }
            }
        }

        void printMatriz(vector<vector<int>> vec){
            for(int i=0; i<vec.size(); i++){
                for(int j=0; j<vec[i].size(); j++){
                    cout << vec[i][j] << " ";
                }
                cout << endl;
            }
        }

        void preencherTabuleiro(vector<int>&individuo, vector<vector<int>> &tabuleiro){
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    tabuleiro[i][j] = 0;
                }
            }

            for(int j=0; j<tabuleiro.size(); j++){
                int posicaoRainhaNaColuna = individuo[j];
                for(int i=0; i<tabuleiro.size(); i++){
                    if(i+1 == posicaoRainhaNaColuna){
                        tabuleiro[i][j] = posicaoRainhaNaColuna;
                    }
                }
            }
        }

        void fitnessFunction(vector<int> &numeroAtaquesPorIndividuo, vector<vector<int>> &listaDeIndividuos, vector<vector<int>> &tabuleiro){
            for(auto individuo: listaDeIndividuos){
                preencherTabuleiro(individuo, tabuleiro);
                printMatriz(tabuleiro);
                cout << "\n";
                // break;
            }
        }
};

#endif