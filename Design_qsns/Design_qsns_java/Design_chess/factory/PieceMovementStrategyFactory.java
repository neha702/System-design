package Design_qsns.Design_qsns_java.Design_chess.factory;
import Design_qsns.Design_qsns_java.Design_chess.enums.PieceType;
import Design_qsns.Design_qsns_java.Design_chess.strategy.IPieceMovementStrategy;
import Design_qsns.Design_qsns_java.Design_chess.strategy.KingPieceMovementStrategy;
import Design_qsns.Design_qsns_java.Design_chess.strategy.KnightPieceMovementStrategy;
import Design_qsns.Design_qsns_java.Design_chess.strategy.RoquePieceMovementStrategy;

public class PieceMovementStrategyFactory {
    public IPieceMovementStrategy createFactory(PieceType pieceType) {
        switch(pieceType) {
            case KING : return new KingPieceMovementStrategy();
            case KNIGHT :  return new KnightPieceMovementStrategy();
            case ROQUE : return new RoquePieceMovementStrategy();
            default : return null;
        }
    }
}
