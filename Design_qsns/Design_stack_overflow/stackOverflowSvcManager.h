 #ifndef STACKOVERFLOWSVCMANAGER_H
 #define STACKOVERFLOWSVCMANAGER_H
 #include <unordered_map>
 #include "tag.h"
 #include "post.h"
 #include "reputationStrategy.h"
 #include <set>
 
class StackOverflowSvcManager {
unordered_map<string, vector<Post* > >qsns;
unordered_map<int, vector<Post*> >answersByQsn;
ReputationStrategy* reputationStrategy;
static set<User*> users;
public:
StackOverflowSvcManager() {
    this->reputationStrategy = new UpvoteStrategy();
}

vector<Post*> getPostsByTag(Tag* tag) {
    return qsns[tag->getTagName()];
}

vector<Post*> getAnswersByQsnPost(Post* qsn) {
    return answersByQsn[qsn->getId()];
}

void setReputationStrategy(ReputationStrategy* strategy) {
    this->reputationStrategy = strategy;
}

set<User*> getUsers() {
    return users;
}

void onboardQsn(Tag* tag , Post* qsnPost) {
    qsns[tag->getTagName()].push_back(qsnPost);
    cout << "Added question post to system!" << endl;
}

void onboardAns(Post* ansPost , Post* qsnPost) {
   answersByQsn[qsnPost->getId()].push_back(ansPost);
   cout << "Added answer post to system!" << endl;
}

void onboardComment(Post* post , Comment* comment) {
   post->addComment(comment);
   cout << "Added comment to qsn post!" << endl;
}

void updateVoteInPost(Post* p , Vote* vote) {
    if(vote->isUpVoted()) {
        p->addVote(vote);
    } else {
        p->downVote(vote);
    }
}

void addReputation(User* u) {
    if(users.find(u) == users.end()) {
        cout << "user not found" << endl;
        return;
    }
    
   reputationStrategy->calculateReputation(u);
}

void addUser(User* u) {
    users.insert(u);
    cout << "User " << u->getName() << " added!" << endl;
}

vector<Post*> getPostsByUser(User* u) {
    return u->getPosts();
}

};
set<User*> StackOverflowSvcManager::users;
 
 #endif // STACKOVERFLOWSVCMANAGER_H