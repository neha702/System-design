#include "../../bitsStd.h"
#include "match.h"
using namespace std;

int main() {
    Team* team1 = new Team("India");
    Person* person1 = new Person("Kohli" , 34);
    Person* person2 = new Person("Dhoni" , 38);
    Person* person3 = new Person("Raina" , 32);
    Person* person4 = new Person("Bumrah" , 31);
    Person* person5 = new Person("Siraj" , 30);
    Player* p1 = new Player(person1 , BATSMAN);
    Player* p2 = new Player(person2 , BATSMAN);
    Player* p3 = new Player(person3 , BATSMAN);
    Player* p4 = new Player(person4 , BOWLER);
    Player* p5 = new Player(person5 , BOWLER);
    team1->addPlayer(p1);
    team1->addPlayer(p2);
    team1->addPlayer(p3);
    team1->addPlayer(p4);
    team1->addPlayer(p5);

    Team* team2 = new Team("Australia");
    Person* person6 = new Person("Ponting" , 34);
    Person* person7 = new Person("Head" , 38);
    Person* person8 = new Person("Warner" , 32);
    Person* person9 = new Person("Bretlee" , 31);
    Person* person10 = new Person("Cummins" , 30);
    Player* p6 = new Player(person6 , BATSMAN);
    Player* p7 = new Player(person7 , BATSMAN);
    Player* p8 = new Player(person8 , BATSMAN);
    Player* p9 = new Player(person9 , BOWLER);
    Player* p10 = new Player(person10 , BOWLER);
    team2->addPlayer(p6);
    team2->addPlayer(p7);
    team2->addPlayer(p8);
    team2->addPlayer(p9);
    team2->addPlayer(p10);
    
    MatchType* matchType1 = new T20();
    Match* match = new Match(team1, team2 , "Wankhede Stadium" , 12345 , matchType1);
    match->startMatch();
}