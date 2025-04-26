#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <iostream>
#include "fileSystemNode.h"
using namespace std;

class Directory : public FileSystemNode{
public:
    Directory(string path) : FileSystemNode(path , 1000) {}

    bool isFile() {
        return false;
    }

    void display(int depth) {
        for(auto it : this->getChildrenNodes()) {
            if(!it->isFile()) {
                cout << "Folder: " << it->getName() << endl;
            } 
            it->display(depth + 1);
        }
    }

};

#endif // DIRECTORY_H