#ifndef MATCHTYPE_H
#define MATCHTYPE_H

class MatchType {
public:
virtual int getOvers() = 0;
virtual int getMaxOversPerPlayer() = 0; //max balls that can be played by a baller
};

class ODI : public MatchType {
int getOvers() {
    return 50;
}
int getMaxOversPerPlayer() {
    return 5; // 4 bowlers
}
};

class T20 : public MatchType {
int getOvers() {
    return 20;
}
int getMaxOversPerPlayer() {
    return 5; //4 bowlers
}
};

#endif // MATCHTYPE_H