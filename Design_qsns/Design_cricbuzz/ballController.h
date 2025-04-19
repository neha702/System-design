#ifndef BALLCONTROLLER_H
#define BALLCONTROLLER_H
#include <deque>
#include "player.h"
#include <map>
#include <iostream>

class BallController {
    deque<Player*> playerQueue;
    Player* bowler;
    map<Player* , int>bowlerOversMap;
    map<Player*,int>bowlerRunsMap;
public:
    void incOvers(Player* p) {
       bowlerOversMap[p] += 1;
    }

    bool chooseNextBaller(int oversAllowedPerPlayer) {
        if(playerQueue.empty()) {
            cout << "No more bowls to bowl!" << endl;
            return false;
        } else {
            Player* currBowler = playerQueue.front();
            playerQueue.pop_front();
            cout << currBowler->getName() << " " << bowlerOversMap[currBowler] << " " << oversAllowedPerPlayer << endl;
            bowler = playerQueue.front();
            if(bowlerOversMap[currBowler] < oversAllowedPerPlayer) {
                playerQueue.push_back(currBowler);
                return true;
            }
        }
        return false;
    }

    void addBowler(Player* player) {
        cout << "Player " << player->getName() << " is added as bowler!" << endl;
        playerQueue.push_back(player);
        bowlerRunsMap[player] = 0;
        bowler = player;
    }

    int getRunsForPlayer() {
        return bowlerRunsMap[bowler];
    }

    void setRunsForPlayer(Player* p , int runs) {
        bowlerRunsMap[p] += runs;
    }

    Player* getCurrBowler() {
        return bowler;
    }
};

#endif // BALLCONTROLLER_H