package Design_qsns.Design_qsns_java.Design_chess.strategy;
import Design_qsns.Design_qsns_java.Design_chess.models.*;
import java.util.*;

public interface IPieceMovementStrategy {
    public ArrayList<Cell> getValidMoves(Cell from , Board board);
}
