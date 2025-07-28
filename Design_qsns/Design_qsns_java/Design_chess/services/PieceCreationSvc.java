package Design_qsns.Design_qsns_java.Design_chess.services;

import Design_qsns.Design_qsns_java.Design_chess.enums.Colors;
import Design_qsns.Design_qsns_java.Design_chess.enums.PieceType;
import Design_qsns.Design_qsns_java.Design_chess.factory.PieceFactory;
import Design_qsns.Design_qsns_java.Design_chess.models.Piece;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PieceCreationSvc {
    private PieceFactory pieceFactory;
    private Map<String , Map<String , List<Piece>>>piecesMap; // Keep all active pieces

    public PieceCreationSvc(PieceFactory pieceFactory) {
        this.pieceFactory = pieceFactory;
        this.piecesMap = new HashMap<>();
    }

    public Map<String , Map<String , List<Piece>>> getPiecesMap() {
        return piecesMap;
    }

    public void updatePiecesMap(String pieceType , String color , Piece actualpiece) {
        if(piecesMap.containsKey(pieceType)) {
            if(piecesMap.get(pieceType).containsKey(color)) {
                List<Piece> piecesList = piecesMap.get(pieceType).get(color);
                for(Piece pieceItr : piecesList) {
                    if(pieceItr == actualpiece) {
                        piecesList.remove(pieceItr);
                        break;
                    }
                }
            }
        }
    }
    
    public Piece[] createPieces() {
        Piece[] pieces = new Piece[32];
        // Initialize the pieces array
        for (int k = 0; k < 16; k++) {
                pieces[k] = null;
        }
        pieces[0] = pieceFactory.createFactory(0, 4, Colors.WHITE, PieceType.KING);
        piecesMap.computeIfAbsent(PieceType.KING.name() , k -> new HashMap<>()).computeIfAbsent(Colors.WHITE.name(), i ->new ArrayList<>()).add(pieces[0]);
        pieces[1] = pieceFactory.createFactory(0, 1, Colors.WHITE, PieceType.KNIGHT);
        pieces[2] =  pieceFactory.createFactory(0, 6, Colors.WHITE, PieceType.KNIGHT);
        piecesMap.computeIfAbsent(PieceType.KNIGHT.name() , k -> new HashMap<>()).computeIfAbsent(Colors.WHITE.name(), i ->new ArrayList<>()).addAll(Arrays.asList(pieces[1], pieces[2]));
        pieces[3] = pieceFactory.createFactory(0, 0, Colors.WHITE, PieceType.ROQUE);
        pieces[4] = pieceFactory.createFactory(0, 7, Colors.WHITE, PieceType.ROQUE);
        piecesMap.computeIfAbsent(PieceType.ROQUE.name() , k -> new HashMap<>()).computeIfAbsent(Colors.WHITE.name(), i ->new ArrayList<>()).addAll(Arrays.asList(pieces[3], pieces[4]));


        pieces[5] = pieceFactory.createFactory(7, 4, Colors.BLACK, PieceType.KING);
        piecesMap.computeIfAbsent(PieceType.KING.name() , k -> new HashMap<>()).computeIfAbsent(Colors.BLACK.name(), i ->new ArrayList<>()).add(pieces[5]);
        pieces[6] = pieceFactory.createFactory(7, 1, Colors.WHITE, PieceType.KNIGHT);
        pieces[7] = pieceFactory.createFactory(7, 6, Colors.BLACK, PieceType.KNIGHT);
        piecesMap.computeIfAbsent(PieceType.KNIGHT.name() , k -> new HashMap<>()).computeIfAbsent(Colors.BLACK.name(), i ->new ArrayList<>()).addAll(Arrays.asList(pieces[6], pieces[7]));
        pieces[8] = pieceFactory.createFactory(7, 0, Colors.BLACK, PieceType.ROQUE);
        pieces[9] = pieceFactory.createFactory(7, 7, Colors.BLACK, PieceType.ROQUE);
        piecesMap.computeIfAbsent(PieceType.ROQUE.name() , k -> new HashMap<>()).computeIfAbsent(Colors.BLACK.name(), i ->new ArrayList<>()).addAll(Arrays.asList(pieces[8], pieces[9]));
        return pieces;
    }
}
