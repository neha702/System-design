#ifndef MATCH_H
#define MATCH_H
#include <string>
#include "team.h"
#include "inning.h"
#include "matchType.h"
#include <iostream>
using namespace std;

class Match
{
    vector<Inning *> innings;
    MatchType *matchType;
    string venue;
    long matchDate;
    Team *team1;
    Team *team2;
    Team *tossWinner;

public:
    Match(Team *team1, Team *team2, string venue, long matchDate, MatchType *matchType)
    {
        this->team1 = team1;
        this->team2 = team2;
        this->venue = venue;
        this->matchDate = matchDate;
        this->matchType = matchType;
    }

    void setTossWinner(Team *tossWinner)
    {
        this->tossWinner = tossWinner;
    }

    double getRandom()
    {
        return (double)rand() / (RAND_MAX + 1.0);
    }

    Team *getTossWinner(Team *teamA, Team *teamB)
    {
        if (getRandom() > 0.5)
        {
            return teamA;
        }
        else
        {
            return teamB;
        }
    }

    void startMatch()
    {
        // do a toss
        setTossWinner(getTossWinner(team1, team2));

        // start innings
        for (int i = 0; i < 2; i++)
        {
            Team *battingTeam = nullptr;
            Team *bowlingTeam = nullptr;
            if (i == 0)
            {
                cout << endl << endl;
                // start first inning
                battingTeam = tossWinner;
                bowlingTeam = tossWinner->getTeamName() == team1->getTeamName() ? team2 : team1;
                Inning *firstInning = new Inning(battingTeam, bowlingTeam, matchType);
                innings.push_back(firstInning);
                cout << "First inning starts!" << endl;
                if(!battingTeam->chooseInitialBatsmen()) {
                    cout << "No batsmen to start!" << endl;
                    return;
                }
                
                cout << "Players " << battingTeam->getStriker()->getName() << " and " << battingTeam->getNonStriker()->getName() << "  are batting!" << endl; 
                cout << "Player " << bowlingTeam->getCurrBowler()->getName() << " is bowling!" << endl;

                
                firstInning->startInning(-1); // in first inning we dont have to chase any runs
            }
            else if (i == 1)
            {
                // start second inning
                bowlingTeam = tossWinner;
                battingTeam = tossWinner->getTeamName() == team1->getTeamName() ? team2 : team1;
                Inning *secondInning = new Inning(battingTeam, bowlingTeam, matchType);
                innings.push_back(new Inning(battingTeam, bowlingTeam, matchType));
                cout << "Second inning starts!" << endl;
                if(!battingTeam->chooseInitialBatsmen()) {
                    cout << "No batsmen to start!" << endl;
                    return;
                }
               
                cout << "Players " << battingTeam->getStriker()->getName() << " and " << battingTeam->getNonStriker()->getName() << "  are batting!" << endl; 
                cout << "Player " << bowlingTeam->getCurrBowler()->getName() << " is bowling!" << endl;

                secondInning->startInning(bowlingTeam->getTotalRunsScored());
                if (battingTeam->getTotalRunsScored() > bowlingTeam->getTotalRunsScored())
                {
                    cout << "Winner is : " << battingTeam->getTeamName() << endl;
                }
                else if (battingTeam->getTotalRunsScored() > bowlingTeam->getTotalRunsScored())
                {
                    cout << "Its a tie" << endl;
                }
                else
                {
                    cout << "Winner is : " << bowlingTeam->getTeamName() << endl;
                }
            }

            cout << endl << endl;

            cout << "Print batting score card for inning " << i + 1 << endl;
            battingTeam->printBattingScoreCard();
            cout << endl;

            cout << "Print bowling score card for inning " << i + 1 << endl;
            bowlingTeam->printBowlingScoreCard();
        }


    }
};

#endif // MATCH_H