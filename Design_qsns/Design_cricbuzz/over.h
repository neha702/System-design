#ifndef OVER_H
#define OVER_H
#include <vector>
#include "ball.h"
#include "team.h"

class Over {
vector<Ball*>balls;
int overNumber;
Player* bowledBy;
public:
Over(int overNum , Player* bowledBy) {
    this->overNumber = overNum;
    this->bowledBy = bowledBy;
}

int startOver(Team* ballingTeam , Team* battingTeam, int runsToChase) {
    for(int i = 1 ; i <= 6 ; i++) {
        cout << "Ball " << i << " starts!" << endl; 
        Ball* newBall = new Ball(battingTeam->getStriker() , ballingTeam->getCurrBowler());
        balls.push_back(newBall);
        int runsMade = newBall->playBall();
        ballingTeam->setRunsForPlayer(ballingTeam->getCurrBowler() , runsMade);
        if(newBall->getBallType() == WICKETBALL) {
            //player is out
            cout << "Player " << battingTeam->getStriker()->getName() << " is out!" << endl;
            if(!battingTeam->chooseNextBatsman()) {
               return 2;
            }
        }
        if(runsToChase != -1){
            if(runsMade > runsToChase) return true;
            if(runsToChase > runsMade) runsToChase -= runsMade;
        }
        battingTeam->setTotalRunsScored(runsMade);
    }

    return runsToChase == 0;
}
};

#endif // OVER_H