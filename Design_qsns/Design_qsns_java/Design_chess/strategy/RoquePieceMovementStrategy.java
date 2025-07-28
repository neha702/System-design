package Design_qsns.Design_qsns_java.Design_chess.strategy;

import Design_qsns.Design_qsns_java.Design_chess.models.Board;
import Design_qsns.Design_qsns_java.Design_chess.models.Cell;
import java.util.ArrayList;

public class RoquePieceMovementStrategy implements IPieceMovementStrategy {
    public ArrayList<Cell> getValidMoves(Cell from , Board board) {
        //try all cels in board if they share any column or row they can be placed
        int fromRow = from.getRow();
        int fromCol = from.getCol();
        ArrayList<Cell>ans = new ArrayList<>();

        for(int i = 0 ; i < 8 ; i++) {
            for(int j = 0 ; j < 8 ; j++) {
                if(i >= 0 && i < 8 && j >= 0 && j < 8) {
                    if(i == fromRow && j == fromCol) {
                        continue; 
                    }

                    if(i == fromRow || j == fromCol) {
                        ans.add(board.getCell(i, j));
                    }
                } 
            }
        }
        return ans;
    }
}
