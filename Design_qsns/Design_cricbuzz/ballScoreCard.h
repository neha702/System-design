#ifndef BALLSCORECARD_H
#define BALLSCORECARD_H
#include <unordered_map>
#include "player.h"

class BallScoreCard {
int ballsPlayed;
int runsProvided;
int wicketsTaken;
int totalNoBall;
int totalWideBall;
public:
void updateScore(int ballsPlayed , int runsProvided , int wicketsTaken , int totalNoBall , int totalWideBall) {
    this->ballsPlayed = this->ballsPlayed + 1;
    this->runsProvided = this->runsProvided + runsProvided;
    this->wicketsTaken = this->wicketsTaken + wicketsTaken;
    this->totalNoBall = this->totalNoBall + totalNoBall;
    this->totalWideBall = this->totalWideBall + totalWideBall;
}

void printScoreCard() {
    cout << "Balls Played: " << ballsPlayed << endl;
    cout << "Runs Provided: " << runsProvided << endl;
    cout << "Wickets Taken: " << wicketsTaken << endl;
    cout << "Total No Ball: " << totalNoBall << endl;
    cout << "Total Wide Ball: " << totalWideBall << endl;
}
};

#endif // BALLSCORECARD_H