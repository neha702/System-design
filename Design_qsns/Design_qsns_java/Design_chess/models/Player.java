package Design_qsns.Design_qsns_java.Design_chess.models;
import Design_qsns.Design_qsns_java.Design_chess.enums.*;
import Design_qsns.Design_qsns_java.Design_chess.services.PieceCreationSvc;
public class Player {
    private String name;
    private Colors color;

    public Player(String name , Colors color) {
        this.name = name;
        this.color = color;
    }

    public int makeMove(Move move , Piece chosenPiece , Board board , PieceCreationSvc pieceCreationSvc) {
        Cell from = move.getFromCell();
        Piece currPiece = from.getPiece();
        Cell to = move.getToCell();
        Piece destPiece = to.getPiece();

        if(currPiece == null) {
            System.out.println("No piece at the source cell");
            return 0;
        }

        if(!(currPiece.isValidMove(from, to , board))) {
            System.out.println("Not a valid move, try something new");
            return 2;
        }

        if(destPiece != null && destPiece.getColor() == currPiece.getColor()) {
            System.out.println("Cannot capture own piece");
            return 2;
        }

        //Update position of chosen piece
        chosenPiece.setRow(to.getRow());
        chosenPiece.setCol(to.getCol());

        if(destPiece != null && destPiece.getType() == PieceType.KING) {
            System.out.println("King is captured! Game Over!");
            return 1;
        }

        //Update pieces on cells
        from.setPiece(null);
        //This piece is inactive so remove from piecesMap
        if(to.getPiece() != null) {
            Piece capturedPiece = to.getPiece();
            pieceCreationSvc.updatePiecesMap(capturedPiece.getType().name(), capturedPiece.getColor().name() , capturedPiece);
        }
        to.setPiece(currPiece);

        return 0;
    }

    public String getName() {
        return name;
    }

    public Colors getColor() {
        return color;
    }
}