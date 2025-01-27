#ifndef PLAYER_H
#define PLAYER_H

#include "playPiece.h"

class Player{
int userId;
PlayPiece* piece;
public:
Player(int id , PlayPiece* piece) {
    this->userId = id;
    this->piece = piece;
}

PlayPiece* getPiece() {
    return piece;
}

int getId() {
    return userId;
}
};

#endif