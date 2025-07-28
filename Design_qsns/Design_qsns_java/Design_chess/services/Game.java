package Design_qsns.Design_qsns_java.Design_chess.services;
import Design_qsns.Design_qsns_java.Design_chess.enums.*;
import Design_qsns.Design_qsns_java.Design_chess.factory.PieceFactory;
import Design_qsns.Design_qsns_java.Design_chess.models.*;
import java.util.*;

public class Game {
    private Board board = null;
    private Deque<Player> players;
    private GameStatus gameStatus;
    private PieceFinderSvc pieceFinderSvc = null;
    private PieceCreationSvc pieceCreationSvc = null;
    private PieceFactory pieceFactory = null;

    public Game() {
        this.board = Board.getInstance();
        this.players = new ArrayDeque<>();
        this.gameStatus = GameStatus.STARTED;
        this.pieceFinderSvc = new PieceFinderSvc();
        this.pieceFactory = new PieceFactory();
        this.pieceCreationSvc = new PieceCreationSvc(pieceFactory);
    }

    public void intialiseGame() {
        //Create pieces
        Piece[] pieces = pieceCreationSvc.createPieces();
        //Initialise board
        board.initializeBoard(pieces);
        //Intialise players
        Player player1 = new Player("Neha" , Colors.WHITE);
        Player player2 = new Player("Rohit" , Colors.BLACK);
        players.add(player1);
        players.add(player2);
    }

    public void startGame() {
        Scanner sc = new Scanner(System.in);
        this.gameStatus = GameStatus.ONGOING;
        while(gameStatus == GameStatus.ONGOING) {
            //Choose player
            Player currentPlayer = players.peekFirst();
            Colors currentColor = currentPlayer.getColor();
            players.removeFirst();
            players.addLast(currentPlayer);
            System.out.println("Current Player: " + currentPlayer.getName() + " (" + currentPlayer.getColor().name() + ")");

            //Choose a piece by player
            System.out.println("Choose the piece");
            String pieceType = sc.next();
            if(pieceCreationSvc.getPiecesMap() == null) {
                System.out.println("No pieces available for type " + pieceType);
                return;
            }
            Piece chosenPiece = null;
            

            if(!pieceCreationSvc.getPiecesMap().containsKey(pieceType)) {
                System.out.println("Invalid piece type " + pieceType + " , choose again!"); 
                continue;
            } else {
                if(!pieceCreationSvc.getPiecesMap().get(pieceType).containsKey(currentColor.name())) {
                    System.out.println("No pieces of type " + pieceType + " for color " + currentColor.name() + " , choose again!");
                    continue;
                }            
                List<Piece> piecesList = pieceCreationSvc.getPiecesMap().get(pieceType).get(currentColor.name());
                while(true) {
                    if(piecesList == null) {
                        System.out.println("No pieces of type " + pieceType + " for color " + currentColor.name());
                        continue;
                    }

                    if(piecesList.size() > 1) {
                        int pieceNum = sc.nextInt();
                        chosenPiece = pieceFinderSvc.findPiece(pieceNum , piecesList);
                        break;
                        // if(chosenPiece == null) {
                        //     System.out.println("Invalid piece number , choose again!");
                        //     continue;
                        // }
                    } else {
                        chosenPiece = piecesList.get(0);
                        break;
                    }
                 }
                }

            System.out.println("Piece chosen of type: " + chosenPiece.getType().name() + " at position: (" + chosenPiece.getPieceCell(board).getRow() + ", " + chosenPiece.getPieceCell(board).getCol() + ")");
            
            //Make the move by taking input from player
            while(true){
                System.out.println("Choose the position to move");
                int r = sc.nextInt();
                int c = sc.nextInt();
                Cell toCell = board.getCell(r, c);
                Cell fromCell = chosenPiece.getPieceCell(board);
                Move move = new Move(fromCell , toCell);
                //Decide if game is over or not
                int result = currentPlayer.makeMove(move , chosenPiece , board , pieceCreationSvc);
                if(result == 2) {
                    continue;
                }
                if(result == 1){
                    System.out.println("Game won by " + currentPlayer.getName() + " (" + currentPlayer.getColor().name() + ")");
                    this.gameStatus = GameStatus.WIN;
                    break;
                }

                if(result == 0) {
                    System.out.println("Move made successfully!");
                    break;
                }
           }
        }
        sc.close();
    }
}
