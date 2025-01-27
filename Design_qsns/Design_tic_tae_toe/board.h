#ifndef BOARD_H
#define BOARD_H
using namespace std;

#include "playPiece.h"

class Board {
int size;
vector<vector<PlayPiece*> > board; // 2D vector of PlayPiece* pointers

public:
    // Constructor
    Board(int size){
        this->size = size;
        this->board = vector<vector<PlayPiece*> >(size , vector<PlayPiece*>(size , nullptr));
    }

bool addPiece(int row , int col , PlayPiece* piece) {
    if(board[row][col] != nullptr) {
        cout << "Piece can't be placed in " << row << " and col " << col << endl; 
        return false;
    } else {
        board[row][col] = piece;
        return true;
    }
}

vector<vector<PlayPiece*> > getBoard() {
    return board;
}

int getSize() {
    return size;
}
};

#endif