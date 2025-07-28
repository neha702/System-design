package Design_qsns.Design_qsns_java.Design_chess.services;

import java.util.List;

import Design_qsns.Design_qsns_java.Design_chess.models.*;

public class PieceFinderSvc {
    Piece findPiece(int pieceNum , List<Piece> piecesList) {
        switch(pieceNum) {
            case 1: {
                return piecesList.get(0);
            }
            case 2: {
                return piecesList.get(1);
            }
            default : return null;
        }
    }
}
