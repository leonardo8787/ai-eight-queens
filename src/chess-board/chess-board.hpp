#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <iostream>
#include <string>
#include <vector>
#include "../utils/sort.hpp"

using namespace std;

class ChessBoard {
    public:
        // Variables
        vector<vector<int>> board;

        // Constructor
        ChessBoard();

        // Methods
        void fillBoard(vector<int> individual);
        void printBoard();
        int returnNumberOfConflicts(vector<int>individual);
};

#endif
