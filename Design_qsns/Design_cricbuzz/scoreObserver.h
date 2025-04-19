#ifndef SCOREOBSERVER_H
#define SCOREOBSERVER_H
#include "ball.h"

class ScoreObserver {
public:
virtual void notify(Player *playedBy,  Player *bowledBy ,int runs , BallType ballType) = 0;
};

class BatScoreObserver : public ScoreObserver {
public:
void notify(Player *playedBy,  Player *bowledBy ,int runs , BallType ballType) {
    //update batting scorecard
    int fours = 0;
    int sixes = 0;
    if(runs == 4) {
        fours += 1;
    } else if (runs == 6) {
        sixes += 1;
    }

    
    playedBy->getBatScorecard()->updateScore(runs , 1 , fours , sixes);
}
};

class BallScoreObserver : public ScoreObserver {
public:
void notify( Player *playedBy,  Player *bowledBy ,int runs , BallType ballType) {
    //update bowling scorecard
    int tot_wide_ball = 0;
    int total_no_ball = 0;
    int tot_wickets = 0;
    if(ballType == WIDEBALL) {
        tot_wide_ball = 1;
    } else if (ballType == NOBALL) {
        total_no_ball = 1;
    } else if (ballType == WICKETBALL) {
        tot_wickets = 1;
    }

    cout << tot_wickets << " " << bowledBy->getName() << endl;
    
    bowledBy->getBallScorecard()->updateScore(1 , runs , tot_wickets , total_no_ball , tot_wide_ball);
}
};

#endif // SCOREOBSERVER_H