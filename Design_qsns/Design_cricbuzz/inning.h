#ifndef INNING_H
#define INNING_H
#include "team.h"
#include "over.h"
#include "matchType.h"

class Inning {
vector<Over*> overs;
Team* battingTeam;
Team* ballingTeam;
MatchType* matchType;

public:
Inning(Team* teamA , Team* teamB , MatchType* matchType) {
    this->battingTeam = teamA;
    this->ballingTeam = teamB;
    this->matchType = matchType;
}

void startInning(int runsToChase) {
    int total_overs = matchType->getOvers();
    // cout << "Player: " << battingTeam->getStriker()->getName() << " is batting!" << endl;
   // cout << "Total overs : " << total_overs << endl;
    for(int i = 1  ; i <= total_overs ; i++) {
        cout << "Over " << i << " starts!" << endl;
      
        Over* over = new Over(i ,ballingTeam->getCurrBowler());
        overs.push_back(over);
        //start the over
        cout << "Player: " << ballingTeam->getCurrBowler()->getName() << " is bowling!" << endl;
        bool won = over->startOver(ballingTeam , battingTeam , runsToChase);
        if(won == 1) {
            cout << "Match is won "<< endl;
            break;
        } else if(won == 2) {
            cout << "No more batsman to play" << endl;
            break;
        }

        //swap the striker and nonStriker
        Player* temp = battingTeam->getStriker();
        battingTeam->setStriker(battingTeam->getNonStriker());
        battingTeam->setNonStriker(temp);

        ballingTeam->incOvers(ballingTeam->getCurrBowler());

        if(!ballingTeam->chooseNextBaller(matchType->getMaxOversPerPlayer())) {
            cout << "No more bowlers to ball!" << endl;
            return;
        }
    }
}
};

#endif // INNING_H