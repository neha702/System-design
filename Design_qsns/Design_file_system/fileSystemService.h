#ifndef FILESYSTEMSERVICE_H
#define FILESYSTEMSERVICE_H
#include <iostream>
#include "fileSystemNode.h"
#include "directory.h"
#include "file.h"
#include "nodeFactory.h"
#include <vector>
#include <sstream>
using namespace std;

class FileSystemService {
    FileSystemNode* getNode(string path) {
        FileSystemNode* currNode = root;

        if(!isValidPath(path)) return nullptr;

        vector<string> tokens = split(path , '/');

        for(int i = 1 ; i < tokens.size() ; i++) {
            if(!currNode->hasChild(tokens[i])) {
                return nullptr;
            } else {
                currNode = currNode->getChildNode(tokens[i]);
            }
        }
        return currNode;
    }
    vector<string> split(string path , char delimiter) {
        stringstream ss(path);
        string token;
        vector<string>tokens;

        while(getline(ss , token , delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    bool startsWith(string s , string prefix) {
        return (s.size() >= prefix.size() && !s.compare(0 , prefix.size() , prefix)); // if strings equal then value is 0
    }

    bool isValidPath(string path) {
        return path.size() > 0 && startsWith(path , "/");
    }

    string getParentPath(string path) {
        //find last slash and path from 0 ind to last_slash - 1 would be the parent
        int lastInd = path.rfind('/');
        return path.substr(0 , lastInd);
    }
public:
    static FileSystemService* fileSystemService;
    static mutex mtx;
    static FileSystemNode* root;
    static NodeFactory* nodeFactory;

    static FileSystemService* getInstance() {
        if(fileSystemService ==  nullptr) {
            mtx.lock();
            if(fileSystemService == nullptr) {
                fileSystemService = new FileSystemService();
                cout << "File system service created" << endl;
                root = new Directory("/");
                nodeFactory = new NodeFactory();
            }
            mtx.unlock();
        }
        return fileSystemService;   
    }

    bool createPath(string path) {
        if(!isValidPath(path)) {
            cout << "Can't create path since its not a valid path" << endl;
            return false; // if not starting with "/"
        }

        vector<string> tokens = split(path , '/');
        
        FileSystemNode* currNode = root;

        for(int i = 1 ; i <  tokens.size() - 1 ; i++) {
            if(tokens[i].size() == 0) continue; // if empty part then skip
            if(!currNode->hasChild(tokens[i])) { // if no child name with this component , create a child with this component name
                FileSystemNode* newNode = new Directory(tokens[i]);
                currNode->addChild(tokens[i] , newNode);
            }
            FileSystemNode* nextNode = currNode->getChildNode(tokens[i]); // if child exist with this component then move to next node
            if(nextNode->isFile()) return false;
            currNode = nextNode;
        }
        //extract last component
        string lastComponent =  tokens[tokens.size() - 1];
        if(lastComponent.size() == 0) return false;

        if(currNode->hasChild(lastComponent)) return false; // if last compoennt already exist

        FileSystemNode* lastNode = nodeFactory->createNode(lastComponent); // create last node based on presence of . , if . present then its a file otherwise a directory
        currNode->addChild(lastComponent , lastNode);
        cout << "Path created!" << endl;
        return true;
    }

    bool deletePath(string path) {
        if(!isValidPath(path)) return false;

        // if its a root node can't delete it
        if(path.size() == 1 && path[0] == '/') {
            return false;
        }

        // if not a root node , find the parent node and then traverse through their children if found our path delete it
        string parentPath = getParentPath(path);
        FileSystemNode* parentNode = getNode(parentPath);

        if(parentNode == nullptr || parentNode->isFile()) return false;

        //find last component string that needs to be deleted
        string lastComponent = path.substr(path.rfind('/') + 1);

         cout << "Path deleted !" << endl;

        return parentNode->removeChild(lastComponent); // remove the last component
    }

    void display() {
        root->display(0); // display the tree with this depth with root node as root
    }

    string getFileContent(string path) {
        FileSystemNode* node = getNode(path);
        
        if(node == nullptr || !node->isFile()) {
            cout << "File node not found!" << endl;
            return NULL;
        }

        File* fileNode = (File*)(node);
        cout << "Displaying file content: " << endl;
        return fileNode->getFileContent();
    }

    bool setFileContent(string path , string content) {
        FileSystemNode* node = getNode(path);
        
        if(node == nullptr || !node->isFile()) {
            cout << "File node not found!" << endl;
            return false;
        }

        cout << "File content is set!" << endl;

        File* fileNode = (File*)(node);
        fileNode->setFileContent(content);
        return true;
    }


    
};
FileSystemService* FileSystemService::fileSystemService = nullptr;
mutex FileSystemService::mtx;
FileSystemNode* FileSystemService::root = nullptr;
NodeFactory* FileSystemService::nodeFactory = nullptr;

#endif // FILESYSTEMSERVICE_H