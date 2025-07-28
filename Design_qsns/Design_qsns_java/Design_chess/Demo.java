package Design_qsns.Design_qsns_java.Design_chess;
import Design_qsns.Design_qsns_java.Design_chess.services.*;

public class Demo {
    /*
     Requirements:
     1. We need board of 8*8 cells
     2. We need 16 pieces each side.
     3.  We are considering 2 players.
     4. We are considering two players would be playing the game.
     5. Players will play match until game is over/ending comditon is reached.
     6. Movement of pieces as per standard route.
     7. We can have strategies of players too - human or AI(optional)
     8. Each piece would have its own movement stratqegy.
     */
    public static void main(String[] args) {
        //Create a game and start it;
        Game game = new Game();
        game.intialiseGame();
        game.startGame();
    }
}
