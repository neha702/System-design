package Design_qsns.Design_qsns_java.Design_chess.factory;

import Design_qsns.Design_qsns_java.Design_chess.enums.*;
import Design_qsns.Design_qsns_java.Design_chess.models.*;
import Design_qsns.Design_qsns_java.Design_chess.strategy.*;

public class PieceFactory {
    IPieceMovementStrategy kingMovementStrategy;
    IPieceMovementStrategy knightMovementStrategy;
    IPieceMovementStrategy roqueMovementStrategy;
    public PieceFactory() {
        PieceMovementStrategyFactory pieceMovementStrategyFactory = new PieceMovementStrategyFactory();
        this.kingMovementStrategy= pieceMovementStrategyFactory.createFactory(PieceType.KING);
        this.knightMovementStrategy = pieceMovementStrategyFactory.createFactory(PieceType.KNIGHT);
        this.roqueMovementStrategy= pieceMovementStrategyFactory.createFactory(PieceType.ROQUE);
    }
    public Piece createFactory(int r , int c , Colors color , PieceType type) {
        switch(type) {
            case KING:
                return new Piece(r , c , color , kingMovementStrategy , type);
            case KNIGHT:
                return new Piece(r , c , color ,knightMovementStrategy , type);
            case ROQUE:
                return new Piece(r , c , color , roqueMovementStrategy , type);
            default:
                return null;
        }
    }
}
