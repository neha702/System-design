package Design_qsns.Design_qsns_java.Design_chess.models;

public class Board {
    private Cell[][] cells;
    private Piece[] pieces;
    private static Board boardInstance = null;

    private Board() {
        cells = new Cell[8][8];
        for(int i = 0 ; i < 8 ; i++) {
            for(int j = 0 ; j < 8 ; j++) {
                cells[i][j] = new Cell(i, j, null);
            }
        }
        pieces = new Piece[32];
    }

    public void initializeBoard(Piece[] pieces) {
        //create pieces
        cells[0][4].setPiece(pieces[0]);
        cells[0][1].setPiece(pieces[1]);
        cells[0][6].setPiece(pieces[2]);
        cells[0][0].setPiece(pieces[3]);
        cells[0][7].setPiece(pieces[4]);
        cells[7][4].setPiece(pieces[5]);
        cells[7][1].setPiece(pieces[6]);
        cells[7][6].setPiece(pieces[7]);
        cells[7][0].setPiece(pieces[8]);
        cells[7][7].setPiece(pieces[9]);

    }

    public Cell getCell(int row , int col) {
        return cells[row][col];
    }

    public static Board getInstance() {
        if (boardInstance == null) {
            synchronized (Board.class) {
                if(boardInstance == null) {
                    boardInstance = new Board();
                }
            }
        }
        return boardInstance;
    }


}
