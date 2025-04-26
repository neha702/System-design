#ifndef NODEFACTORY_H
#define NODEFACTORY_H
#include <iostream>
#include "directory.h"
#include "file.h"
using namespace std;

class NodeFactory {
     bool ifContains(string s , char value) {
        for(char a : s) {
            if(a == value) return true;
        }
        return false;
    }
public:
    FileSystemNode* createNode(string lastComponent) {
        FileSystemNode* component = nullptr;
        //check if its a file or directory (if it contains a .)
            if(ifContains(lastComponent , '.')) {
                component = new File(lastComponent);
            } else {
                component = new Directory(lastComponent);
            }
        return  component;
    }
};

#endif // NODEFACTORY_H