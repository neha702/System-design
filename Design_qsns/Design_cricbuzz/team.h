#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include <queue>
#include "player.h"
#include "ballController.h"
#include "batController.h"
using namespace std;

class Team {
vector<Player*>players;
queue<Player*>playerQueue;
BallController* ballController;
BatController* batController;
string teamName;
int totalRunsScored;

public:
Team(string teamName) {
    this->teamName = teamName;
    this->ballController = new BallController();
    this->batController = new BatController();
}

void addPlayer(Player* p) {
    players.push_back(p);
    playerQueue.push(p);
    if(p->getPlayerType() == BOWLER)
        ballController->addBowler(p);
    else batController->addBatsman(p);
}

string getTeamName() {
    return teamName;
}

int getTotalRunsScored() {
    return totalRunsScored;
}

void setTotalRunsScored(int runs) {
    this->totalRunsScored = this->totalRunsScored + runs;
}

bool chooseNextBaller(int oversAllowedPerPlayer) {
    return ballController->chooseNextBaller(oversAllowedPerPlayer);
}

void incOvers(Player* p) {
    return ballController->incOvers(p);
}

bool chooseNextBatsman() {
    return batController->chooseNextBatsman();
}

Player* getCurrBowler() {
    return ballController->getCurrBowler();
}

Player* getStriker() {
    return batController->getStriker();
}

Player* getNonStriker() {
    return batController->getNonStriker();
}

void setStriker(Player* player) {
    batController->setStriker(player);
}

void setNonStriker(Player* player) {
    batController->setNonStriker(player);
}

void printBattingScoreCard() {
    for(auto player : players) {
        player->printBatScoreCard();
        cout << endl;
    }
}

void printBowlingScoreCard() {
    for(auto player : players) {
        player->printBallScoreCard();
        cout << endl;
    }
}

bool chooseInitialBatsmen() {
    return batController->chooseInitialBatsmen();
}

void setRunsForPlayer(Player* p , int runs) {
        ballController->setRunsForPlayer(p , runs);
}
};

#endif // TEAM_H