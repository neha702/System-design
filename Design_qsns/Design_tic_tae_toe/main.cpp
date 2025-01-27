#include "../../bitsStd.h"
#include "game.h"
using namespace std;

int main() {
    Game* game = Game::getGame();

    int playersNum = 0;
    int boardSize = 0;

    cout << "Enter number of players: " << endl; 
    cin >> playersNum;

    cout << "Enter number of boards size: " << endl; 
    cin >> boardSize;

    game->initialiseGame(playersNum , boardSize);
    game->startGame();

}