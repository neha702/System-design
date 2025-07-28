package Design_qsns.Design_qsns_java.Design_chess.models;

public class Cell {
    private int row;
    private int col;
    private Piece piece;

    Cell(int row , int col , Piece piece) {
        this.row = row;
        this.col = col;
        this.piece = piece;
    }

    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    public void setPiece(Piece piece) {
        this.piece = piece;
    }

    public Piece getPiece() {
        return piece;
    }
}
