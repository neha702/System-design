package Design_qsns.Design_qsns_java.Design_chess.models;
import Design_qsns.Design_qsns_java.Design_chess.enums.*;
import Design_qsns.Design_qsns_java.Design_chess.strategy.*;
import java.util.*;

public class Piece {
    int row;
    int col;
    Colors color;
    PieceType type;
    boolean isActive;

    IPieceMovementStrategy pieceStrategy;

    public  Piece(int row, int col, Colors color, IPieceMovementStrategy pieceStrategy , PieceType type) {
        this.row = row;
        this.col = col;
        this.color = color;
        this.isActive = true;
        this.type = type;
        this.pieceStrategy = pieceStrategy;
    }

    public Colors getColor() {
        return color;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public void setCol(int col) {
        this.col = col;
    }

    public PieceType getType() {
        return type;
    }


   boolean isValidMove(Cell from , Cell to , Board board) {
    if(from == null || to == null) {
        return false;
    }

    ArrayList<Cell> possibleCells = pieceStrategy.getValidMoves(from , board);
    for(Cell cell : possibleCells) {
        if(cell.getRow() == to.getRow() && cell.getCol() == to.getCol()) {
            return true;
        }
    }
    return false;
   }

   public Cell getPieceCell(Board board) {
    return board.getCell(row, col);
   }
    
}
