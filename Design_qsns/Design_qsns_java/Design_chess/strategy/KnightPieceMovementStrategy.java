package Design_qsns.Design_qsns_java.Design_chess.strategy;

import Design_qsns.Design_qsns_java.Design_chess.models.Board;
import Design_qsns.Design_qsns_java.Design_chess.models.Cell;
import java.util.ArrayList;

public class KnightPieceMovementStrategy implements IPieceMovementStrategy{
    int [][]dir = {{1,2} , {1, -2} , {2,1} , {2,-1} , {-1,2} , {-1, -2} , {-2,1} , {-2,-1}};
    public ArrayList<Cell> getValidMoves(Cell from , Board board) {
        //first find positions and then choose the valid ones
        int fromRow = from.getRow();
        int fromCol = from.getCol();
        ArrayList<Cell>ans = new ArrayList<>();
        
        for(int k = 0 ; k < 8 ; k++) {
            int new_row = fromRow + dir[k][0];
            int new_col = fromCol + dir[k][1];
            if(new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
                ans.add(board.getCell(new_row, new_col));
            }
        }
        return ans;
    }
}
