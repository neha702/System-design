#ifndef USER_H
#define USER_H
#include <string>
#include "post.h"
#include "comment.h"
using namespace std;

class Post;

class User {
int id;
string name;
int reputation = 0;
vector<Post*>addedPosts;
vector<pair<Post* , bool> >votedPosts;
vector<Comment*>comments;
public:
User(int id , string name) {
    this->id = id;
    this->name = name;
}

void addToVotedPosts(Post* p , bool isUpVoted) {
    votedPosts.push_back(make_pair(p ,isUpVoted));
    cout << "Added to voted post" << endl;
}

vector<pair<Post* , bool> > getVotedPosts() {
    return votedPosts;
}

int getUserId() {
    return id;
}

void addPost(Post* p) {
    addedPosts.push_back(p);
    cout << "Added post to profile!" << endl;
}

int showReputation() {
    cout << "User " << name << " has reputation of " << reputation << endl;
}

void setReputation(int repo) {
    this->reputation = repo;
    cout << "Added reputation of " << repo << endl;
}

void addComment(Comment* comment) {
    comments.push_back(comment);
    cout << "Added comment to profile!" << endl;
}

vector<Post*> getPosts() {
    return addedPosts;
}

string getName() {
    return name;
}
};

#endif // USER_H