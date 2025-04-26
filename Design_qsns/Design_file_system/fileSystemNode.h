#ifndef FILESYSTEMNODE_H
#define FILESYSTEMNODE_H
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class FileSystemNode {
    string name;
    unordered_map<string , FileSystemNode*> childrenMap;
    long createdAt;
public:
    FileSystemNode(string name , long createdAt) {
        this->name =  name;
        this->createdAt = createdAt;
    }

    void addChild(string path , FileSystemNode* fileSystemNode) {
        childrenMap[path] = fileSystemNode;
    }   

    bool removeChild(string path) {
        if(childrenMap.find(path) == childrenMap.end()) return false;
        childrenMap.erase(path);
        return true;
    } 

    FileSystemNode* getChildNode(string path) {
        return childrenMap[path];
    }

    virtual bool isFile() = 0;

    vector<FileSystemNode*> getChildrenNodes() {
        vector<FileSystemNode*> childrenNodes;

        for(auto it : childrenMap) {
            childrenNodes.push_back(it.second);
        }

        return childrenNodes;
    }

     bool hasChild(string path) {
        return (childrenMap.find(path) != childrenMap.end());
    }

    string getName() {
        return name;
    }

    long getCreatedAt() {
        return createdAt;
    }

    virtual void display(int depth) = 0;
};

#endif // FILESYSTEMNODE_H