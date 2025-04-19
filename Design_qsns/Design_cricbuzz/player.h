#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"
#include "enums.h"
#include "batScoreCard.h"
#include "ballScoreCard.h"
#include <iostream>
using namespace std;

class Player
{
    Person *p;
    PlayerType playerType;
    BatScoreCard *batScoreCard;
    BallScoreCard *ballScoreCard;

public:
    Player(Person *p, PlayerType playerType)
    {
        this->p = p;
        this->playerType = playerType;
        this->batScoreCard = new BatScoreCard();
        this->ballScoreCard = new BallScoreCard();
    }

    BatScoreCard *getBatScorecard()
    {
        return batScoreCard;
    }

    BallScoreCard *getBallScorecard()
    {
        return ballScoreCard;
    }

    string getName()
    {
        return p->getName();
    }

    PlayerType getPlayerType()
    {
        return playerType;
    }

    void printBatScoreCard() {
        cout << "Player: " << getName() << endl;
        batScoreCard->printScoreCard();
    } 

    void printBallScoreCard() {
        cout << "Player: " << getName() << endl;
        ballScoreCard->printScoreCard();
    } 
};

#endif // PLAYER_H