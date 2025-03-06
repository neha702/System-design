#ifndef POST_H
#define POST_H
#include "vote.h"
#include "comment.h"
#include "tag.h"
#include "stackOverflowSvc.h"
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Post {
int id;
bool isQsn;
string content;
Tag* tag;
User* createdBy;
set<Vote*>votes;
int upvotes;
int downvotes;
vector<Comment*>comments;
mutex voteMtx;
public:
Post(int id , bool isQsn , string content , Tag* tag , User* createdBy) {
    this->id = id;
    this->isQsn = isQsn;
    this->content = content;
    this->tag = tag;
    this->createdBy = createdBy;
    upvotes = 0;
    downvotes = 0;
}

int getId() {
    return id;
}

Tag* getTag(Post* p) {
    return p->tag;
}

void addComment(Comment* comment) {
    comments.push_back(comment);
}

void addVote(Vote* v) {
    voteMtx.lock();
    votes.insert(v);
    upvotes++;
    cout << "Added upvote for post!" << endl;
    voteMtx.unlock();
}

void downVote(Vote* v) {
    voteMtx.lock();
    votes.insert(v);
    downvotes++;
    cout << "Added downvote for post!" << endl;
    voteMtx.unlock();
}

string getUser() {
    return createdBy->getName();
}

bool hasVoted(User* u) {
    for(auto it : votes) {
        if(it->getVotedBy() == u) return true;
    }
    return false;
}

void showVotes() {
    cout << "Up votes : " << upvotes << " ---- ";
    cout << "Down votes : " << downvotes << endl;
}

};

#endif // POST_H