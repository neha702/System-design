#ifndef BATCONTROLLER_H
#define BATCONTROLLER_H
#include "player.h"
#include <queue>
#include <iostream>

class BatController {
    queue<Player*> playerQueue;
    Player* striker;
    Player* nonStriker;
public:
    Player* getStriker() {
        return striker;
    }

    Player* getNonStriker() {
        return nonStriker;
    }

    void setStriker(Player* player) {
        this->striker = player;
    }

    void setNonStriker(Player* player) {
        this->nonStriker = player;
    }

   bool chooseNextBatsman() {
        if(playerQueue.empty()) {
            cout << "No more players to play!" << endl;
            return false;
        }
        
        //cout << "next player is " << playerQueue.front()->getName() << endl;
        striker = playerQueue.front();
        playerQueue.pop();
        return true;
    }

   void addBatsman(Player* player) {
        cout << "Player " << player->getName() << " is added as batsman!" << endl;
        playerQueue.push(player);
    }

    bool chooseInitialBatsmen() {
        if(!playerQueue.empty()) {
            striker = playerQueue.front();
            playerQueue.pop();
        } else {
            cout << "No batsman to be striker" << endl;
            return false;
        }

         if(!playerQueue.empty()) {
                nonStriker = playerQueue.front();
                playerQueue.pop();
        } else {
                cout << "No batsman to be non striker" << endl;
                return false;
        }

        return true;
    }
};

#endif // BATCONTROLLER_H