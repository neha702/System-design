#ifndef REPUTATIONSTRATEGY_H
#define REPUTATIONSTRATEGY_H
#include "post.h"

class ReputationStrategy {
public:
virtual void calculateReputation(User* u) = 0;
};

//Based on upvotes in post , repo calculated
class UpvoteStrategy : public ReputationStrategy {
public:
void calculateReputation(User* u) {
    int repo = 0;
    vector<pair<Post*, bool> >votedPosts = u->getVotedPosts();
    for(auto it : votedPosts) {
        if(it.second == 1) {
            repo += 10;
        }
    }
    u->setReputation(repo);
}
};

//Based on downvotes in post , repo calculated
class DownvoteStrategy : public ReputationStrategy {
public:
void calculateReputation(User* u) {
    int repo = 0;
    vector<pair<Post*, bool> >votedPosts = u->getVotedPosts();
    for(auto it : votedPosts) {
        if(it.second == 1) {
            repo += -5;
        }
    }
    u->setReputation(repo);
}
};

#endif // REPUTATIONSTRATEGY_H