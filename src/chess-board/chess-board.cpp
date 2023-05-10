#include "chess-board.hpp"

ChessBoard::ChessBoard() : board(8, vector<int>(8, 0)) {}

void ChessBoard::fillBoard(vector<int> individual) {
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            this->board[i][j] = 0;
        }
    }

    for(unsigned int j=0; j<this->board.size(); j++){
        unsigned int queenPositionInColumn = individual[j];
        for(unsigned int i=0; i<this->board.size(); i++){
            if(i+1 == queenPositionInColumn){
                this->board[i][j] = queenPositionInColumn;
            }
        }
    }
}

void ChessBoard::printBoard(){
    for(unsigned int i=0; i<this->board.size(); i++){
        for(unsigned int j=0; j<this->board[i].size(); j++){
            cout << this->board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

int ChessBoard::returnNumberOfConflicts(vector<int> individual) {
    // TODO

    return 0;
}
