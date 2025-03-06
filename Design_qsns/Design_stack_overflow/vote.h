#ifndef VOTE_H
#define VOTE_H
#include "user.h"

class Vote {
User* votedBy;
bool isUpVotedFlag = false;
public:
Vote(User* votedBy , bool isUpvoted) {
    this->votedBy = votedBy;
    this->isUpVotedFlag = isUpvoted;
}

bool isUpVoted() {
    return isUpVotedFlag;
}

User* getVotedBy() {
    return votedBy;
}
};

#endif // VOTE_H