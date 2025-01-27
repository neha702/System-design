#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include<vector>
#include<deque>
#include<mutex>
using namespace std;

class Game{
deque<Player*>players;
Board* board;
static mutex mtx;
static Game* gameInstance;

public:
static Game* getGame() {
    if(!gameInstance) {
        mtx.lock();
        if(!gameInstance) {
            gameInstance = new Game();
        }
        mtx.unlock();
    }
    return gameInstance;
}

void initialisePlayers(int playersNum) {
    PlayPiece* crossPiece = new PlayPieceCross();
    PlayPiece* zeroPiece = new PlayPieceZero();
    Player* p1 = new Player(0 , crossPiece);
    players.push_back(p1);
    Player* p2 = new Player(1 , zeroPiece);
    players.push_back(p2);
}

Player* findTurn() {
    Player* p = players.front();
    cout << "Player " << p->getId() << " turn has come!" << endl;
    players.pop_front();
    return p;
}

bool isThereWinner(int row, int column, PieceType pieceType) {
    bool rowMatch = true;
    bool columnMatch = true;
    bool diagonalMatch = true;
    bool antiDiagonalMatch = true;
    vector<vector<PlayPiece*> > tictactoeBoard = board->getBoard();

    // Check the row
    for (int i = 0; i < board->getSize(); i++) {
        if (tictactoeBoard[row][i] == nullptr || tictactoeBoard[row][i]->getPieceType() != pieceType) {
            rowMatch = false;
        }
    }

    // Check the column
    for (int i = 0; i < board->getSize(); i++) {
        if (tictactoeBoard[i][column] == nullptr || tictactoeBoard[i][column]->getPieceType() != pieceType) {
            columnMatch = false;
        }
    }

    // Check the main diagonal
    for (int i = 0, j = 0; i < board->getSize(); i++, j++) {
        if (tictactoeBoard[i][j] == nullptr || tictactoeBoard[i][j]->getPieceType() != pieceType) {
            diagonalMatch = false;
        }
    }

    // Check the anti-diagonal
    for (int i = 0, j = board->getSize() - 1; i < board->getSize(); i++, j--) {
        if (tictactoeBoard[i][j] == nullptr || tictactoeBoard[i][j]->getPieceType() != pieceType) {
            antiDiagonalMatch = false;
        }
    }

    return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
}

void initialiseGame(int playersNum , int boardSize) {
initialisePlayers(playersNum);
board = new Board(boardSize);
}

void startGame() {
//find turn
while(true) {
    Player* player = findTurn();
    vector<vector<PlayPiece*> > tictactoeBoard = board->getBoard();

    //if adding piece possible
    bool addingPiecePossible = false;
    for(int i = 0 ; i < board->getSize() ; i++) {
        for(int j = 0 ; j < board->getSize() ; j++) {
            if(tictactoeBoard[i][j] == nullptr) {
                addingPiecePossible = true;
                break;
            }
        }
    }

    if(!addingPiecePossible) {
        cout << "Adding piece not possible as all filled in board , its a tie then!" << endl;
        return;
    }

    //add piece (if comes false then keep it doing until can place it)
    int row = 0;
    int col = 0;
    cout << "Enter row and col where playpiece to be put: " << endl;
    cin >> row >> col ;
    bool isPossibleToPlace = board->addPiece(row , col , player->getPiece());
    cout << "Player " << player->getId() << " to put the playpiece " << to_string(player->getPiece()->getPieceType()) << " in row " << row << " and col " << col << endl;
    if(!isPossibleToPlace) {
        cout << "Not possible to place the playpiece, try again" << endl;
        players.push_front(player);
        continue;
    } else {
        cout << "Player " << player->getId() << " has put the playpiece " << to_string(player->getPiece()->getPieceType()) << " in row " << row << " and col " << col << " successfully!" << endl;
    }

    //find if there is winner
    bool winner = isThereWinner(row , col , player->getPiece()->getPieceType());
    if (winner) {
        cout << "Player " << player->getId() << " won the game!" << endl;
        break;
    }
    players.push_back(player);
 }
}
};
Game* Game::gameInstance = nullptr;
mutex Game::mtx;
#endif