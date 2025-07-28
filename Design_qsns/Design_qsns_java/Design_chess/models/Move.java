package Design_qsns.Design_qsns_java.Design_chess.models;

public class Move {
    Cell from;
    Cell to;

    public Move(Cell from , Cell to ) {
        this.from = from;
        this.to = to;
    }

    public Cell getFromCell() 
    {
        return from;
    }

    public Cell getToCell() 
    {
        return to;
    }
}
