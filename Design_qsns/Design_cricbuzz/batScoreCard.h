#ifndef BATSCORECARD_H
#define BATSCORECARD_H

class BatScoreCard
{
    int runs;
    int ballsPlayed;
    int fours;
    int sixes;
    double strikeRate;

public:
    void updateScore(int runs, int ballsPlayed, int fours, int sixes)
    {
        this->runs = this->runs + runs;
        this->ballsPlayed = this->ballsPlayed + ballsPlayed;
        this->fours = this->fours + fours;
        this->sixes = this->sixes + sixes;
        this->strikeRate = ((double)(this->runs) / (double)(this->ballsPlayed)) * 100;
    }

    void printScoreCard()
    {
        cout << "Runs: " << runs << endl;
        cout << "Balls Played: " << ballsPlayed << endl;
        cout << "Fours: " << fours << endl;
        cout << "Sixes: " << sixes << endl;
        cout << "Strike Rate: " << strikeRate << endl;
    }
};

#endif // BATSCORECARD_H