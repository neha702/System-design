#ifndef STACKOVERFLOWSVC_H
#define STACKOVERFLOWSVC_H
#include <mutex>
#include "post.h"
#include "tag.h"
#include "user.h"
#include "stackOverflowSvcManager.h"
using namespace std;

class StackOverflowSvc {
public:
static StackOverflowSvcManager* stackOverflowSvcManager;
static StackOverflowSvc* stackOverflowSvc;
static mutex singletonMtx;

static StackOverflowSvc* getStackOverflowSvc() {
    if(stackOverflowSvc == nullptr) {
        singletonMtx.lock();
        if(stackOverflowSvc == nullptr) {
            stackOverflowSvc = new StackOverflowSvc();
            stackOverflowSvcManager = new StackOverflowSvcManager();
        }
       singletonMtx.unlock();
    }
 return stackOverflowSvc;
}

StackOverflowSvcManager* getStackOverflowSvcManager() {
    return stackOverflowSvcManager;
}

Post* addQuestion(int id , string content , Tag* tag , User* u) {
    Post* qsnPost = new Post(id , true , content , tag ,u);
    if(stackOverflowSvcManager->getUsers().find(u) != stackOverflowSvcManager->getUsers().end()) {
        stackOverflowSvcManager->onboardQsn(tag , qsnPost);
        u->addPost(qsnPost);
        return qsnPost;
    } else {
        cout << "User doesn't exist in db to add post" << endl;
        return nullptr;
    }
}

Post* addAnswer(int id , string content , Post* qsn , User* u) {
    if(qsn == nullptr) {
        cout << "Question post doesn't exist to be answered" << endl;
        return nullptr;
    }
    Post* ansPost = new Post(id , false, content , nullptr ,u);
     if(stackOverflowSvcManager->getUsers().find(u) != stackOverflowSvcManager->getUsers().end()) {
         stackOverflowSvcManager->onboardAns(ansPost , qsn); // add ans to qsnsToAns map
         u->addPost(ansPost);
         return ansPost;
     }else {
        cout << "User doesn't exist in db to add post" << endl;
        return nullptr;
    }
}

void addComment(string commentContent , Post* post , User* u) {
    if(stackOverflowSvcManager->getUsers().find(u) != stackOverflowSvcManager->getUsers().end()) {
         Comment* comment = new Comment(u , commentContent);
         stackOverflowSvcManager->onboardComment(post , comment); // add comment to post
         u->addComment(comment); // add comment to profile
    } else {
        cout << "User doesn't exist in db to add comment to post" << endl;
    }
}

void upVote(Post* post , User* u) {
    //make sure duplicate votes are not added
    if(stackOverflowSvcManager->getUsers().find(u) != stackOverflowSvcManager->getUsers().end() && !post->hasVoted(u)) {
        Vote* vote = new Vote(u , true);
        stackOverflowSvcManager->updateVoteInPost(post , vote); // update votes in post
        u->addToVotedPosts(post ,true);
    }else {
        cout << "User doesn't exist in db to add vote to post or already upvoted " << endl;
    }
}

void downVote(Post* post , User* u) {
if(stackOverflowSvcManager->getUsers().find(u) != stackOverflowSvcManager->getUsers().end() && !post->hasVoted(u)) {
        Vote* vote = new Vote(u , false);
        stackOverflowSvcManager->updateVoteInPost(post , vote); // update votes in post
        u->addToVotedPosts(post ,false);
    //in future if we need to track votes in profile   
    }else {
        cout << "User doesn't exist in db to add vote to post or already downvoted " << endl;
    }
}

};
StackOverflowSvc* StackOverflowSvc::stackOverflowSvc = nullptr;
StackOverflowSvcManager* StackOverflowSvc::stackOverflowSvcManager = nullptr;
mutex StackOverflowSvc::singletonMtx;

#endif // STACKOVERFLOWSVC_H