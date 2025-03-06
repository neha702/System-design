#include "../../bitsStd.h"
#include "stackOverflowSvc.h"
#include "stackOverflowSvcManager.h"
#include "user.h"
#include "tag.h"
using namespace std;
/*
Database schema
1. Identify entities
    a. Post
    b. User
    c. Vote
    d. Tag
    e. Comment
    f. Reputation

2. Determine relationships between entities
    a. Each post can have many votes , many tags , many comments , one user , many answer posts
    
3. Define tables with constraints and indexing (table is for one to many relationships)
    a. User => P.K - user_id , fileds - user_id , name , reputation
    b. post => P.K - post_id , fields - post_id  , user_id (F.K to users) , is_qsn , content , parent_post_id (F.K to other ans posts) - null for qsn , post_id for qsn for answers
    c. tags => P.K - tag_id , fields - tag_id , tag_name
    d. comment => P.K - comment_id , fields - user_id (F.K to users), post_id (F.K to posts), content
    e. vote => P.K - vote_id , fields - user_id(F.K to users) , post_id (F.K to posts), isUpVoted, to prevent duplicate voting need unique com
    bination of user_id , post_id
    f. reputation => this table not needed

    Concurrency => We need to handle concurrent access  for service by making it singleton and for voting also concurrency needs to be handled , so for each
    post should have one mutx so for each post at a time one user can change vote

    Design patterns => strategy for reputation, Singleton for service and manager

    accept answer , remove votes functionality can be added
*/

int main() {
    StackOverflowSvc* stackOverflowSvc = StackOverflowSvc::getStackOverflowSvc();
    StackOverflowSvcManager* stackOverflowSvcManager = stackOverflowSvc->getStackOverflowSvcManager();

    User* u1 = new User(1 , "Rohan");
    stackOverflowSvcManager->addUser(u1);
    User* u2 = new User(2 , "Neha");
    stackOverflowSvcManager->addUser(u2);
    User* u3 = new User(3 , "Pratik");
    stackOverflowSvcManager->addUser(u3);

    Tag* scTag = new ScienceFictionTag("Only science qsns");
    Post* qsn1 = stackOverflowSvc->addQuestion(1 , "What is corrosion?" , scTag ,u1);
    Post* qsn2 = stackOverflowSvc->addQuestion(2 , "How to excel in chemistry?" , scTag ,u3);
    Post* ans1 = stackOverflowSvc->addAnswer(3 , "This is rusting" , qsn2 ,u2);
    stackOverflowSvc->addComment("Thanks" , qsn1 ,u1);
    stackOverflowSvc->upVote(qsn1 , u3);
    stackOverflowSvc->upVote(qsn2 , u3);
    stackOverflowSvc->downVote(qsn2 , u3);

    qsn1->showVotes();

    stackOverflowSvcManager->addReputation(u3);

    vector<Post*> posts1 = stackOverflowSvcManager->getPostsByTag(scTag);
    if(posts1.size() == 0) cout << "No posts found" << endl;
    for(auto it : posts1) {
        cout << "Post by " << it->getUser() << endl;
    }

    vector<Post*> posts2 = stackOverflowSvcManager->getPostsByUser(u2);
    if(posts2.size() == 0) cout << "No posts found" << endl;
    for(auto it : posts2) {
        cout << "Post by " << it->getUser() << " has votes " ;
        it->showVotes();
        cout << endl;
    }

    
}