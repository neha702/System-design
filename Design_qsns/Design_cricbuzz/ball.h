#ifndef BALL_H
#define BALL_H
#include "player.h"
#include <iostream>
#include "scoreObserver.h"

class Ball
{
    int ballNum;
    Player *playedBy;
    Player *bowledBy;
    RunType runType;
    BallType ballType;
    vector<ScoreObserver*> observers;

public:
    Ball(Player *playedBy, Player *bowledBy)
    {
        this->playedBy = playedBy;
        this->bowledBy = bowledBy;
        observers.push_back(new BatScoreObserver());
        observers.push_back(new BallScoreObserver());
    }

    int playBall()
    {
        BallType currBallType = getCurrBallType();
        this->ballType = currBallType;
        if(currBallType == WICKETBALL) {
            //player is out
            cout << "Wicket taken by " << bowledBy->getName() << " of " << playedBy->getName() << endl;
            RunType currRunType = ZERO;
            this->runType = currRunType;
        } else if(currBallType == WIDEBALL) {
            cout << "Wide ball thrown!" << endl;
            RunType currRunType = ONE;
            this->runType = currRunType;
        } else {
            RunType currRunType = getCurrRunType();
            this->runType = currRunType;
        }

        
        int runs = getRuns();
        cout << "Player " << playedBy->getName() << " scored " << runs << " runs!" << endl;

        for(auto obs : observers) {
            obs->notify(playedBy , bowledBy , runs , ballType);
        }

        return runs;
    }

    int getRuns()
    {
        if(runType == ONE) {
            return 1;
        } else if(runType == TWO) {
            return 2;
        } else if(runType == FOUR) {
            return 4;
        } else if(runType == SIX) {
            return 6;
        }
        return 0;
    }

    double getRandom()
    {
        return (double)rand() / (RAND_MAX + 1.0);
    }

    RunType getCurrRunType()
    {
        double randomVal = getRandom();

        if(randomVal <= 0.2) {
            return ONE;
        } else if (randomVal > 0.2 && randomVal <= 0.4) {
            return TWO;
        } else if (randomVal > 0.4 && randomVal <= 0.6) {
            return FOUR;
        } else if (randomVal > 0.6 && randomVal <= 0.8){
            return SIX;
        } else  ZERO;
    }

    BallType getCurrBallType()
    {
        double randomVal = getRandom();

        if(randomVal <= 0.4) {
            return NORMALBALL;
        } else if (randomVal > 0.4 && randomVal <= 0.6) {
            return WIDEBALL;
        } else if (randomVal > 0.6 && randomVal <= 0.8) {
            return NOBALL;
        } else {
            return WICKETBALL;
        }
    }

    BallType getBallType() {
        return ballType;
    }
};

#endif // BALL_H