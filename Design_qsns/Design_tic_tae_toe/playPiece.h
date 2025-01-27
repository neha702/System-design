#ifndef PLAYPIECE_H
#define PLAYPIECE_H

#include "pieceType.h"

class PlayPiece {
protected:
    PieceType pieceType;

public:
    // Constructor requiring a PieceType
    PlayPiece(PieceType type) : pieceType(type) {}

    // Virtual destructor for proper cleanup
    virtual ~PlayPiece() {}

    // Getter for pieceType
    PieceType getPieceType() const {
        return pieceType;
    }
};

class PlayPieceCross : public PlayPiece {
public:
    // Properly initialize base class using the initializer list
    PlayPieceCross() : PlayPiece(PieceType::CROSS) {}
};

class PlayPieceZero : public PlayPiece {
public:
    // Properly initialize base class using the initializer list
    PlayPieceZero() : PlayPiece(PieceType::ZERO) {}
};

#endif
